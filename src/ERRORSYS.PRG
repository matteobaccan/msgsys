/***
*
*       Errorsys.prg
*
*  Standard Clipper error handler
*
*  Copyright (c) 1990-1993, Computer Associates International, Inc.
*  All rights reserved.
*
*  Compile:  /m /n /w
*
*/

#include "error.ch"


// put messages to STDERR
#command ? <list,...>   =>  ?? Chr(13) + Chr(10) ; ?? <list>
#command ?? <list,...>  =>  OutErr(<list>)


// used below
#define NTRIM(n)                ( LTrim(Str(n)) )



/***
*       ErrorSys()
*
*       Note:  automatically executes at startup
*/

proc ErrorSys()
        ErrorBlock( {|e| DefError(e)} )
return


#define TEXT_QUIT       1
#define TEXT_BREAK      2
#define TEXT_RETRY      3
#define TEXT_DEFAULT    4
#define TEXT_DOSERROR   5
#define TEXT_CALLSTACK  6
#define TEXT_ERROR      7
#define TEXT_WARNING    8

/***
*       DefError()
*/
STATIC Function DefError(e)
 Local i, cMessage, cDOSError, aOptions, nChoice
 Local aText := {"Kil‚p", "Kihagy", "éjra", "Alap‚rtelmez‚s",;
                "DOS Hiba ","H¡v sok sorrendje:","Hiba ", "Jelz‚s "}

   // by default, division by zero yields zero
   if ( e:genCode == EG_ZERODIV )
      return (0)
   end


   // for network open error, set NETERR() and subsystem default
   if ( e:genCode == EG_OPEN .and. e:osCode == 32 .and. e:canDefault )

      NetErr(.t.)
      return (.f.)                                                                    // NOTE

   end


   // for lock error during APPEND BLANK, set NETERR() and subsystem default
   if ( e:genCode == EG_APPENDLOCK .and. e:canDefault )

      NetErr(.t.)
      return (.f.)                                                                    // NOTE

   end



   // build error message
   cMessage := ErrorMessage(e)


   // build options array
   // aOptions := {aText[ TEXT_BREAK], aText[ TEXT_QUIT]}
   aOptions := {aText[ TEXT_QUIT]}

   if (e:canRetry)
      AAdd(aOptions, aText[ TEXT_RETRY])
   end

   if (e:canDefault)
      AAdd(aOptions, aText[ TEXT_DEFAULT])
   end


   // put up alert box
   nChoice := 0
   while ( nChoice == 0 )

           if ( Empty(e:osCode) )
              cDOSError := ""
            Else
              cDOSError := ";("+ aText[ TEXT_DOSERROR] + NTRIM(e:osCode) + ")"
           end

           nChoice := Alert( cMessage + cDOSError,;
                             aOptions )

           if ( nChoice == NIL )
                   exit
           end

   end


   if ( !Empty(nChoice) )

           // do as instructed
           if ( aOptions[nChoice] == "Kihagy" )
              Break(e)

           elseif ( aOptions[nChoice] == "éjra" )
              return (.t.)

           elseif ( aOptions[nChoice] == "Alap‚rtelmez‚s" )
              return (.f.)

           end

   end


   // display message and traceback
   if ( !Empty(e:osCode) )
           cMessage += " "+SubStr( cDOSError,2)
   end

   ? cMessage
   i := 2
   ? "H¡v sok sorrendje:"
   while ( !Empty(ProcName(i)) )
           ? "  "+Trim(ProcName(i)) + "(" + NTRIM(ProcLine(i)) + ")  "

           i++
   end


   // give up
   ErrorLevel(1)
   QUIT

return (.f.)




/***
*       ErrorMessage()
*/
static func ErrorMessage(e)
local cMessage


        // start error message
        cMessage := if( e:severity > ES_WARNING, "Hiba ", "Jelz‚s " )


        // add subsystem name if available
        if ( ValType(e:subsystem) == "C" )
                cMessage += e:subsystem()
        else
                cMessage += "???"
        end


        // add subsystem's error code if available
        if ( ValType(e:subCode) == "N" )
                cMessage += ("/" + NTRIM(e:subCode))
        else
                cMessage += "/???"
        end


        // add error description if available
        if ( ValType(e:description) == "C" )
                cMessage += ("  " + e:description)
        end


        // add either filename or operation
        if ( !Empty(e:filename) )
                cMessage += (": " + e:filename)

        elseif ( !Empty(e:operation) )
                cMessage += (": " + e:operation)

        end


return (cMessage)


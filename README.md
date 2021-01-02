# MsgSys
Multi-language replacement of Clipper 5.x internal error message files

Enclosed are the source files for msgita.obj and the source for a standard message system for the International version Clipper.

I have modified it and recompiled it with a different switch. This will allow a Clipper application to have an additional 1542 bytes of DGROUP space and the ability for all Clipper programmers to create a new language system.

To use it, all you have to do is link the correct object file into your application.  If you create a new language source and obj, please feel free to send me the new source so I can enclose it with future versions of this package.

If you find an error in the source, send me the corrected source or details of the error you detected so I can update this package.

I have tested it with Clipper 5.2e International version, but I think this package will also work with Clipper 5.3b International Version. You must only try to link it to know if it does.

# Why use this package

1) Standard package uses 1542 byte of DGROUP, this package uses 0
2) Standard package has no source available
3) If your language is not supported, you can easily create your version.
4) With this source you can create a multilanguage system
5) Use the new .obj it's very simple
6) ...

# Get Sys Modification 

I have produced the 1st version of this package only for a joke, but I have discovered that many people in the Clipper community downloaded it and wrote versions to support other languages.  For example Sylvain Larche, 72537,2561 (72537.2561@compuserve.com) produced the French version of MSGSYS. Sylvain also discovered a little problem with logical value in standard GETSYS. If you change the standard Y/N string ( NATIONMSG(12) ) for example with O/N the logical value displays the right setting, but will accept only Y and N characters. To solve this problem, I have modified the standard GETSYS to correct the problem in the :Insert and :OverStrike methods of the GET object by adding the following lines:

(Also, see the short example which follows.)

<pre>
       //--------------------------------------------------------
       // Little modification to Clipper Kernel Code
       //--------------------------------------------------------
       IF oGet:TYPE()=="L"
          DO CASE
             CASE UPPER(cKey) == UPPER(SUBSTR(NATIONMSG(12),1,1))
                  cKey := "Y"
             CASE UPPER(cKey) == UPPER(SUBSTR(NATIONMSG(12),3,1))
                  cKey := "N"
          ENDCASE
       ENDIF
       //--------------------------------------------------------

       IF ( SET( _SET_INSERT ) )
          oGet:insert( cKey )
       ELSE
          oGet:overstrike( cKey )
       ENDIF
</pre>

# C Source : Compiler Switch 

It's very easy to decrease the DGROUP usage in the Clipper application by adding a switch to the command line when compiling C code.

The switch for MSC 6.0 is this : /Gt0

This switch allows the compiler to put ALL THE DATA OF DGROUP in a FAR segment. This decreases the DGROUP usage and increases the size of DGROUP for STATIC var, recursive routines and for 3rd party libraries.

This is the command line that I have used to compile the enclosed source files

cl /c /AL /FPa /G2s /Zl /Oaltie /Gh /W4 /Gt0

NOTE : If all of Clipper was compiled with these switches, the DGROUP usage would  be very near to 0 8->>>>>>>

# Send To Me 

If you produce a new language or a new version of MSGSYS, feel free to send to me this upgrade, to improve this little package.

Thanks to all the beta testers and to all the people that use this source and for all the compliments.

# If you are ...

If you are English and wish to correct this doc ... please feel free to send the new one to me !! 8->>> So I can substitute it in the new version.

Thanks to

* White Wolf                  - Hungarian version
* Vincent DUFFAUT             - French version
* Larry Bauder                - Revision
* Kai Froeb                   - German version
* Pablo R. Montenegro C.      - Spanish version
* Luiz Rafael Culik           - BRAZILIAN PORTUGUESE version
* Ignacio Ortiz de Zuñiga     - Another Spanish version

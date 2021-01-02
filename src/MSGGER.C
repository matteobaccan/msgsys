/******************************************************************************
Project     : Clipper source
Description : Clipper National Message Source
Programmer  : Baccan Matteo
Home Page   : http://matteo.isanet.it
              http://www.dbsee.com
Email       : baccan@isanet.it
Translation : Kai Froeb (Kai_Froeb@Compuserve.com)
******************************************************************************/

#include <extend.api>

// Current language
char *_natmsgver(){
   return "GERMAN";
}

// Message Version
CLIPPER _NATMSGVER(){
   _retc("NATMSGS v1.4 x16 04/June/97");
}

// Date picture formatter
CLIPPER _DDATEFMT(){
   _retc("DD.MM.YYYY");
}

// Get the number of the day and return the day String
char *_day_name( int nDay ){
   char *pRet="";

   switch( nDay ){
      case  1: pRet = "Sonntag";      break;
      case  2: pRet = "Montag";      break;
      case  3: pRet = "Dienstag";     break;
      case  4: pRet = "Mittwoch";   break;
      case  5: pRet = "Donnerstag";    break;
      case  6: pRet = "Freitag";      break;
      case  7: pRet = "Samstag";    break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Januar";     break;
      case  2: pRet = "Februar";    break;
      case  3: pRet = "MÑrz";       break;
      case  4: pRet = "April";       break;
      case  5: pRet = "Mai";         break;
      case  6: pRet = "Juni";        break;
      case  7: pRet = "Juli";        break;
      case  8: pRet = "August";      break;
      case  9: pRet = "September";   break;
      case 10: pRet = "Oktober";     break;
      case 11: pRet = "November";    break;
      case 12: pRet = "Dezember";    break;
   }

   return pRet;
}

// String used by Yes / No question
char *_ynstr(){
   return "J/N";
}

// Check if a key is a negative key (Negative is the 3rd character of _ynstr)
CLIPPER ISNEGATIVE(){
   int nRet=0;
   char *pYN=_ynstr();

   if( _parinfo(1)==CHARACTER )
       nRet = (_parc(1)[0]|32)==(pYN[2]|32);

   _retl(nRet);
}

// Check if a key is a confirm key (Confirm is the 1st character of _ynstr)
CLIPPER ISAFFIRM(){
   int nRet=0;
   char *pYN=_ynstr();

   if( _parinfo(1)==CHARACTER )
       nRet = (_parc(1)[0]|32)==(pYN[0]|32);

   _retl(nRet);
}

// Messages translated in the supported language
CLIPPER NATIONMSG(){
   char *pRet="";

   if( _parinfo(1)==NUMERIC ){
      switch (_parni(1)){
         case  1: pRet="Tabellen          # SÑtze      énderungsdatum Grî·e"; break;
         case  2: pRet="Wollen Sie mehr Beispiele?";  break;
         case  3: pRet="SeitenNr.";                   break;
         case  4: pRet="** Subtotal **";              break;
         case  5: pRet="* Subsubtotal *";             break;
         case  6: pRet="*** Total ***";               break;
         case  7: pRet="Einf";                        break;
         case  8: pRet="    ";                        break;
         case  9: pRet="UngÅltiges Datum";            break;
         case 10: pRet="Bereich: ";                   break;
         case 11: pRet=" - ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="UngÅltiges Argument";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Argument error";                 break;
      case 0x0002: pRet="Bound error";                    break;
      case 0x0003: pRet="String overflow";                break;
      case 0x0004: pRet="Numeric overflow";               break;
      case 0x0005: pRet="Zero divisor";                   break;
      case 0x0006: pRet="Numeric error";                  break;
      case 0x0007: pRet="Syntax error";                   break;
      case 0x0008: pRet="Operation too complex";          break;
      case 0x000b: pRet="Memory low";                     break;
      case 0x000c: pRet="Undefined function";             break;
      case 0x000d: pRet="No exported method";             break;
      case 0x000e: pRet="Variable does not exist";        break;
      case 0x000f: pRet="Alias does not exist";           break;
      case 0x0010: pRet="No exported variable";           break;
      case 0x0011: pRet="Illegal characters in alias";    break;
      case 0x0012: pRet="Alias already in use";           break;
      case 0x0014: pRet="Create error";                   break;
      case 0x0015: pRet="Open error";                     break;
      case 0x0016: pRet="Close error";                    break;
      case 0x0017: pRet="Read error";                     break;
      case 0x0018: pRet="Write error";                    break;
      case 0x0019: pRet="Print error";                    break;
      case 0x001E: pRet="Operation not supported";        break;
      case 0x001F: pRet="Limit exceeded";                 break;
      case 0x0020: pRet="Corruption detected";            break;
      case 0x0021: pRet="Data type error";                break;
      case 0x0022: pRet="Data width error";               break;
      case 0x0023: pRet="Workarea not in use";            break;
      case 0x0024: pRet="Workarea not indexed";           break;
      case 0x0025: pRet="Exclusive required";             break;
      case 0x0026: pRet="Lock required";                  break;
      case 0x0027: pRet="Write not allowed";              break;
      case 0x0028: pRet="Append lock failed";             break;
      case 0x0029: pRet="Lock Failure";                   break;
      case 0x002D: pRet="Lock Error";                     break;
      case 0x002E: pRet="Lock Timeout";                   break;
      case 0x019F: pRet="Cannot open overlay file";       break;
      case 0x01A0: pRet="Read error on overlay file";     break;
      case 0x014B: pRet="String/array memory overflow";   break;
      case 0x0154: pRet="Too many Extend locks";          break;
      case 0x028A: pRet="Processor stack fault";          break;
      case 0x029B: pRet="Eval stack fault";               break;
      case 0x14B4: pRet="Not enough memory";              break;
      case 0x14B6: pRet="Conventional memory exhausted";  break;
      case 0x14BF: pRet="Cannot create VM swap file";     break;
      case 0x14C0: pRet="VM swap file overallocated";     break;
      case 0x14C1: pRet="Out of space for VM swap file";  break;
      case 0x270C: pRet="Cancelled";                      break;
      case 0x270D: pRet="Error recovery failure";         break;
      case 0x270E: pRet="Unrecoverable error";            break;
      case 0x270F: pRet="Internal error";                 break;
   }

   return pRet;
}

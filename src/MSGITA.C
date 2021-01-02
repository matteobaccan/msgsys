/******************************************************************************
Project     : Clipper source
Description : Clipper National Message Source
Programmer  : Baccan Matteo
Home Page   : http://matteo.isanet.it
              http://www.dbsee.com
Email       : baccan@isanet.it
******************************************************************************/

#include <extend.api>

// Current language
char *_natmsgver(){
   return "ITALIANO";
}

// Message Version
CLIPPER _NATMSGVER(){
   _retc("NATMSGS v1.4 x16 04/June/97");
}

// Date picture formatter
CLIPPER _DDATEFMT(){
   _retc("DD-MM-YYYY");
}

// Get the number of the day and return the day String
char *_day_name( int nDay ){
   char *pRet="";

   switch( nDay ){
      case  1: pRet = "Domenica";    break;
      case  2: pRet = "Lunedç";      break;
      case  3: pRet = "Martedç";     break;
      case  4: pRet = "Mercoledç";   break;
      case  5: pRet = "Giovedç";     break;
      case  6: pRet = "Venerdç";     break;
      case  7: pRet = "Sabato";      break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Gennaio";     break;
      case  2: pRet = "Febbraio";    break;
      case  3: pRet = "Marzo";       break;
      case  4: pRet = "Aprile";      break;
      case  5: pRet = "Maggio";      break;
      case  6: pRet = "Giugno";      break;
      case  7: pRet = "Luglio";      break;
      case  8: pRet = "Agosto";      break;
      case  9: pRet = "Settembre";   break;
      case 10: pRet = "Ottobre";     break;
      case 11: pRet = "Novembre";    break;
      case 12: pRet = "Dicembre";    break;
   }

   return pRet;
}

// String used by Yes / No question
char *_ynstr(){
   return "S/N";
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
         case  1: pRet="File database     n¯Records    Ultimo Agg.     Dim."; break;
         case  2: pRet="Vuoi altri esempi?";          break;
         case  3: pRet="Pagina n¯";                   break;
         case  4: pRet="Subtotale";                   break;
         case  5: pRet="Subsubtotale";                break;
         case  6: pRet="Totale";                      break;
         case  7: pRet="Ins.";                        break;
         case  8: pRet="    ";                        break;
         case  9: pRet="Data non consentita";         break;
         case 10: pRet="Range da ";                   break;
         case 11: pRet=" a ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="Invalid argument";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Argument error";                 break;
      case 0x0002: pRet="Bound error";                    break;
      case 0x0003: pRet="Overflow di stringa";            break;
      case 0x0004: pRet="Overflow numerico";              break;
      case 0x0005: pRet="Divisione per zero";             break;
      case 0x0006: pRet="Numeric error";                  break;
      case 0x0007: pRet="Errore di sintassi";             break;
      case 0x0008: pRet="Operazione troppo complessa";    break;
      case 0x000b: pRet="Memoria bassa";                  break;
      case 0x000c: pRet="Funzione sconosciuta";           break;
      case 0x000d: pRet="Metodo non esportabile";         break;
      case 0x000e: pRet="Variabile inesistente";          break;
      case 0x000f: pRet="Alias inesistente";              break;
      case 0x0010: pRet="Variabile non esportabile";      break;
      case 0x0011: pRet="Carattere illegale in alias";    break;
      case 0x0012: pRet="Alias giÖ in uso";               break;
      case 0x0014: pRet="Errore di creazione";            break;
      case 0x0015: pRet="Errore d'apertura";              break;
      case 0x0016: pRet="Errore di chiusura";             break;
      case 0x0017: pRet="Errore di lettura";              break;
      case 0x0018: pRet="Errore di scrittura";            break;
      case 0x0019: pRet="Errore di stampa";               break;
      case 0x001E: pRet="Operazione non supportata";      break;
      case 0x001F: pRet="Limit exceeded";                 break;
      case 0x0020: pRet="Corruption detected";            break;
      case 0x0021: pRet="Data type error";                break;
      case 0x0022: pRet="Data width error";               break;
      case 0x0023: pRet="Workarea non in uso";            break;
      case 0x0024: pRet="Workarea non indicizzata";       break;
      case 0x0025: pRet="Exclusive required";             break;
      case 0x0026: pRet="Lock required";                  break;
      case 0x0027: pRet="Write not allowed";              break;
      case 0x0028: pRet="Append lock failed";             break;
      case 0x0029: pRet="Lock fallito";                   break;
      case 0x002D: pRet="Errore di lock";                 break;
      case 0x002E: pRet="Lock timeout";                   break;
      case 0x019F: pRet="Cannot open overlay file";       break;
      case 0x01A0: pRet="Read error on overlay file";     break;
      case 0x014B: pRet="String/array memory overflow";   break;
      case 0x0154: pRet="Too many Extend locks";          break;
      case 0x028A: pRet="Processor stack fault";          break;
      case 0x029B: pRet="Eval stack fault";               break;
      case 0x14B4: pRet="Memoria insufficente";           break;
      case 0x14B6: pRet="Memoria convenzionale esaurita"; break;
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

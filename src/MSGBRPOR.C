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
   return "BRAZILIAN PORTUGUESE";
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
      case  1: pRet = "Domingo";    break;
      case  2: pRet = "Segunda";      break;
      case  3: pRet = "Teráa";     break;
      case  4: pRet = "Quarta";   break;
      case  5: pRet = "Quinta";     break;
      case  6: pRet = "Sexta";     break;
      case  7: pRet = "Sabado";      break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Janeiro";     break;
      case  2: pRet = "Fevereiro";    break;
      case  3: pRet = "Maráo";       break;
      case  4: pRet = "Apri";      break;
      case  5: pRet = "Maio";      break;
      case  6: pRet = "Junho";      break;
      case  7: pRet = "Julio";      break;
      case  8: pRet = "Agosto";      break;
      case  9: pRet = "Setembro";   break;
      case 10: pRet = "Outubro";     break;
      case 11: pRet = "Novembro";    break;
      case 12: pRet = "Dezembro";    break;
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
         case  2: pRet="Voce quer mais Exemplos?";          break;
         case  3: pRet="Pagina n¯";                   break;
         case  4: pRet="Sub total";                   break;
         case  5: pRet="Subsubtotal";                break;
         case  6: pRet="Total";                      break;
         case  7: pRet="Ins.";                        break;
         case  8: pRet="    ";                        break;
         case  9: pRet="Data Invalida";         break;
         case 10: pRet="Range de ";                   break;
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
      case 0x0003: pRet="Overflow de string";            break;
      case 0x0004: pRet="Overflow numerico";              break;
      case 0x0005: pRet="Divisisao por zero";             break;
      case 0x0006: pRet="Numeric error";                  break;
      case 0x0007: pRet="Error de sintaxi";             break;
      case 0x0008: pRet="Operaá∆o muito complexa";    break;
      case 0x000b: pRet="Memoria baiza";                  break;
      case 0x000c: pRet="Funcao  indefinida";           break;
      case 0x000d: pRet="Metodo nao esportado";         break;
      case 0x000e: pRet="Variavel inesistente";          break;
      case 0x000f: pRet="Alias inesistente";              break;
      case 0x0010: pRet="Variavel n∆o esportada";      break;
      case 0x0011: pRet="Caracter ilegal no alias";    break;
      case 0x0012: pRet="Alias ja em uso";               break;
      case 0x0014: pRet="Error de criacao";            break;
      case 0x0015: pRet="Error de abertura";              break;
      case 0x0016: pRet="Error de fechamento";             break;
      case 0x0017: pRet="Error de leitura";              break;
      case 0x0018: pRet="Error de escrever";            break;
      case 0x0019: pRet="Error de Impress∆o";               break;
      case 0x001E: pRet="Operaá∆o n∆o supportada";      break;
      case 0x001F: pRet="Limit exceeded";                 break;
      case 0x0020: pRet="Corruption detected";            break;
      case 0x0021: pRet="Data type error";                break;
      case 0x0022: pRet="Data width error";               break;
      case 0x0023: pRet="Workarea n∆o emuso ";            break;
      case 0x0024: pRet="Workarea n∆o indexáada";       break;
      case 0x0025: pRet="Exclusive required";             break;
      case 0x0026: pRet="Lock required";                  break;
      case 0x0027: pRet="Write not allowed";              break;
      case 0x0028: pRet="Append lock failed";             break;
      case 0x0029: pRet="Falha lock";                   break;
      case 0x002D: pRet="Error de lock";                 break;
      case 0x002E: pRet="Lock timeout";                   break;
      case 0x019F: pRet="Cannot open overlay file";       break;
      case 0x01A0: pRet="Read error on overlay file";     break;
      case 0x014B: pRet="String/array memory overflow";   break;
      case 0x0154: pRet="Too many Extend locks";          break;
      case 0x028A: pRet="Processor stack fault";          break;
      case 0x029B: pRet="Eval stack fault";               break;
      case 0x14B4: pRet="Memoria insufficente";           break;
      case 0x14B6: pRet="Memoria convencional  exausta"; break;
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

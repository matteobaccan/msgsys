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
   return "MAGYAR CWI";
}

// Message Version
CLIPPER _NATMSGVER(){
   _retc("NATMSGS v1.4 x16 04/June/97");
}

// Date picture formatter
CLIPPER _DDATEFMT(){
   _retc("YYYY.MM.DD.");
}

// Get the number of the day and return the day String
char *_day_name( int nDay ){
   char *pRet="";

   switch( nDay ){
      case  1: pRet = "Vas�rnap";    break;
      case  2: pRet = "H�tf�";       break;
      case  3: pRet = "Kedd";        break;
      case  4: pRet = "Szerda";      break;
      case  5: pRet = "Cs�t�r�k";    break;
      case  6: pRet = "P�ntek";      break;
      case  7: pRet = "Szombat";     break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Janu�r";     break;
      case  2: pRet = "Febru�r";    break;
      case  3: pRet = "M�rcius";    break;
      case  4: pRet = "�prilis";    break;
      case  5: pRet = "M�jus";      break;
      case  6: pRet = "J�nius";     break;
      case  7: pRet = "J�lius";     break;
      case  8: pRet = "Augusztus";  break;
      case  9: pRet = "Szeptember"; break;
      case 10: pRet = "Okt�ber";    break;
      case 11: pRet = "November";   break;
      case 12: pRet = "December";   break;
   }

   return pRet;
}

// String used by Yes / No question
char *_ynstr(){
   return "I/N";
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
         case  1: pRet="Adatb�zisok       T�telsz�m    Utols� mod.     M�ret"; break;
         case  2: pRet="K�ri a tov�bbi r�szeket?";    break;
         case  3: pRet="Lapsz�m";                     break;
         case  4: pRet="** �sszesen **";              break;
         case  5: pRet="* R�sz�sszesen *";            break;
         case  6: pRet="*** Mind�sszesen ***";        break;
         case  7: pRet="Ins";                         break;
         case  8: pRet="   ";                         break;
         case  9: pRet="Rossz d�tum";                 break;
         case 10: pRet="Hat�rok: ";                   break;
         case 11: pRet=" - ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="Hib�s arumentum";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Argumentum hiba";                        break;
      case 0x0002: pRet="Hat�r�rt�k hiba";                        break;
      case 0x0003: pRet="Sztring t�lcsordul�s";                   break;
      case 0x0004: pRet="Sz�m t�lcsordul�s";                      break;
      case 0x0005: pRet="Null�val oszt�s";                        break;
      case 0x0006: pRet="Numerikus hiba";                         break;
      case 0x0007: pRet="Szintaxis hiba";                         break;
      case 0x0008: pRet="A m�velet t�l bonyolult";                break;
      case 0x000b: pRet="Kev�s a mem�ria";                        break;
      case 0x000c: pRet="Nem defini�lt f�ggv�ny";                 break;
      case 0x000d: pRet="Nem export�lt met�dus";                  break;
      case 0x000e: pRet="A v�ltoz� nem l�tezik";                  break;
      case 0x000f: pRet="Az aliasz nem l�tezik";                  break;
      case 0x0010: pRet="Nem export�lt v�ltoz�";                  break;
      case 0x0011: pRet="Illeg�lis karakterek az aliaszban";      break;
      case 0x0012: pRet="Az aliasz m�r haszn�lt";                 break;
      case 0x0014: pRet="L�trehoz�si hiba";                       break;
      case 0x0015: pRet="Megnyit�si hiba";                        break;
      case 0x0016: pRet="Z�r�si hiba";                            break;
      case 0x0017: pRet="Olvas�si hiba";                          break;
      case 0x0018: pRet="�r�si hiba";                             break;
      case 0x0019: pRet="Nyomtat�si hiba";                        break;
      case 0x001E: pRet="Nem t�mogatott m�velet";                 break;
      case 0x001F: pRet="Hat�r�rt�k t�ll�p�s";                    break;
      case 0x0020: pRet="Korrupci�t �szleltem";                   break;
      case 0x0021: pRet="Adatt�pus hiba";                         break;
      case 0x0022: pRet="Adatsz�less�g hiba";                     break;
      case 0x0023: pRet="Haszn�laton k�v�li munkater�let";        break;
      case 0x0024: pRet="A munkater�let nincs indexelve";         break;
      case 0x0025: pRet="Kiz�r�lagos haszn�lat sz�ks�ges";        break;
      case 0x0026: pRet="Z�rol�s sz�ks�ges";                      break;
      case 0x0027: pRet="Az �r�s nem megengedett";                break;
      case 0x0028: pRet="A hozz�f�z�si z�rol�s sikertelen";       break;
      case 0x0029: pRet="A z�rol�s sikertelen";                   break;
      case 0x002D: pRet="Z�rol�si hiba";                          break;
      case 0x002E: pRet="Z�rol�si id�t�ll�p�s";                   break;
      case 0x019F: pRet="Az overlay f�jl nem tudom megnyitni";    break;
      case 0x01A0: pRet="Olvas�si hiba az overlay f�jln�l";       break;
      case 0x014B: pRet="Sztring/t�mb mem�ria t�lcsordul�s";      break;
      case 0x0154: pRet="T�l sok Extend Lock";                    break;
      case 0x028A: pRet="Processzor verem hiba";                  break;
      case 0x029B: pRet="Ki�rt�kel� verem (Eval stack) hiba";     break;
      case 0x14B4: pRet="Nincs el�g mem�ria";                     break;
      case 0x14B6: pRet="A hagyom�nyos mem�ria elfogyott";        break;
      case 0x14BF: pRet="A VM swap f�jlt nem tudom l�trehozni";   break;
      case 0x14C0: pRet="A VM swap f�jl t�lfoglalva";             break;
      case 0x14C1: pRet="Nics el�g hely a VM swap f�jlnak";       break;
      case 0x270C: pRet="Megszak�tva";                            break;
      case 0x270D: pRet="Hiba ut�ni helyre�ll�s sikertelen";      break;
      case 0x270E: pRet="Helyrehozhatatlan hiba";                 break;
      case 0x270F: pRet="Bels� hiba";                             break;

   }

   return pRet;
}

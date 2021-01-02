/******************************************************************************
Project     : Clipper source
Description : Clipper National Message Source
Programmer  : Baccan Matteo, Vincent DUFFAUT <VincentDUFFAUT@compuserve.com>
Home Page   : http://matteo.isanet.it
              http://www.dbsee.com
Email       : baccan@isanet.it
******************************************************************************/

#include <extend.api>

// Current language
char *_natmsgver(){
   return "FRENCH";
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
      case  1: pRet = "Dimanche";   break;
      case  2: pRet = "Lundi";      break;
      case  3: pRet = "Mardi";      break;
      case  4: pRet = "Mercredi";   break;
      case  5: pRet = "Jeudi";      break;
      case  6: pRet = "Vendredi";   break;
      case  7: pRet = "Samedi";     break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Janvier";     break;
      case  2: pRet = "F‚vrier";     break;
      case  3: pRet = "Mars";        break;
      case  4: pRet = "Avril";       break;
      case  5: pRet = "Mai";         break;
      case  6: pRet = "Juin";        break;
      case  7: pRet = "Juillet";     break;
      case  8: pRet = "Ao–t";        break;
      case  9: pRet = "Septembre";   break;
      case 10: pRet = "Octobre";     break;
      case 11: pRet = "Novembre";    break;
      case 12: pRet = "D‚cembre";    break;
   }

   return pRet;
}

// String used by Yes / No question
char *_ynstr(){
   return "O/N";
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
         case  1: pRet="Base de données   Nb Enreg.    Mise à jour     Taille"; break;
         case  2: pRet="Voulez-vous d'autres ‚chantillons?";   break;
         case  3: pRet="Page N°";                     break;
         case  4: pRet="** Total interm‚diaire **";   break;
         case  5: pRet="* Total partiel *";           break;
         case  6: pRet="*** Total ***";               break;
         case  7: pRet="Ins";                         break;
         case  8: pRet="   ";                         break;
         case  9: pRet="Date Invalide";               break;
         case 10: pRet="Limites : ";                  break;
         case 11: pRet=" - ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="Erreur d'argument";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Erreur d'argument";					break;
      case 0x0002: pRet="Erreur de dimension";					break;
      case 0x0003: pRet="D‚passement de capacit‚ de chaŒne de caractŠres";	break;
      case 0x0004: pRet="D‚passement de capacit‚ num‚rique";			break;
      case 0x0005: pRet="Diviseur z‚ro";                  			break;
      case 0x0006: pRet="Erreur num‚rique";               			break;
      case 0x0007: pRet="Erreur de syntaxe";              			break;
      case 0x0008: pRet="Op‚ration trop complexe";        			break;
      case 0x000b: pRet="M‚moire basse";                  			break;
      case 0x000c: pRet="Fonction non d‚finie";           			break;
      case 0x000d: pRet="M‚thode externe inexistante";        			break;
      case 0x000e: pRet="Variable inexistante";	        			break;
      case 0x000f: pRet="Alias inexistant";					break;
      case 0x0010: pRet="Variable d'instance externe inexistante";		break;
      case 0x0011: pRet="CaractŠres incorrects dans l'alias";			break;
      case 0x0012: pRet="Alias d‚j… utilis‚";					break;
      case 0x0014: pRet="Erreur de cr‚ation";						break;
      case 0x0015: pRet="Erreur d'ouverture";             			break;
      case 0x0016: pRet="Erreur de fermeture";            			break;
      case 0x0017: pRet="Erreur de lecture";              			break;
      case 0x0018: pRet="Erreur d'‚criture";              			break;
      case 0x0019: pRet="Erreur d'impression";            			break;
      case 0x001E: pRet="Opération non support‚e";        			break;
      case 0x001F: pRet="Valeur limite d‚pass‚e";                		break;
      case 0x0020: pRet="Corruption d‚tect‚e";            			break;
      case 0x0021: pRet="Erreur de type de donn‚e";       			break;
      case 0x0022: pRet="Erreur de taille de donn‚e";    			break;
      case 0x0023: pRet="Zone de travail n'est pas en utilisation";             break;
      case 0x0024: pRet="Zone de travail non index‚e";               		break;
      case 0x0025: pRet="Mode exclusif requis";           			break;
      case 0x0026: pRet="Verrou requis";                  			break;
      case 0x0027: pRet="Ecriture non autoris‚e";         			break;
      case 0x0028: pRet="Verrou refus‚ lors d'un ajout";           		break;
      case 0x0029: pRet="D‚faillance de verrouillage";             		break;
      case 0x002D: pRet="Erreur de verrouillage";                  		break;
      case 0x002E: pRet="Temps limite de verrouillage d‚pass‚";			break;
      case 0x019F: pRet="Ouverture du fichier de recouvrement (Overlay) impossible";       break;
      case 0x01A0: pRet="Erreur de lecture du fichier de recouvrement (Overlay)";     break;
      case 0x014B: pRet="D‚passement de capacit‚ de m‚moire sur chaŒne de caractŠres/tableau";   break;
      case 0x0154: pRet="Trop d'allocations verrouill‚es";        		break;
      case 0x028A: pRet="Erreur de gestion de la pile de programme";    	break;
      case 0x029B: pRet="Trop d'empilage dans le programme";  			break;
      case 0x14B4: pRet="M‚moire insuffisante";              			break;
      case 0x14B6: pRet="M‚moire conventionnelle ‚puis‚e";			break;
      case 0x14BF: pRet="Impossible de cr‚er le fichier swap du VM";    	break;
      case 0x14C0: pRet="D‚passement d'allocation du fichier swap du VM";	break;
      case 0x14C1: pRet="Espace disque insuffisant pour le fichier swap du VM";  break;
      case 0x270C: pRet="Annul‚";                        			break;
      case 0x270D: pRet="D‚faillance de r‚cup‚ration d'erreur";         	break;
      case 0x270E: pRet="Erreur irr‚cup‚rable";           			break;
      case 0x270F: pRet="Erreur interne";                 			break;
   }

   return pRet;
}

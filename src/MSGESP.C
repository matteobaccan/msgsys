/******************************************************************************
Project     : Clipper source
Description : Clipper National Message Source
Programmer  : Baccan Matteo
Home Page   : http://matteo.isanet.it
              http://www.dbsee.com
Email       : baccan@isanet.it
Translation : Pablo R. Montenegro C. (pablormc@yahoo.com)
******************************************************************************/

#include <extend.api>

// Current language
char *_natmsgver(){
   return "ESPA¥OL";
}

// Message Version
CLIPPER _NATMSGVER(){
   _retc("NATMSGS v1.4 x16 04/June/97");
}

// Date picture formatter
CLIPPER _DDATEFMT(){
   _retc("DD/MM/YYYY");
}

// Get the number of the day and return the day String
char *_day_name( int nDay ){
   char *pRet="";

   switch( nDay ){
      case  1: pRet = "Domingo";    break;
      case  2: pRet = "Lunes";      break;
      case  3: pRet = "Martes";     break;
      case  4: pRet = "Mi‚rcoles";  break;
      case  5: pRet = "Jueves";     break;
      case  6: pRet = "Viernes";    break;
      case  7: pRet = "S bado";     break;
   }

   return pRet;
}

// Get the number of the month and return the month String
char *_month_name( int nMonth ){
   char *pRet="";

   switch( nMonth ){
      case  1: pRet = "Enero";       break;
      case  2: pRet = "Febrero";     break;
      case  3: pRet = "Marzo";       break;
      case  4: pRet = "Abril";       break;
      case  5: pRet = "Mayo";        break;
      case  6: pRet = "Junio";       break;
      case  7: pRet = "Julio";       break;
      case  8: pRet = "Agosto";      break;
      case  9: pRet = "Septiembre";  break;
      case 10: pRet = "Octubre";     break;
      case 11: pRet = "Noviembre";   break;
      case 12: pRet = "Diciembre";   break;
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
         case  1: pRet="Archivos DBF     # Registros    Ult. Act.    Tama¤o"; break;
         case  2: pRet="¨Desea m s ejemplos?";        break;
         case  3: pRet="Hoja No.";                    break;
         case  4: pRet="** Subtotal **";              break;
         case  5: pRet="* Subsubtotal *";             break;
         case  6: pRet="*** Total ***";               break;
         case  7: pRet="Ins";                         break;
         case  8: pRet="   ";                         break;
         case  9: pRet="Fecha no v lida";             break;
         case 10: pRet="Rango: ";                     break;
         case 11: pRet=" - ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="Argumento no v lido";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Error de argumento";                                   break;
      case 0x0002: pRet="Error de l¡mite";                                      break;
      case 0x0003: pRet="Desbordamiento de cadena";                             break;
      case 0x0004: pRet="Desbordamiento n£merico";                              break;
      case 0x0005: pRet="Divisor cero";                                         break;
      case 0x0006: pRet="Error n£merico";                                       break;
      case 0x0007: pRet="Error de sint xis";                                    break;
      case 0x0008: pRet="Operaci¢n demasiado compleja";                         break;
      case 0x000b: pRet="Poca memoria";                                         break;
      case 0x000c: pRet="Funci¢n indefinida";                                   break;
      case 0x000d: pRet="No es un m‚todo exportado";                            break;
      case 0x000e: pRet="La variable no existe";                                break;
      case 0x000f: pRet="El alias no existe";                                   break;
      case 0x0010: pRet="No es una variable exportada";                         break;
      case 0x0011: pRet="Caracteres ilegales en el alias";                      break;
      case 0x0012: pRet="El alias ya est  en uso";                              break;
      case 0x0014: pRet="Error de creaci¢n";                                    break;
      case 0x0015: pRet="Error de apertura";                                    break;
      case 0x0016: pRet="Error al cerrar";                                      break;
      case 0x0017: pRet="Error de lectura";                                     break;
      case 0x0018: pRet="Error de escritura";                                   break;
      case 0x0019: pRet="Error de impresi¢n";                                   break;
      case 0x001E: pRet="Operaci¢n no soportada";                               break;
      case 0x001F: pRet="L¡mite excedido";                                      break;
      case 0x0020: pRet="Corrupci¢n detectada";                                 break;
      case 0x0021: pRet="Error de tipo de datos";                               break;
      case 0x0022: pRet="Error de ancho de datos";                              break;
      case 0x0023: pRet="El  rea de trabajo no est  en uso";                    break;
      case 0x0024: pRet="El  rea de trabajo no est  indexada";                  break;
      case 0x0025: pRet="Se requiere uso Exclusivo";                            break;
      case 0x0026: pRet="Se requiere bloqueo";                                  break;
      case 0x0027: pRet="Escritura no permitida";                               break;
      case 0x0028: pRet="Falla al bloquear para a¤adir (Append)";               break;
      case 0x0029: pRet="Falla al bloquear";                                    break;
      case 0x002D: pRet="Error de bloqueo";                                     break;
      case 0x002E: pRet="Se ha excedido el tiempo del bloqueo";                 break;
      case 0x019F: pRet="No puedo abrir el archivo superpuesto (overlay)";      break;
      case 0x01A0: pRet="Error de lectura en el archivo superpuesto (overlay)"; break;
      case 0x014B: pRet="Desbordamiento de la memoria de Cadenas/Vectores";     break;
      case 0x0154: pRet="Demasiados bloqueos extendidos";                       break;
      case 0x028A: pRet="Violaci¢n de la pila del Procesador";                  break;
      case 0x029B: pRet="Violaci¢n de la pila de Evaluaci¢n";                   break;
      case 0x14B4: pRet="No hay suficiente memoria";                            break;
      case 0x14B6: pRet="Memoria convencional insuficiente";                    break;
      case 0x14BF: pRet="No puedo crear el archivo de intercambio para VM";     break;
      case 0x14C0: pRet="Archivo de intercambio de VM sobreasignado";           break;
      case 0x14C1: pRet="Sin espacio para el archivo de intercambio de VM";     break;
      case 0x270C: pRet="Cancelado";                                            break;
      case 0x270D: pRet="Fracaso en la recuperaci¢n del error";                 break;
      case 0x270E: pRet="Error irrecuperable";                                  break;
      case 0x270F: pRet="Error Interno";                                        break;
   }

   return pRet;
}
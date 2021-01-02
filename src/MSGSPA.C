/******************************************************************************
Project     : Clipper source
Description : Clipper National Message Source (Spanish)
Programmer  : Baccan Matteo (translated to spanish by Ignacio Ortiz de Zuñiga)
Home Page   : http://matteo.isanet.it
              http://www.dbsee.com; http://www.ozs.com
Email       : baccan@isanet.it; ignacio@ozs.com
Note        : All strings are in Ansi format
******************************************************************************/

#include <extend.api>

// Current language
char *_natmsgver(){
   return "SPANISH";
}

// Message Version
CLIPPER _NATMSGVER(){
   _retc("NATMSGS v1.4 x16 24/November/99");
}

// Date picture formatter
CLIPPER _DDATEFMT(){
   _retc("DD-MM-YYYY");
}

// Get the number of the day and return the day String
char *_day_name( int nDay ){
   char *pRet="";

   switch( nDay ){
      case  1: pRet = "Domingo";   break;
      case  2: pRet = "Lunes";     break;
      case  3: pRet = "Martes";    break;
      case  4: pRet = "Miercoles"; break;
      case  5: pRet = "Jueves";    break;
      case  6: pRet = "Viernes";   break;
      case  7: pRet = "Sabado";    break;
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
         case  1: pRet="Ficheros Datos    # Registros    Ultima actualización     Tamaño"; break;
         case  2: pRet="¿Necesita más ejemplos?";     break;
         case  3: pRet="N. Página";                   break;
         case  4: pRet="** Subtotal **";              break;
         case  5: pRet="* Subsubtotal *";             break;
         case  6: pRet="*** Total ***";               break;
         case  7: pRet="Ins";                         break;
         case  8: pRet="   ";                         break;
         case  9: pRet="Fecha Invalida";              break;
         case 10: pRet="Rango: ";                     break;
         case 11: pRet=" - ";                         break;
         case 12: pRet=_ynstr();                      break;
      }
   } else pRet="Argumento invalido";

   _retc( pRet );
}

// Return the description of one error
char *_errordesc( unsigned int nErr ){
   char *pRet="";

   switch( nErr ) {
      case 0x0001: pRet="Error de argumento";                                       break;
      case 0x0002: pRet="Error de rango";                                           break;
      case 0x0003: pRet="Desbordamiento de cadena de caracteres";                   break;
      case 0x0004: pRet="Desbordamiento numérico";                                  break;
      case 0x0005: pRet="División por cero";                                        break;
      case 0x0006: pRet="Error numérico";                                           break;
      case 0x0007: pRet="Erros de sintaxis";                                        break;
      case 0x0008: pRet="Operación demasiado compleja";                             break;
      case 0x000b: pRet="Memoria insuficiente";                                     break;
      case 0x000c: pRet="Función no definida";                                      break;
      case 0x000d: pRet="Método no exportado";                                      break;
      case 0x000e: pRet="Variable no existe";                                       break;
      case 0x000f: pRet="Alias no existe";                                          break;
      case 0x0010: pRet="Variable no exportada";                                    break;
      case 0x0011: pRet="Caracteres ilegales en alias";                             break;
      case 0x0012: pRet="Alias en uso";                                             break;
      case 0x0014: pRet="Error de creación";                                        break;
      case 0x0015: pRet="Error de apertura";                                        break;
      case 0x0016: pRet="Error de cierre";                                          break;
      case 0x0017: pRet="Error de lectura";                                         break;
      case 0x0018: pRet="Error de escritura";                                       break;
      case 0x0019: pRet="Error de impresión";                                       break;
      case 0x001E: pRet="Operación no soportada";                                   break;
      case 0x001F: pRet="Límite excedido";                                          break;
      case 0x0020: pRet="Detectada corrupción";                                     break;
      case 0x0021: pRet="Error en tipo de datos";                                   break;
      case 0x0022: pRet="Error en anchura de datos";                                break;
      case 0x0023: pRet="Area de trabajo no esta en uso";                           break;
      case 0x0024: pRet="Area de trabajo no indexada";                              break;
      case 0x0025: pRet="Apertura en exclusivo requerida";                          break;
      case 0x0026: pRet="Bloqueo de fichero requerido";                             break;
      case 0x0027: pRet="Escritura prohibida";                                      break;
      case 0x0028: pRet="Fracaso en bloqueo por alta";                              break;
      case 0x0029: pRet="Fracaso en bloqueo";                                       break;
      case 0x002D: pRet="Error de bloqueo";                                         break;
      case 0x002E: pRet="Tiempo agotado para bloqueo";                              break;
      case 0x019F: pRet="No se puede abrir archivo de Overlay";                     break;
      case 0x01A0: pRet="Error de lectura en archivo de Overlay";                   break;
      case 0x014B: pRet="Desbordamiento de memoria en cadena de caracteres/matriz"; break;
      case 0x0154: pRet="Demasiados bloqueos";                                      break;
      case 0x028A: pRet="Fallo en la pila del procesador";                          break;
      case 0x029B: pRet="Fallo de la pila de evaluación";                           break;
      case 0x14B4: pRet="Memoria insuficiente";                                     break;
      case 0x14B6: pRet="Memooria convencional exhausta";                           break;
      case 0x14BF: pRet="No se puede crear el fichero de intercambio VM";           break;
      case 0x14C0: pRet="Fichero de intercambio VM sobreasignado";                  break;
      case 0x14C1: pRet="Sin memoria en el fichero de intercambio VM";              break;
      case 0x270C: pRet="Cancelado";                                                break;
      case 0x270D: pRet="Fracaso en recuperación de error";                         break;
      case 0x270E: pRet="Error no recuperable";                                     break;
      case 0x270F: pRet="Error interno";                                            break;
   }

   return pRet;
}
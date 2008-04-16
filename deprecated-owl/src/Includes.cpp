/*
    FreeDFD: Editor e int�rprete de diagramas de flujo.
    Copyright (C) 1997-2006

    Nelson Castillo Izquierdo <arhuaco@freaks-unidos.net>
    Eduardo Daza Castillo <eduardodazacastillo@gmail.com>
    Fabi�n C�rdenas Varela <f_cardenas@yahoo.com>

    **********

    Necesitamos ayuda para terminar la nueva versi�n, que funcionar� dentro
    de GNU/Linux y dentro de Windows, y que incluir� m�ltiples mejoras.
    Vis�tenos en:

    http://freedfd.freaks-unidos.net

 Espa�ol:

    Este programa es software libre. Puede redistribuirlo y/o modificarlo
    bajo los t�rminos de la Licencia P�blica General de GNU seg�n es
    publicada por la Free Software Foundation, bien de la versi�n 2 de dicha
    Licencia o bien (seg�n su elecci�n) de cualquier versi�n posterior.

    Este programa se distribuye con la esperanza de que sea �til, pero SIN
    NINGUNA GARANT�A, incluso sin la garant�a MERCANTIL impl�cita o sin
    garantizar la CONVENIENCIA PARA UN PROP�SITO PARTICULAR. V�ase la
    Licencia P�blica General de GNU para m�s detalles.

    Deber�a haber recibido una copia de la Licencia P�blica General junto
    con este programa. Si no ha sido as�, escriba a la Free Software
    Foundation, Inc., en 675 Mass Ave, Cambridge, MA 02139, EEUU.

 English:

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/


#ifndef __INCLUDES_CPP
#define __INCLUDES_CPP


  enum Accion{ EDICION= 0, EJECUCION, DEPURACION };


  enum TipoDato  { REAL, STRING, LOGICO };

  enum TipoToken { OPERADOR, OPERANDO };
  enum AlcanceOperador { UNITARIO, BINARIO, UNITARIOBINARIO, ARRAY };
  enum TipoAlmacenamiento { CONSTANTE, VARIABLE };


  enum TipoError
  {
    LOS_TIPOS_NO_COINCIDEN, ID_NO_ES_ARREGLO, DIMENSION_NO_VALIDA,
    CONSTANTE_NUMERICA_ILEGAL, NOMBRE_VARIABLE_INCORRECTO,
    FUNCION_REQUIERE_PARAMETRO,
    FALTA_OPERADOR, CERRADO_PARENTESIS_NO_ABIERTO,
    CADENA_INDETERMINADA,
    CONSTANTE_LOGICA_ILEGAL, OPERADOR_LOGICO_ILEGAL,
    FALTA_OPERANDO, OPERADOR_ILEGAL,
    CARACTER_ILEGAL, ABIERTO_PARENTESIS_NO_CERRADO,
    LLAMADO_DE_FUNCION_NO_VALIDO,
    ERROR_INDEFINIDO, DESBORDAMIENTO, DESBORDAMIENTO_NEGATIVO,
    VARIABLE_NO_EXISTE, VARIABLE_NO_INICIALIZADA,
    DIVISION_POR_CERO, INDICES,
    ILEGAL_COMA_O_CADENA_VACIA, SOLO_VARIABLES,NO_INDICES,
    TIPO_DEBE_SER_LOGICO, VINICIAL_CONTADOR,
    VFINAL_CONTADOR, INCREMENTO_CONSTANTE, CONTADOR_REAL,
    LIMITE_REAL, PARAMETRO_ILEGAL, PARAMETRO_REPETIDO,
    ILEGAL_NOMBRE_SUBPROGRAMA, SUBPROGRAMA_NO_EXISTE,
    SUBPROGRAMA_REPETIDO, MUCHOS_ARGUMENTOS, POCOS_ARGUMENTOS};

	#include <math.h>
	#include <float.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <new.h>
	#include <ctype.h>
	#include <dir.h>
	#include "errores.cpp"
	#include "campos.cpp"
	#include "operador.cpp"
	#include "tokeniza.cpp"
	#include "errormat.cpp"
	#include "funcion.cpp"
	#include "arreglos.cpp"
	#include "analiza.cpp"
	#include "oe.cpp"
	#include "editor.cpp"
	#include "dialogos.cpp"
	#include "imprimir.cpp"
            
#endif

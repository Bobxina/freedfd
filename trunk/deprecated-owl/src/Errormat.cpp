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



// Este handler evita que el programa se muera cuando se presentan
// algunas excepciones. Al mismo tiempo, permite dar mensajes m�s
// �tiles al usuario.

#ifndef __ERRORMAT_CPP
#define __ERRORMAT_CPP


int _matherrl (struct _exceptionl *a)
{

	if( !strcmpi(a->name,"powl") )
		Buzon.SetIdentificadorAsociado( "^" );

	else if( !strcmpi(a->name,"sinl") )
		Buzon.SetIdentificadorAsociado( "SIN" );

	else if( !strcmpi(a->name,"cosl") )
		Buzon.SetIdentificadorAsociado( "COS" );

	else if( !strcmpi(a->name,"tanl") )
		Buzon.SetIdentificadorAsociado( "TAN" );

	else if( !strcmpi(a->name,"acosl") )
		Buzon.SetIdentificadorAsociado( "ACOS" );

	else if( !strcmpi(a->name,"asinl") )
		Buzon.SetIdentificadorAsociado( "ASIN" );

	else if( !strcmpi(a->name,"atanl") )
		Buzon.SetIdentificadorAsociado( "ATAN" );


	else if( !strcmpi(a->name,"sinhl") )
		Buzon.SetIdentificadorAsociado( "SINH" );

	else if( !strcmpi(a->name,"coshl") )
		Buzon.SetIdentificadorAsociado( "COSH" );

	else if( !strcmpi(a->name,"tanhl") )
		Buzon.SetIdentificadorAsociado( "TANH" );

	else if( !strcmpi(a->name,"expl") )
		Buzon.SetIdentificadorAsociado( "EXP" );

	else if( !strcmpi(a->name,"logl") )
		Buzon.SetIdentificadorAsociado( "LN" );

	else if( !strcmpi(a->name,"log10l") )
		Buzon.SetIdentificadorAsociado( "LOG" );

	else if( !strcmpi(a->name,"sqrtl") )
		Buzon.SetIdentificadorAsociado( "SQRT" );

	else
		Buzon.SetIdentificadorAsociado( "????/MATHERRL" );

	Buzon.Error( LLAMADO_DE_FUNCION_NO_VALIDO );
	a->retval=1;
	return 1;
 }

 #endif

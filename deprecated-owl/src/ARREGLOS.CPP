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



// Esta funcion accesa al valor de un arreglo cuyos nombre y respectivos
// subindices se encuentran en la pila que se recibe como parametro.

#ifndef __ARREGLOS_CPP
#define __ARREGLOS_CPP



  void AccesoArreglo( Token **Pila, int Dim ){

	 unsigned *Indices= new unsigned[Dim];
	 Token **TokenIndice= new Token *[Dim];
	 Token *YoRecorro= *Pila;

	 // Se guarda la direccion de los Token's que serviran de indices en
	 // el vector de apuntadores TokenIndice
	 for( int i= 0 ; i<Dim ; ++i ){
		TokenIndice[i]= ObtieneTokenPila( YoRecorro );
		if( Buzon.GetHuboError() ){
		  for( int j= 0 ; j<i ; ++j )
			 BorrarToken( TokenIndice[j] );
		  delete []TokenIndice;     // nelson280897
		  delete[] Indices;
		  return ;
		}
		YoRecorro= YoRecorro->GetSig();
	 }
	 bool Error= false;

	 // Se revisa que los indices san valores adecuados
	 for( int i= 0 ; i<Dim ; ++i ){
		if( TokenIndice[i]->GetTipoDato() != REAL ){
		  Error= true;
		  break;
		}
		long double ValorReal= TokenIndice[i]->GetDatoReal();
		if( ValorReal<0.0L || ValorReal>65535.0L ||
			 ( floorl( ValorReal )!= ValorReal ) ){
		  Error= true;
		  break;
		}
		Indices[Dim-1-i]= ( unsigned ) ValorReal;
	 }

	 if( Error ){
		Buzon.SetIdentificadorAsociado( YoRecorro->GetDatoStr() );
		Buzon.Error( INDICES );
		for( int j= 0 ; j< Dim ; ++j )
		  BorrarToken( TokenIndice[j] );
      delete []TokenIndice; // nelson280897
		delete[] Indices;
		return ;
	 }
	 Token *TokenRetorno= PilaDeTablas.Leer( YoRecorro->GetDatoStr(),
														  Indices, Dim );
	 for( int i= 0 ; i< Dim ; ++i )
		BorrarToken( TokenIndice[i] );
	 delete[] Indices;
	 delete[] TokenIndice;  // nelson280897
	 if( Buzon.GetHuboError() )
		return ;
	 for( int i= 0 ; i< Dim+1 ; ++i )
		delete Desapila( Pila );
	 Apila( Pila, TokenRetorno );
	 return ;
  }

#endif
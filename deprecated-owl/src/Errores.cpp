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


#ifndef __ERRORES_CPP
#define __ERRORES_CPP


 class BuzonDeErrores{

	  struct Mensaje{
		 char *Info;
		 TipoError Tipo;
		 Mensaje *Sig;
	  }*Inicio;

	  char *IdentificadorAsociado;
	  bool HuboError;
	  void IntroducirError( char *Id , TipoError UnError, int Asociado= 1 );

	public:

	  BuzonDeErrores(){
		 Inicio=0; IdentificadorAsociado= 0;
		 HuboError= false;
	  }
	  void Error(TipoError UnError);
	  bool GetHuboError(){ return HuboError; }
	  char *GetIdentificadorAsociado(){ return IdentificadorAsociado; }
	  char *GetError();
	  void SetIdentificadorAsociado( char  *Id );
	  void Mostrar();
	  void Vacear();
	  ~BuzonDeErrores();

 }Buzon;


 void BuzonDeErrores::Vacear(){
	Mensaje *Aux;
	while( Inicio ){
	  Aux= Inicio;
	  Inicio=Inicio->Sig;
	  delete[] Aux->Info;
	  delete Aux;
	}
	HuboError= false;
 }


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 void BuzonDeErrores::IntroducirError( char *Id, TipoError UnError, int Asociado ){

	HuboError= true;
	Mensaje *NuevoError;
	NuevoError= new Mensaje;

	NuevoError->Tipo= UnError;
	int LargoIdentificador= (IdentificadorAsociado)?
									 strlen( IdentificadorAsociado ) : 0;
	int LargoError= strlen( Id );
	NuevoError->Sig= Inicio;
	Inicio= NuevoError;

	NuevoError->Info= new char[LargoIdentificador+LargoError +2];
	NuevoError->Info[0]= 0;
	if( Asociado )
	  strcpy( NuevoError->Info, IdentificadorAsociado );
	strcat( NuevoError->Info, Id );
 }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 void BuzonDeErrores::SetIdentificadorAsociado(char  *Id){
		 if( IdentificadorAsociado )
			 delete[] IdentificadorAsociado;
		 IdentificadorAsociado= new char[strlen(Id)+1];
		 strcpy( IdentificadorAsociado, Id );
 }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 void BuzonDeErrores::Error( TipoError UnError ){


	switch( UnError ){

	  case DESBORDAMIENTO:
		 IntroducirError( ":Desbordamiento en la operaci�n", DESBORDAMIENTO );
		 break;

	  case DESBORDAMIENTO_NEGATIVO:
		 IntroducirError( ":Desbordamiento negativo en la operaci�n",
		 DESBORDAMIENTO_NEGATIVO );
		 break;

	  case LOS_TIPOS_NO_COINCIDEN:
		 IntroducirError( ": Los tipos no coinciden", LOS_TIPOS_NO_COINCIDEN );
		 break;

	  case ID_NO_ES_ARREGLO:
		 IntroducirError( ": El identificador no es es un arreglo", ID_NO_ES_ARREGLO );
		 break;

	  case DIMENSION_NO_VALIDA:
		 IntroducirError( ": Dimensi�n no v�lida", DIMENSION_NO_VALIDA );
		 break;

	  case CONSTANTE_NUMERICA_ILEGAL:
		 IntroducirError( ": Constante num�rica ilegal",
								CONSTANTE_NUMERICA_ILEGAL );
		 break;

	  case NOMBRE_VARIABLE_INCORRECTO:
		 IntroducirError( ": Nombre de variable incorrecto",
								NOMBRE_VARIABLE_INCORRECTO );
		 break;

	  case FUNCION_REQUIERE_PARAMETRO:
		 IntroducirError(": La funci�n requiere argumentos",
								FUNCION_REQUIERE_PARAMETRO );
		 break;

	  case FALTA_OPERADOR:
		 IntroducirError( ": Se esper� un operador", FALTA_OPERADOR );
		 break;

	  case CADENA_INDETERMINADA:
		 IntroducirError( ": Se esper� ' para delimitar la cadena",
								 CADENA_INDETERMINADA );
		 break;

/*	  case OPERADOR_ILEGAL_DE_CADENA:
		 IntroducirError( ": No es un operador v�lido para una cadena",
								OPERADOR_ILEGAL_DE_CADENA );
		 break;
*/
	  case CONSTANTE_LOGICA_ILEGAL:
		 IntroducirError( " : Se esper� una constante l�gica( .V. o .F. )",
								 CONSTANTE_LOGICA_ILEGAL );
		 break;

	  case OPERADOR_LOGICO_ILEGAL:
		 IntroducirError( ": Operador l�gico ilegal",
								OPERADOR_LOGICO_ILEGAL );
		 break;

	  case FALTA_OPERANDO:
		 IntroducirError( ": Se esper� un operando", FALTA_OPERANDO );
		 break;

	 /* case OPERANDO_ILEGAL:
		 IntroducirError( ": El operador recibi� un operando ilegal",
								 OPERANDO_ILEGAL );
		 break;
      */
	  case OPERADOR_ILEGAL:
		 IntroducirError( ": Operador ilegal", OPERADOR_ILEGAL );
		 break;

	  case CARACTER_ILEGAL:
		 IntroducirError( ": Caracter ilegal", CARACTER_ILEGAL );
		 break;

	  case CERRADO_PARENTESIS_NO_ABIERTO:
		 IntroducirError( ": Cerrado par�ntesis no abierto",
								CERRADO_PARENTESIS_NO_ABIERTO );
		 break;

	  case ABIERTO_PARENTESIS_NO_CERRADO:
		 IntroducirError( ": Abierto par�ntesis no cerrado",
								ABIERTO_PARENTESIS_NO_CERRADO );
		 break;

	 /* case COMA_ILEGAL:
		 IntroducirError( ": Uso ilegal del operador", COMA_ILEGAL );
		 break;*/

/*	  case ERROR_MATEMATICO:
		 IntroducirError( ": Error Matem�tico", ERROR_MATEMATICO );
		 break;*/

	  case LLAMADO_DE_FUNCION_NO_VALIDO:
		 IntroducirError( ": Llamado de funci�n no v�lido", LLAMADO_DE_FUNCION_NO_VALIDO);
		 break;

	  case VARIABLE_NO_INICIALIZADA:
		 IntroducirError( ": Variable no inicializada",
								 VARIABLE_NO_INICIALIZADA );
		 break;

	  case VARIABLE_NO_EXISTE:
		 IntroducirError( ": Variable no existe", VARIABLE_NO_EXISTE );
		 break;

	  case DIVISION_POR_CERO:
		 IntroducirError( ": Divisi�n por cero", DIVISION_POR_CERO );
		 break;

/*	  case SUBINDICE_NO_VALIDO:
		 IntroducirError( ": Indice no v�lido", SUBINDICE_NO_VALIDO );
		 break;*/

	  case INDICES:
		 IntroducirError( "Los �ndices deben ser enteros no negativos menores o iguales a 65535.",
								 INDICES, 0 );
		 break;

	  case ILEGAL_COMA_O_CADENA_VACIA:
		 IntroducirError( "Uso ilegal de la coma � falta expresi�n",
								 ILEGAL_COMA_O_CADENA_VACIA, 0 );
		 break;

	  case SOLO_VARIABLES:
		 IntroducirError( "La asignaci�n de valores solo se realiza en campos variables",
								 SOLO_VARIABLES, 0 );
		 break;


	  case NO_INDICES:
		 IntroducirError( "No hay �ndices entre los par�ntesis.",
								 NO_INDICES, 0 );
		 break;

	  case TIPO_DEBE_SER_LOGICO:
		 IntroducirError( "La condici�n debe ser de tipo l�gico.",
								 TIPO_DEBE_SER_LOGICO, 0 );
		 break;

	  case VINICIAL_CONTADOR:
		 IntroducirError( "Se necesita un valor inicial para el contador.",
								 VINICIAL_CONTADOR, 0 );
		 break;

	  case VFINAL_CONTADOR:
		 IntroducirError( "Se necesita un valor final para el contador.",
								 VFINAL_CONTADOR, 0 );
		 break;

	  case INCREMENTO_CONSTANTE:
		 IntroducirError( "El incremento debe ser una constante real.",
								 INCREMENTO_CONSTANTE, 0 );
		 break;

	  case CONTADOR_REAL:
		 IntroducirError( "El valor del contador debe ser de tipo real.",
								 CONTADOR_REAL, 0 );
		 break;

	  case LIMITE_REAL:
		 IntroducirError( "El valor del l�mite para el contador debe ser de tipo real.",
								 LIMITE_REAL, 0 );
		 break;

	  case PARAMETRO_ILEGAL:
		 IntroducirError( "Los par�metros deben ser campos variables.", PARAMETRO_ILEGAL, 0 );
		 break;

	  case ILEGAL_NOMBRE_SUBPROGRAMA:
		 IntroducirError( "Ilegal nombre para un subprograma.", ILEGAL_NOMBRE_SUBPROGRAMA, 0 );
		 break;

	  case PARAMETRO_REPETIDO:
		 IntroducirError( ": Par�metro Repetido.", PARAMETRO_ILEGAL );
		 break;

	  case SUBPROGRAMA_NO_EXISTE:
		 IntroducirError( ": No se encontr� el Subprograma.", SUBPROGRAMA_NO_EXISTE );
		 break;
	  case SUBPROGRAMA_REPETIDO:
		 IntroducirError( ": Subprograma repetido.", SUBPROGRAMA_REPETIDO );
		 break;
	  case MUCHOS_ARGUMENTOS:
		 IntroducirError( ": Demasiados argumentos.", MUCHOS_ARGUMENTOS );
		 break;
	  case POCOS_ARGUMENTOS:
		 IntroducirError( ": Muy pocos argumentos.", POCOS_ARGUMENTOS );
		 break;

	  default:
		 IntroducirError( ": ERROR", ERROR_INDEFINIDO );
		 break;
	}
 }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 char *BuzonDeErrores::GetError(){

	if( !Inicio ){
	  char *ErrorFicticio= new char[6];
	  strcpy( ErrorFicticio, "Error" );
	  return ErrorFicticio;
   }
	char *Retorno= new char[strlen(Inicio->Info )+1];
	strcpy( Retorno, Inicio->Info );
	Vacear();
	return Retorno;

 }

 void BuzonDeErrores::Mostrar(){

	if( !Inicio )
	  return;
	HuboError= false;
	//Mensaje *Aux;
	//while( Inicio ){
	  if( Estado.Accion==EDICION )
		 VentanaPrincipal->MessageBox( Inicio->Info,
						"Error de revisi�n" , MB_ICONSTOP );
	  else
		 VentanaPrincipal->MessageBox( Inicio->Info,
						"Error en ejecuci�n", MB_ICONSTOP );

	  Vacear();
	/*
	  Aux= Inicio;
	  Inicio= Inicio->Sig;
	  delete[] Aux->Info;
	  delete Aux;

	}
	*/
 }

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

 BuzonDeErrores::~BuzonDeErrores(){

	Mensaje *Aux;
	while( Inicio ){
	  Aux= Inicio;
	  Inicio= Inicio->Sig;
	  delete[] Aux->Info;
	  delete Aux;
	}
	if( IdentificadorAsociado )
	  delete[] IdentificadorAsociado;
 }

#endif

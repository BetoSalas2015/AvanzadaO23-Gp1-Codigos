#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

//  Definicion del nodo
struct Nodo 
{ 
	char info;
	struct Nodo *sig;
};

typedef struct Nodo nodo;

nodo *raiz = NULL;				// Lista Vacia

//  Primitivas
void insert( char dato )
{
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  _No hay memoria
	{
		printf( "No hay memoria disponible\n");
		pausa;
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	if( raiz == NULL )
	{
		raiz = nuevo;
	}
	else 
	{
		nodo *recorre = raiz;
		while( recorre->sig != NULL )
			recorre = recorre -> sig;
		recorre -> sig = nuevo;

	}
	return;
}

void insert1( char dato )
{
	nodo *nuevo = NULL;
	nuevo = ( nodo *) malloc( sizeof( nodo ) );
	if( nuevo == NULL)     ///  _No hay memoria
	{
		printf( "No hay memoria disponible\n");
		pausa;
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = raiz;
	raiz = nuevo;
	return;
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while( recorre != NULL )
	{
		printf("%c, ", recorre->info);
		recorre = recorre -> sig;
	}
	NL;
}



int main()
{
	 imprimeLista();

	 insert1('R');
	 insert1('o');
	 insert1('b');
	 insert1('e');
	 insert1('r');
	 insert1('t');
	 insert1('o');

	 imprimeLista();

	 pausa;
 	 return 0;
}
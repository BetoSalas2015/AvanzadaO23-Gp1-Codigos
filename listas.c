#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define pausa system("pause")
#define cls system("cls")
#define NL putchar('\n')

// Prototipos
void insert( char dato );
void insert1( char dato );
void insertn( char dato, int pos );
char remueve();

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



void insertn( char dato, int pos )
{
	int cont;
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
	if( pos == 1)
	{
		nuevo ->sig = raiz;
		raiz = nuevo;
	}
	else 
	{
		nodo *recorre = raiz;
		cont = 1;
		while( recorre->sig != NULL && cont < pos - 1)
		{
			recorre = recorre -> sig;
			cont++;
		}
		nuevo ->sig = recorre ->sig;
		recorre -> sig = nuevo;

	}
	return;
}
char remueve()
{
	char dato;
	nodo *anterior = NULL, *siguiente = NULL;
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	if( anterior->sig == NULL)
	{
		raiz = NULL;
		dato = anterior->info;
		free(anterior);
		return dato;
	}
	else
	{
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
		}
		dato = siguiente ->info;
		anterior ->sig = NULL;
		free(siguiente);
		return dato;
	}
}

char remueve1()
{
	char dato;
	nodo *anterior = NULL;
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	raiz = raiz ->sig;
	dato = anterior->info;
	free(anterior);
	return dato;
}

char remuevn(int pos)
{
	char dato;
	nodo *anterior = NULL, *siguiente = NULL;
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return '\0';
	}
	anterior = raiz;
	if( anterior->sig == NULL)
	{
		raiz = NULL;
		dato = anterior->info;
		free(anterior);
		return dato;
	}
	else
	{
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
		}
		dato = siguiente ->info;
		anterior ->sig = NULL;
		free(siguiente);
		return dato;
	}
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

	 printf("Salió un %c\n", remueve()  );
	 printf("Salió un %c\n", remueve1()  );

	 imprimeLista();

	 pausa;
 	 return 0;
}
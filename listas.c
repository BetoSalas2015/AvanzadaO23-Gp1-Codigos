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

// Prototipos
nodo *insert( nodo *raiz, char dato );
void insert1( char dato );
void insertn( char dato, int pos );
char remueve();
char remueve1();
char remueven(int pos);
void imprimeLista();



nodo *raiz = NULL;	


//  Primitivas
nodo *insert( nodo *raiz, char dato )
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
	return raiz;
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


char remueven(int pos)
{
	char dato;
	nodo *anterior = NULL, *siguiente = NULL;
	 
	anterior = raiz;
	if( pos == 1)
	{
		raiz = raiz ->sig;
		dato = anterior->info;
		free(anterior);
		return dato;
	}
	else
	{
		int cont = 1;
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL && cont < pos -1)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
			cont++;
		}
		dato = siguiente ->info;
		anterior ->sig = siguiente ->sig;
		free(siguiente);
		return dato;
	}
}


void imprimeLista(nodo *raiz)
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
	nodo *nombre = NULL, *apellido = NULL; 
	 imprimeLista(nombre);

	 nombre = insert(nombre, 'R');
	 nombre = insert(nombre, 'o');
	 nombre = insert(nombre, 'b');
	 nombre = insert(nombre, 'e');
	 nombre = insert(nombre, 'r');
	 nombre = insert(nombre, 't');
	 nombre = insert(nombre, 'o');


	 apellido = insert(apellido, 'S');
	 apellido = insert(apellido, 'a');
	 apellido = insert(apellido, 'l');
	 apellido = insert(apellido, 'a');
	 apellido = insert(apellido, 'z');
	 apellido = insert(apellido, 'a');
	 apellido = insert(apellido, 'r');

	 imprimeLista(nombre);
	 imprimeLista(apellido);


	 pausa;
 	 return 0;
}
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
nodo *insert1( nodo *raiz, char dato );
nodo *insertn( nodo *raiz, char dato, int pos );
nodo *remueve(nodo *raiz, char *dato);
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

nodo *insert1( nodo *raiz, char dato )
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
	return raiz;
}



nodo *insertn( nodo *raiz, char dato, int pos )
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
	return raiz;
}


nodo *remueve(nodo *raiz, char *dato)
{
	
	nodo *anterior = NULL, *siguiente = NULL;
	if( raiz == NULL)
	{
		printf("Lista vacia, no hay nada que elimniar.\n");
		pausa;
		return NULL;
	}
	anterior = raiz;
	if( anterior->sig == NULL)
	{
		raiz = NULL;
		*dato = anterior->info;
		free(anterior);
		return raiz;
	}
	else
	{
		siguiente = anterior ->sig;
		while(siguiente -> sig != NULL)
		{
			anterior = anterior->sig;			// anterior = siguiente;
			siguiente = siguiente->sig;
		}
		*dato = siguiente ->info;
		anterior ->sig = NULL;
		free(siguiente);
		return raiz;
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
	//int javierHernandez;
	//int *chicharito;

	//chicharito = &javierHernandez;   //  creamos un alias (apodo)
	//*chicharito = 50;
	char dato;

	nodo *nombre = NULL, *apellido = NULL; 
	 imprimeLista(nombre);

	 nombre = insert(nombre, 'R');
	 nombre = insert(nombre, 'o');
	 nombre = insert(nombre, 'b');
	 nombre = insert(nombre, 'e');
	 nombre = insert(nombre, 'r');
	 nombre = insert(nombre, 't');
	 nombre = insert(nombre, 'o');


	 apellido = insert1(apellido, 'S');
	 apellido = insert1(apellido, 'a');
	 apellido = insert1(apellido, 'l');
	 apellido = insert1(apellido, 'a');
	 apellido = insert1(apellido, 'z');
	 apellido = insert1(apellido, 'a');
	 apellido = insert1(apellido, 'r');

	 apellido = remueve(apellido, &dato);
	 printf("El dato que salio fue; %c\n", dato);
	 nombre = remueve(nombre, &dato);
	 printf("El dato que salio fue; %c\n", dato);

	 imprimeLista(nombre);
	 imprimeLista(apellido);


	 pausa;
 	 return 0;
}
//Create for Cristian López Vázquez
//Bookstore
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

//Estructura de Tipo Nodo
struct nodo {
	int dato;
	struct nodo *sig;
}; 
struct nodo *inicio=NULL;

//Funcion para verificar un numero repetido
int busca (int v) {
	//Variables
	int f=1;
	struct nodo *ap;
	//Verificar el numero repetido
	while (ap!=NULL && ap->dato!=v) {
		ap=ap->sig;
	}
	if (ap!=NULL) {
		f=0;
	}
	return f;
}

//Funcion para insertar un numero en la lista
void inserta (int n) {
	//Llamada a la estructura con variables
	struct nodo *nuevo, *ap1, *ap2;
	int band=1;
	//Llamada a la funcion busca pasando la variable n
	band=busca(n);
	//Validacion para numero repetido
	if (band==1) {
		//Genera Nodo
		nuevo=new nodo; 
		/* Instruccion para Lenguaje en C, si marca error borrar el 1
		nuevo=(struct nodo*)malloc(1,sizeof(struct nodo));*/
		//Guardar la informacion 
		nuevo->dato=n;
		nuevo->sig=NULL;
		//Casos para inserta
		//Inicializar la lista
		if (inicio==NULL) {
		inicio=nuevo;
		}
		//Cambia el orden de la lista
		else if (n<inicio->dato) {
			nuevo->sig=inicio;
			inicio=nuevo;
		}
		else {
			//Apuntadores apuntan al inicion
			ap1=ap2=inicio;
			//Cambiar el orden de la lista
			while (ap1!=NULL && n>ap1->dato) {
				ap2=ap1;
				ap1=ap1->sig;
			}
			//Sigue guardando el orden establecido
			ap2->sig=nuevo;
			if (ap1!=NULL) {
				nuevo->sig=ap1;
			}
		}
	}
	else {
		cout<<"\n \t Lo Sentimos, El Numero Ingresado Ya Existe :( "<<endl;
	}	
}


int borra (int n) {
	int r=-1, band=1;
	struct nodo *ap1, *ap2;
	band=busca(n);
	if(band==0) {
		//Borra el principio de la fila
		if (n==inicio->dato) {
			ap1=inicio;
			r=ap1->dato;
			inicio=incio->sig;
			free(ap1);
		}
		else {
			ap1=ap2=incio;
			while(ap1->dato!=n) {
				ap2=ap1;
				ap1=ap1->sig;
			}
			r=ap1->dato;
			ap2->sig=ap1->sig;
			free(ap1);
		}
	}
	return r;
}

//Funcion para llamar a la funcion
void muestra (void) {
	struct nodo *ap;
	ap=inicio;
	cout<<"\n \t";
	while (ap!=NULL) {
		cout<<"\n \t "<<ap->dato<<", ";
		ap=ap->sig;
	}
	cout<<"\n \t ";
}

//Proceso Menu
void menu (void) {
	//Variables
	char op;
	int num, numr;
	//Menu
	do {
		cout<<"\n \t Lista Simple en Orden :V "<<endl;
		cout<<"\n \t (1) -> Insertar "<<endl;
		cout<<"\n \t (2) -> Borrar "<<endl;
		cout<<"\n \t (3) -> Mostrar Resultados "<<endl;
		cout<<"\n \t (4) -> Salir "<<endl;
		cout<<"\n \t Elige una opcion: ";
		cin>>op;
		//Casos
		switch (op) {
			//Caso 1 Insertar
			case '1': {
				cout<<"\n \t Captura un numero para insertar en la lista: ";
				cin>>num;
				//Llamada a la funcion insertar pasando la variable num
				inserta(num);
				break;
			}
			//Case 2 Borrar
			case '2': {
				cout<<"\n \t Captura el numero a borrar en la lista: ";
				cin>>num;
				//Llamada a la funcion borra para eliminar el numero
				numr=borra(num);
				//Validacion para encontrar el numero en la lista
				if (num!=numr) {
					cout<<"\n \t Lo sentimos, El numero capturado no se encuentra en la lista :( "<<endl;
				}
				break;
			}
			//Caso 3 Mostrar
			case '3': {
				//Llamada a la funcion mostrar
				muestra();
				break;
			}
		}
	}
	//Fin del Menu
	while (op!='4');
}

//Proceso Principal
main() {
	//Contenido
	cout<<"\n \t Programa: Lista Simple "<<endl;
	//Llamada a la funcion Menu
	menu();
	//Fin del Programa
	getch();
}
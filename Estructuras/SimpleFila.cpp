//Creado por Cristian Lopez Vazquez
//Bookstore
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct nodo {
	int dato;
	struct nodo *sig;
};
 
struct nodo *inicio=NULL;
 
int busca(int v)
{
	int f=1;
	struct nodo *ap;
	ap=inicio;
	while(ap!=NULL && ap->dato!=v)
	     ap=ap->sig;
	if(ap!=NULL)
	    f=0;
	return f;	    
}
 
void inserta(int n)
{
	struct nodo *nuevo, *ap1, *ap2;
	int band=1;
	band=busca(n);
	if(band==1)
	{
	   nuevo=new nodo; //nuevo=(struct nodo*) malloc (1, sizeof(struct nodo));
	   nuevo->dato=n;
	   nuevo->sig=NULL;
	   if(inicio==NULL)
	       inicio=nuevo;
	   else
	   if(n<inicio->dato)
	   {
	   	  nuevo->sig=inicio;
	   	  inicio=nuevo;
	   }
	   else
	   {
	   	  ap1=ap2=inicio;
	   	  while(ap1!=NULL && n>ap1->dato)
	   	  {
	   	    ap2=ap1;
			ap1=ap1->sig;	
		  }
		  ap2->sig=nuevo;
		  if(ap1!=NULL)
		      nuevo->sig=ap1;
	    }
    }
	else
	    cout<<"\n Lo Sentimos, El numero ya existe :(";      
}
 
int borra(int n)
{
	int r=-1, band=1;
	struct nodo *ap1, *ap2;
	band=busca(n);
	if(band==0)
	{
		if(n==inicio->dato)
	    {
	    	ap1=inicio;
	    	r=ap1->dato;
	    	inicio=inicio->sig;
	    	free(ap1);
		}
		else
		{
			ap1=ap2=inicio;
			while(ap1->dato!=n)
			{
				ap2=ap1;
				ap1=ap1->sig;
			}
			ap2->sig=ap1->sig;
			free(ap1);
		}
    }
	return r;
}
 
void muestra(void)
{
	struct nodo *ap;
	ap=inicio;
	cout<<"\n";
	while(ap!=NULL)
	{
		cout<<ap->dato<<", ";
		ap=ap->sig;
	}
	cout<<"\n";
}
 
void menu(void)
{
	char op;
	int num, r;
	do
	{
		cout<<"\nLista Simple En Orden";
		cout<<"\n1 - Inserta";
		cout<<"\n2 - Borra";
		cout<<"\n3 - Muestra";
		cout<<"\n4 - Salir";
		cout<<"\n\tOpcion ->";
		cin>>op;
		switch(op)
		{
			case '1': cout<<"\nDame el numero a Insertar: "; 
			          cin>>num;
			          inserta(num);
			          break;
			case '2': cout<<"\nQue numero desea borrar? ";
			          cin>>num;
					  num=borra(num);
					  if(num!=r)
					      cout<<"\n Lo sentimos, El numero no esta en la Lista :( \n";
					  break;
			case '3': muestra();		            
		}
	}
	while(op!='4');
}
 
main(void)
{
	menu();
}
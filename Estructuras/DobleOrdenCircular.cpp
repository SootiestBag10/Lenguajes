#include <iostream>

using namespace std;

struct nodo
{
	int dato;
	struct nodo *sig, *ant;
};

struct nodo *inicio=NULL;

int busca(int v)
{
	int f=0;
	struct nodo *ap;
	ap=inicio;
	if(ap!=NULL)
		do
		{
			if(ap->dato==v)
			    f=1;
			ap=ap->sig;
		}
	    while(ap!=inicio && f==0);
    return f;
}

void inserta(int n)
{
	struct nodo *nuevo, *ap1, *ap2;
	int band=1;
	band=busca(n);
	if(band==0)
	{
	   nuevo=new nodo;  //Puede ser "nuevo=(struct nodo*)malloc(1,sizeof(struct nodo));"
	   nuevo->dato=n;
	   if(inicio==NULL)
	   {   	
	      inicio=nuevo;
	      nuevo->sig=nuevo->ant=nuevo;
       }
       else
         if(n<inicio->dato)
         {  
            ap1=inicio;
			while(ap1->sig!=inicio)
			    ap1=ap1->sig;	        
       	    nuevo->sig=inicio;
       	    nuevo->ant=ap1;
       	    inicio->ant=nuevo;
       	    ap1->sig=nuevo;
       	    inicio=nuevo;
	     }
	     else
         {
       	    ap1=inicio->sig;
       	    ap2=inicio;
       	    while(ap1!=inicio && n>ap1->dato)
       	    {
       	  	    ap2=ap1;
       	  	    ap1=ap1->sig;
		    }
		    ap2->sig=nuevo;
		    nuevo->sig=ap1;
		    nuevo->ant=ap2;
		    ap1->ant=nuevo;
	     }
    }
    else
        cout<<"\nEl numero ya existe, cawn! \n";
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
			r=ap1->dato;
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
	do
	{
	    cout<<ap->dato<<", ";
	    ap=ap->sig;
	}
	while(ap!=inicio);
	cout<<"\n";
	ap=inicio->ant;
	do
	{
	    cout<<ap->dato<<", ";
	    ap=ap->ant;
	}
	while(ap!=inicio->ant);
	cout<<"\n";
}

void menu(void)
{
	char op;
	int num, r;
	do
	{
		cout<<"\nLISTA DOBLE EN ORDEN CIRCULAR :D";
		cout<<"\n1 - Inserta";
		cout<<"\n2 - Borra";
		cout<<"\n3 - Muestra";
		cout<<"\n4 - Salir";
		cout<<"\n\tOpcion -> ";
		cin>>op;
		switch(op)
		{
			case '1': cout<<"\nDame un numero: ";
			          cin>>num;
			          inserta(num);
			          break;
			case '2': cout<<"\nQue numero quieres borrar?: ";
			          cin>>num;
			          r=borra(num);
			          if(num!=r)
			             cout<<"\nEse numero no esta en la lista, cawn! \n";
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
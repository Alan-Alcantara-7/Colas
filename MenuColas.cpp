#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;
};

void menu();
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void suprimirCola(Nodo *&, Nodo *&, int &);
int main(){
	
	menu();

	return 0;
}

void menu(){
	int opc;
	int dato;
	Nodo *inicio = NULL;
	Nodo *fin = NULL;
	
	do{
		cout<<"\n.:::Menu:::."<<endl;
		cout<<"1.- Insertar dato a la cola"<<endl;
		cout<<"2.- Mostrar todos los elementos"<<endl;
		cout<<"3.- Salir"<<endl;
		cout<<"opcion:  ";
		cin>>opc;
		
		switch(opc){
			case 1: cout<<"\n Ingrese el dato para agregar: ";
			cin>>dato;
			insertarCola(inicio, fin, dato);
			
			break;
			case 2:
			cout<<"\n Mostrando los elementos de la cola:  "<<endl;
			while(inicio != NULL){
				suprimirCola(inicio, fin, dato);
				if (inicio != NULL){
					cout<<dato<<"  ,  ";
				}
				else{
					cout<<dato<<"...";
				}
			}
			system("pause");
			break;
			case 3: break;
				
		}
		system("cls");
	}while(opc != 3);
}

void insertarCola(Nodo *&inicio, Nodo *&fin, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(cola_vacia(inicio)){
		inicio = nuevo_nodo;	
	}
	else{
		fin->siguiente = nuevo_nodo;	
	}
	fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
	return (frente == NULL)? true : false;
}

void suprimirCola(Nodo *&inicio, Nodo *&fin, int &n){
	n = inicio->dato; 
	Nodo *aux = inicio;
	
	if (inicio == fin){
		inicio = NULL;
		fin = NULL;	
	}
	else{
		inicio = inicio->siguiente;
	}
	delete aux;
}

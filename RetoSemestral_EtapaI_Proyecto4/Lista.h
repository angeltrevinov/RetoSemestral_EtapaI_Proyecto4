//
//  Lista.h
//  ListasEncadenadas (Clase)
//
//  Created by Angel Trevino on 9/1/17.
//  Copyright © 2017 Angel Odiel Treviño Villanueva. All rights reserved.
//

#ifndef Lista_h
#define Lista_h

#include <iostream>

using namespace std;

template <class T> //nuevo tipo de dato gracias a templates

// este es para crear nodos
class Nodo{
public:
    //atributos
    T dato; //tipo de dato que vas a guardar
    Nodo <T> *pSig; // es un pointer que acepta el tipo de dato del template
    //constructores
    Nodo <T> (){ pSig=NULL; } //constructor que inicialisa un nodo vacio.
    Nodo <T> (T dato){ //constructor que recive el dato y agrega al final
        this->dato = dato;
        pSig = NULL;
    }
};

// este es para crear listas con varios nodos.
template <class T>
class Lista{
private:
    Nodo <T> *pInicio; //el apuntador que dice cual es el primer nodo de la lista
public:
    //constructor
    Lista(){//crea una lista vacia
        pInicio = NULL;
    }
    
    //metodo que inserta un nodo en la primer posicion
    void insertaInicio(T dato){
        Nodo <T> *pP = new Nodo <T>(dato);// crea apuntador a nuevo nodo
        pP->pSig = pInicio;
        pInicio = pP;
    }
    
    //metododo que inserta al final de la lista
    void insertaFinal(T dato){
        Nodo <T> *pQ = new Nodo <T> (dato); //que dato insertar
        Nodo <T> *pP = pInicio; //dato para encontrar al final
        
        if(pP == NULL){//por si la lista esta vacia
            insertaInicio(dato);
        }else{
            while(pP -> pSig != NULL){
                pP = pP -> pSig;
            }
            pP -> pSig = pQ;
        }
    }
    
    //Borrar el primer nodo de la lista, si existe
    void borraInicio(){
        if(pInicio != NULL){ //por si esta vacio para que no gastes memoria
            Nodo <T> *pP = pInicio;
            pInicio = pInicio -> pSig;
            delete pP;
        }
    }
    
    //Borra el ultimo nodo
    void borraFinal(){
        Nodo <T> *pP = pInicio;
        if( pP !=NULL && pInicio->pSig != NULL){ //varios Nodos
            Nodo <T> *pQ = NULL;
            while(pP -> pSig != NULL){
                pQ = pP;
                pP = pP -> pSig;
            }
            pQ -> pSig = NULL;
            delete pP;
        }else{
            borraInicio();
        }
    }
    
    
    //metodo que regresa el tamaño de modos
    int regresaTamanio(){
        int cont = 0;
        Nodo <T> *pP;
        pP = pInicio;
        while(pP != NULL){
            cont++;
            pP = pP -> pSig;
        }
        return  cont;
    }
    
    //metodo que muestra el contenido de la lista
    void muestra(){
        Nodo <T> *pP = pInicio; //pInicio nunca se mueve
        while(pP != NULL){
            cout << pP -> dato << " ";
            pP = pP -> pSig;
        }
        cout << endl;
    }
    
    //Invierte el contenido de la lista encadenada
    void reverse(){
        Nodo <T> *Aux = pInicio;
        Nodo <T> *Prev = NULL;
        
        while(pInicio != NULL){
            pInicio = pInicio -> pSig;
            Aux -> pSig = Prev;
            Prev = Aux;
            Aux = pInicio;
        }
        pInicio = Prev;
    }
    
    //hace un corrimiento de int casillas en la lista encadenada. Si int es 2, la cero pasa a ser la 2 , la 1 la 3 y así en forma circular. Si int es -1 la cero pasa a ser la última, la 1 la cero y así sucesivamente.
    void Shift(int Casillas){
        Nodo <T> *pAux = pInicio;
        if(Casillas > 0){//utilizar borrar al final e insertar al principio para los positivos
            for(int i = 0; i < Casillas; i++){
                while(pAux -> pSig != NULL){
                    pAux = pAux -> pSig;
                }
                borraFinal();
                insertaInicio(pAux -> dato);
            }
        }else if(Casillas < 0){// utilizar borrar al principio e insertar al final para negativos
            Casillas = Casillas*(-1);
            for(int i = 0; i < Casillas; i++ ){
                pAux = pInicio;
                borraInicio();
                insertaFinal(pAux -> dato);
            }
        }
    }
    
    //operator ==  : Revisa si dos listas encadenadas tienen el mismo contenido y en el mismo orden.
    bool igual(Lista <T> L){
        //utiliza el muestra
        Nodo <T> *pP = pInicio; //apuntador de la lista principal
        Nodo <T> *pQ = L.pInicio; //apuntador de la seguna lisa
        
        if(regresaTamanio() != L.regresaTamanio()){ //checa el tamaño
            return false;
        }
        
        while(pP != NULL && pQ != NULL){//checa el contenido
            if( pP -> dato != pQ -> dato){
                return false;
            }
            pP = pP -> pSig;
            pQ = pQ -> pSig;
        }
        
        return true;
    }
    
    //operator+= (LinkedList<T> l) : Apendiza toda la info de la lista endadenada l, al final de la lista encadenada.
    void operator+= (Lista <T> L){
        Nodo <T> *pAux = pInicio; //sabes donde esta el ultimo nodo
        Nodo <T> *pP = L.pInicio; // donde esta el primer nodo de la otra lista
        while(pAux -> pSig != NULL){//coloca pAux, en la ultima posicion de la lista
            pAux = pAux -> pSig;
        }
        while(pP != NULL){// va colocando uno por uno los datos de la lista L en la lista copy
            insertaFinal(pP -> dato);
            pP = pP -> pSig;
        }
    }
    
    //delete(int x, int y) = : borra x nodos a partir de la posición y. Debe validarse que haya suficientes nodos para borra a partir de la posición y. En caso de que x sea mayor a la cantidad de nodos que quedan a partir de la posición y se borran todos los que quedan.
    void deleteLista(int x, int y){// x borra la cantidad de nodos a partir de la posicion y
        Nodo <T> *pAux = pInicio; //auxiliar que busca la posicion del nodo donde se quiere borrar
        
        if(x < regresaTamanio()){
            for(int i = 0; i < x-1; x++){
                pAux = pAux ->pSig;
            }
        }else{
            cout <<"no hay suficientes nodos para borrar"<< endl;
        }
        //este ya es para borrar
        if(y < regresaTamanio()){
            Nodo<T> *borra;
            for(int i = 0; i < y; i++ ){
                borra = pAux ->pSig; //guarda cual se va a eliminar
                pAux = pAux -> pSig ->pSig; //pAux pasa al siguiente auxiliar
                delete borra; //borra la posicion eliminada
            }
        }else{
            for(int i = 0; i < regresaTamanio(); i++){
                borraInicio();
            }
            cout<< "entro";
        }
    }
    
    //copy constructor
    Lista <T>(const Lista<T> &L){
        pInicio = NULL;
        Nodo <T> *pP = L.pInicio;
        while(pP != NULL){
            insertaFinal(pP->dato);
            pP = pP -> pSig;
        }
    }
    
    //destructor
    ~Lista(){
        if(pInicio != NULL){//chec que la lista no esta vacia
            Nodo <T> *pP = pInicio;
            Nodo <T> *pQ;
            do{
                pQ = pP;
                pP = pP -> pSig;
                delete pQ;
            }while(pP != NULL);
            delete pP;
        }
    }
};

#endif /* Lista_h */

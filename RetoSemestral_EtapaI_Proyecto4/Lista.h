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
    
    
    //metodo que muestra el contenido de la lista
    void muestra(){
        Nodo <T> *pP = pInicio; //pInicio nunca se mueve
        while(pP != NULL){
            cout << pP -> dato << " ";
            pP = pP -> pSig;
        }
        cout << endl;
    }
    
    Nodo<T>* MergeLists(Nodo<T> *headA, Nodo<T> *headB){
        Nodo<T> * pP = headA;
        Nodo<T> * pQ = headB;
        while(pP != NULL && pQ != NULL){
            if(pQ -> data < pP -> data){ //este solo funciona si es el primero de la lista
                pQ -> pSig = pP;
            }else if(pQ -> data >= pP -> data ){ //funciona con todos los demas
                pQ -> pSig = pP -> pSig;
                pP -> pSig = pQ;
            }
            pP = pP -> pSig;
            pQ = pQ -> pSig;
        }//ese es del while
        return headA;
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
};

#endif /* Lista_h */

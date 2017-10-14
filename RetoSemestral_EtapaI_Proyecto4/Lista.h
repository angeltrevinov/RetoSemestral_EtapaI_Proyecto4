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
        Nodo<T> *pP; //esta es la temporar para mover los nodos
        if((headA==NULL)&&(headB==NULL)){//estan vacios
            return NULL;
        }else if((headA!=NULL)&&(headB==NULL)){//solo B esta vacio
            return headA;
        }else if((headA == NULL)&&(headB!=NULL)){//solo A esta vacio
            return headB;
        }else if(headA -> data < headB -> data){ // si el dato en A es menor que el dato B
            headA -> pSig = MergeLists(headA -> pSig, headB);
        }else if(headA -> data >= headB -> data){ //si el dato en A es mayor que el dato B
            pP = headB;//pP apunta al head de la lista B
            headB = headB-> pSig; //head de B se mueve al siguiente nodo
            pP -> pSig = headA; //pP apuntara al head de la listaA
            headA = pP; //headA se movera a pP
            headA-> pSig = MergeLists(headA-> pSig, headB); // se hace recursivamente
        }
            return headA;
    }
};

#endif /* Lista_h */

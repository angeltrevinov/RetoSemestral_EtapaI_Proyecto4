/*
    Angel Odiel Treviño Villanueva
    A01336559
    Estructura de Datos
    Reto Semestral
    MergeList
    *NOTA: solo necesitas la funcion mergelist dentro de la clase lista, tambien tienes que cambiar nombre de las variables para que hackerrank te acepte.
 */
#include <iostream>
#include "Lista.h"

int main() {
    
    Lista <int> L; //primera lista
    Lista <int> L2; //segunda lista
    L.insertaInicio(8);
    L.insertaInicio(5);
    L.insertaInicio(2);
    L.insertaInicio(3);
    L.muestra();
    L2.insertaInicio(9);
    L2.insertaInicio(7);
    L2.insertaFinal(4);
    L2.muestra();
    
    return 0;
}

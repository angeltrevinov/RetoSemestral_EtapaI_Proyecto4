//
//  ListasEncadenadas (Clase)
//  Angel Odiel Treviño Villanueva
//  A01336559
//  Estructura de Datos

#include <iostream>
#include "Lista.h"

int main() {
    
    Lista <int> L;
    L.insertaInicio(5);
    L.insertaInicio(2);
    L.insertaInicio(8);
    L.insertaFinal(3);
    L.muestra();
    cout << "El tamaño es " << L.regresaTamanio() << endl;
    /*L.borraInicio();
     L.borraFinal();
     L.muestra();*/
    Lista <int> copy(L);
    copy.muestra();
    copy.reverse();
    copy.Shift(-10);
    copy.borraFinal();
    if(copy.igual(L))
        cout << "son iguales" <<endl;
    else
        cout << "son diferentes" <<endl;
    copy.muestra();
    copy.operator+=(L);
    L.muestra();
    copy.muestra();
    //copy.deleteLista(3, 3); no me funciono
    
    return 0;
}

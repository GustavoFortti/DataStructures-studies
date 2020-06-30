#include <iostream>
#include <stdlib.h>
#include "Classifier.h"
#include "Funcionalidades.h"

int main (void)
{
    int size = 10;
    // std::cin >> size;
    int *vector; 
    vector = createVector(size); //função que gera numeros randomicos, para inserir na minha lista linear

    int option = 1;              // 1 bublesort, 2 ..., 3 ...
    // std::cin >> option;       // Entrada para o algoritimo
    
    ListaLinear<int> * LLE = new ListaLinear<int>();                   //declara lista como um objeto de numeros inteiros
    for (int i = 0; i < size; i++)
    {
        LLE->insert_first(*(vector + i));    // insere na lista
    }
    LLE->show();
    Classifier * sorter = new  Classifier(option);
    sorter->Sort(&LLE);

    LLE->show();
    std::cout << "\n\n";

    // LLE.dump();
}
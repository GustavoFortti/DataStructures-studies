#include "ListaLinear.h"
#include "iostream"

class Classifier
{
    public:
        static const int _BUBBLE_SORT    = 1;
        static const int _SELECTION_SORT = 2;
        static const int _INSERTION_SORT = 3;

        Classifier(int method);
        // virtual ~Classifier();
        Classifier(const Classifier& other);

        void Sort(ListaLinear<int> ** LLE);

    protected:
        int method;
        void BubleSort(ListaLinear<int> ** LLE);
        void SelectionSort(ListaLinear<int> ** LLE);
        void InsertionSort(ListaLinear<int> ** LLE);
        void swap(Node<int> ** first, Node<int> ** second, ListaLinear<int> ** LLE);
    private:
};

//Classifier.cpp
Classifier::Classifier(int method)
{
    if (method < _BUBBLE_SORT || method > _INSERTION_SORT)
    {
        throw "Methodo de ordenação nao suportado";
    }
    this->method = method;
}

// Classifier::~Classifier(ListaLinear<int> * LLE)  
// {
// }

Classifier::Classifier(const Classifier& other)
{
    //copy ctor
}

void Classifier::Sort(ListaLinear<int> ** LLE)
{
    switch (this->method)
    {
        case _BUBBLE_SORT : BubleSort(LLE);
            break;
        case _SELECTION_SORT : SelectionSort(LLE);
            break;
        case _INSERTION_SORT : InsertionSort(LLE);
    }
}

void Classifier::BubleSort(ListaLinear<int> ** LLE)
{
    
    Node<int>* Head = (*LLE)->Head();
    int size = (*LLE)->sizeList();
    (*LLE)->show();

    bool trocou = true;
    for (; trocou;) {
        Node<int> * first = Head, *second = NULL;
        trocou = false;
        for (size_t i = 0; i < size - 1; i++) {
            Node<int> * Verify = first->getNext(); 
            if (first->getValue() > Verify->getValue()) {
                swap(&first, &second, LLE);
                trocou = true;
            }
            else
            {
                second = first;
                first = first->getNext();
            }
            (*LLE)->show();
        }
        size--;
    }std::cout << "\n\n  Lista ordenada - BubleSort\n\n";
}

void Classifier::SelectionSort(ListaLinear<int> ** LLE)
{

}

void Classifier::InsertionSort(ListaLinear<int> ** LLE)
{

}

void Classifier::swap(Node<int> ** first, Node<int> ** second, ListaLinear<int> ** LLE)
{
    Node<int> * aux = (*first)->getNext();
    (*first)->setNext(aux->getNext());
    aux->setNext(*first);

    if (*second == NULL)
    {
        (*LLE)->setHead(aux);
        *second = aux;  
    } 
    else
    {
        (*second)->setNext(aux);
        *second = (*second)->getNext();
    }
}

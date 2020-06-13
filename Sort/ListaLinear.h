#ifndef _LISTALINEAR_H_
#define _LISTALINEAR_H_

template<class T>
class Node
{
    private:
        Node* next;

    public:
        T data;
        Node(T data) 
        {
            this->data = data;
            this->next = NULL;
        }

        T getValue() 
        {
            return data;
        }

        Node* getNext() 
        {
            return next;
        }

        void setNext(Node* nxt) 
        {
            next = nxt;
        }
};

template<class T>
class ListaLinear
{
    private:
        // Node<T> *tail; 
        Node<T> *head; 

    public:

        ListaLinear()
        {
            head = NULL;
            // tail = NULL;
        }

        ListaLinear(T data)
        {
            head = new Node<T>(data);
            // tail = head;
        }

        virtual ~ListaLinear() 
        {
            delete head;
        }

        Node<T> * Head()
        {
            return head;
        }

        void setHead(Node<T> * newNode)
        {
            head = newNode;
        }

        int sizeList()
        {
            if(Void())
                return 0;

            Node<T>* No = head;
            int size = 0;
            
            do
            {
                No = No->getNext();
                size++;
            } while(No);
            
            return size;
        }

        void show() 
        {
            Node<T>* No = head;
            std::cout << "  ";
            if(Void())
                 std::cout << "Não existe elementos\n";
            else
            {
                while(No) 
                {
                    std::cout << "[" << No->getValue() << "]->";
                    No = No->getNext();
                }
                std::cout << "NULL";
                std::cout << "\n";
            }
        }

        bool Void() 
        {
            return (head == NULL);
        }

        void insert_first(T data)
        {
            Node<T>* newNode = new Node<T>(data);

            newNode->setNext(head);
            head = newNode;
        }
};

#endif
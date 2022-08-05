#include <iostream>

using namespace std;

class Node
{
    public:
        int info;
        Node *next;

        Node ()
        {
            next=0;
        }

        Node (int el, Node *pr=0)
        {
            info=el;
            next=pr;
        }
};      

class Queue
{
    Node* head, *tail;

    public:
        Queue (){ head = tail =0;}

        void clearQ ();
        bool isEmpty ()
        {
            return (head==NULL);
        }
        void enqueue (int el);
        void dequeue ();
        int firstEl ();
        void printQueue ();
};

void Queue::clearQ ()
{
    Node *tmp=head;

    while (tmp!=NULL)
    {
        tmp=tmp->next;
        delete head;
        head=tmp;
    }

}

void Queue::enqueue (int el)
{
    if (tail!=0)
    {
        // Se a lista não estiver vazia
        tail->next=new Node (el);
        tail=tail->next;
    }
    else
    {
        head = tail = new Node (el);
    }
}

void Queue::dequeue ()
{
    if (!isEmpty ())
    {
        cout << "Elemento removido: " << firstEl();
        Node *tmp=head;
        
        if (head==tail) // Se há apenas um nó na lista
        {
            head=tail=0;
        }
        else
        {
            head = head -> next;
            delete tmp;
        }
    }
    else
    {
        cout << "\nLista vazia, nenhum elemento retirado!";
    }
}

int Queue::firstEl ()
{
    if (head==NULL)
    {
        cout << "\nFila vazia!";
        return -1;
    }
    else
    {
        return head->info;
    }
}

void Queue::printQueue ()
{
    Node *tmp=head;

    while (tmp!=NULL)
    {
        cout << "\n" << tmp->info;
    }
}

int main ()
{
    
}

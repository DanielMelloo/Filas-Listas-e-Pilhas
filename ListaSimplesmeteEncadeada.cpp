#include <iostream>

using namespace std;

//=================================================================================
// Definições da Lista
//=================================================================================

class NodeL
{
    public:
        NodeL ()
        {
            next=0;
        }
        NodeL (int el, NodeL *ptr=0)
        {
            info=el;
            next=ptr;
        }

        int info;
        NodeL *next;
};

class List
{
    public:
        List ()
        {
            head=tail=0;
        }
        int isEmpty ()
        {
            return head==0;
        }
        void addtoHead (int);
        void addToTail (int);
        int deleteFromHead (); // Deleta a head e retorna o seu valor
        int deleteFromTail (); //Deleta a tail e retorna o seu valor
        void deleteNode (int);
        bool isInList (int) const;

    private:
        NodeL *head, *tail;
};

int main ()
{
    
}

//=================================================================================
// Funções da Lista
//=================================================================================

void List::addtoHead (int el)
{
    head = new NodeL (el, head);
    
    if (tail==0)
    {
        tail=head;
    }
}

void List::addToTail (int el)
{
    if (tail!=0)
    { // Se não está vazia
        tail->next = new NodeL (el);
        tail=tail->next;
    }
    else 
    {
        head = tail = new NodeL (el);
    }
}

int List::deleteFromHead ()
{
    int el = head->info;

    NodeL *tmp=head;

    if (head==tail)
    {
        // Se há apenas 1 nó na lista
        head=tail=0;
    }
    else
    {
        head=head->next;
        delete tmp;
    }

}

int List::deleteFromTail ()
{
    int el=tail->info;

    if (head==tail)
    {
        // Se só há 1 nó na lista
        delete head;
        head=tail=0;
    }
    else
    {                  // Se mais de 1 nó está na lista
        NodeL *tmp;    // encontra o predecessor da tail
        for (tmp=head;tmp->next!=tail;tmp=tmp->next)
        delete tail;
        tail=tmp;      // O predecessor da tal se torna a tail
        tail->next=0;
    }

    return el;
}

void List::deleteNode (int el)
{
    if (head!=0)
    {
        if (head==tail && el==head->info)
        {
            // Se há apenas um nó na lista

            delete head;
            head=tail=0;
        }
        else if (el==head->info)
        {
            // Se há mais de um nó na lista
            NodeL *tmp=head;
            head=head->next;  
            delete tmp; // A antiga head é deletada
        }
        else
        {
            // Se há mais de um nó na lista
            NodeL *pred, *tmp;

            for (pred=head, tmp=head->next;     // e um nó diferente da head
                 tmp!=0 && !(tmp->info==el);    // é deletado
                 pred=pred->next, tmp->next);
                if (tmp!=0)
                {
                    pred->next=tmp->next;
                    if (tmp==tail)
                    {
                        tail=pred;
                        delete tmp;
                    }
                }
        }
    }
}

bool List::isInList (int el) const
{
    NodeL *tmp;

    for (tmp=head;tmp!=0 && !(tmp->info==el);tmp=tmp->next);
    return tmp!=0;
}
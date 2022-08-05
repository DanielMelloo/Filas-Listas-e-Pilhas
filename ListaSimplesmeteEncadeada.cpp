#include <iostream>

using namespace std;

//=================================================================================
// Defini��es da Lista
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
// Fun��es da Lista
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
    { // Se n�o est� vazia
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
        // Se h� apenas 1 n� na lista
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
        // Se s� h� 1 n� na lista
        delete head;
        head=tail=0;
    }
    else
    {                  // Se mais de 1 n� est� na lista
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
            // Se h� apenas um n� na lista

            delete head;
            head=tail=0;
        }
        else if (el==head->info)
        {
            // Se h� mais de um n� na lista
            NodeL *tmp=head;
            head=head->next;  
            delete tmp; // A antiga head � deletada
        }
        else
        {
            // Se h� mais de um n� na lista
            NodeL *pred, *tmp;

            for (pred=head, tmp=head->next;     // e um n� diferente da head
                 tmp!=0 && !(tmp->info==el);    // � deletado
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
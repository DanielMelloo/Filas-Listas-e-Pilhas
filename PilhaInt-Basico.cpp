#include <iostream>

using namespace std;

void testedecodigo ()
{
    cout << "bom dia" << endl;
}

class Node
{
    public:
        int info;
        Node *next;

        Node () { next=0; }

        Node (int el, Node *pr)
        {
            info=el;
            next=pr;
        }
};

class stack
{
    private:
        Node *head;
    public:
        stack () { head=0;}

        void clear ();
        bool isEmpty () { return (head==NULL);}

        void push (int el);
        void pop ();
        int popEl();
        void printstack();
        void preenchePilha (const int&);
        stack inverteElementos ();
        int qtdelementosPares ();
        void somadeImparePar  (int&, int&);
        bool comparaPilhas (stack*, stack*);
};

void stack::clear()
{
    Node *tmp=head;
    while (tmp !=NULL)
    {
        tmp=tmp->next;
        delete head;
        head=tmp;
    }
}

void stack::push (int el)
{
    head = new Node (el,head);
    head->info=el;
}

void stack::pop ()
{
    // cout << "\n Elemento removido" << popEl ();

    if (head!=NULL)
    {
        Node *tmp = head;
        head = head->next;
        delete tmp;
    }
}

int stack::popEl ()
{
    if (head==NULL)
    {
        cout << "\n Pilha vazia!";
        return -1;
    }
    else
    {
        return head->info;
    }
}

void stack::printstack ()
{
    Node *tmp=head;

    while (tmp!=NULL)
    {
        cout << "\n" << tmp->info;
        tmp = tmp->next;
    }

    cout << "\n";
}

void stack::preenchePilha (const int& n)
{
    for (int i=0;i<n;i++)
    {
        push (i);
    }
}
 
stack stack::inverteElementos ()
{
    stack p_tmp;

    Node *tmp=head;

    while (tmp!=NULL)
    {
        p_tmp.push (popEl ());
        tmp = tmp->next;
        pop ();
    }

    delete tmp;

    return p_tmp;
}

int stack::qtdelementosPares ()
{
    Node *tmp=head;

    int i=0;

    while (tmp!=NULL)
    {
        if (tmp->info%2==0 && tmp->info!=0)
        {
            i++;
        }

        tmp = tmp->next;
    }

    delete tmp;

    return i;
}

void stack::somadeImparePar (int& somapar, int& somaimpar)
{
    Node *tmp=head;

    while (tmp!=NULL)
    {
        if (tmp->info%2==0)
        {
            somapar=somapar + tmp->info;
        }

        else if (tmp->info%2!=0)
        {
            somaimpar=somaimpar + tmp->info;
        }

        tmp = tmp -> next;
    }

    delete tmp;

}

bool stack::comparaPilhas (stack *pa, stack *pb)
{
    Node *tmp=pa->head, *tmp2=pb->head;

    while (tmp!=NULL)
    {

        if (tmp->info!=tmp2->info)
        {
            return false;
        }
        
        tmp=tmp->next;
        tmp2=tmp2->next;
    }

    // while (tmp2!=NULL)
    // {

    //     if (tmp->info!=tmp2->info)
    //     {
    //         return false;
    //     }
        
    //     tmp=tmp->next;
    //     tmp2=tmp2->next;
    // }

    return true;
}

int main ()
{
    stack p1, p2, p3;

}


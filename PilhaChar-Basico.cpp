#include <iostream>

using namespace std;

void testedecodigo ()
{
    cout << "sim" << endl;
}

class Node
{
    public:
        // int info;
        char info;
        Node *next;

        Node () { next=0; }

        Node (char el, Node *pr)
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

        void push (char el);
        void pop ();
        char popEl();
        void printstack();
        void preenchePilha (const int&); //ta errado
        stack inverteElementos ();
        bool comparaPilhas (stack*, stack*);
        stack iguala ();
        bool palindromo();
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

void stack::push (char el)
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

char stack::popEl ()
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
    char l;

    for (int i=0;i<n;i++)
    {
        cout << "Informa a " << i+1 << " letra:\n";
        cin >> l;
        push (l);
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

stack stack::iguala()
{
    stack p_tmp;

    Node *tmp=head;
    
    while (tmp!=NULL)
    {       
        p_tmp.push (tmp->info);
        tmp = tmp->next;
    }

    p_tmp=p_tmp.inverteElementos();

    delete tmp;

    return p_tmp;
}

bool stack::palindromo()
{
    stack p_tmp;

    Node *tmp=head;
    
    while (tmp!=NULL)
    {       
        p_tmp.push (tmp->info);
        tmp = tmp->next;
    }

    delete tmp;

    if (comparaPilhas(&(*this), &p_tmp)==true)
    {
        testedecodigo();
        cout << "\n";
    }

    return true;
}

int main ()
{
    stack p1, p2, p3;

    int n;

    cout << "Quantas letras tem?\n" ;
    cin >> n;

    p1.preenchePilha (n);

    p2=p1.iguala();

    // p2=p2.inverteElementos();

    // cout << "\n\npilha 1";
    // p1.printstack();
    // cout << "\n";

    // cout << "pilha 2";
    // p2.printstack();
    // cout << "\n";

    // if (p1.comparaPilhas(&p1, &p2)==true)
    // {
    //     testedecodigo();
    //     cout << "\n";
    // }

    p1.palindromo ();

}

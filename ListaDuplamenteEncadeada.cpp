#include <iostream>

using namespace std;

class Node
{
    public:
        Node()
        {
            next=prev=0;
        }
        Node (int el, Node *n=0, Node *p=0)
        {
            info=el;
            next=n;
            prev=p;
        }
    int info;
    Node *next, *prev;
};

class Lista
{
    private:
        Node *head;
        Node *tail;

    public:
        Lista()
        {
            head=tail=0;
        }
        // ~Lista();
        int isEmpty()
        { 
            return head==0;
        }

        void AddToHead (int);
        void AddToTail (int);
        void AddToAny (const int& , const int& ); // adiciona um valor à uma posição informada
        void AddToCenter (const int& , const int& );

        int DeleteFromHead ();
        int DeleteFromTail ();
        void DeleteNodeV (int); // Deleta, se houver, o elemento que possui o valor informado
        void DeleteNodeP (int); // Deleta, se houver, o elemento na posição informada

        bool isInLista (int) const;
        void MaiorMenor (int& maior, int& menor);
        float Media ();
        void Concatena (Lista l2);
        void PrintLista ();
        int QtdElementos ();
};

int main ()
{
    
}

void Lista::AddToHead (int el)
{
    head = new Node (el, head);
    if (tail == 0)
    {
        tail=head;
    }
}

void Lista::AddToTail (int el)
{
    if (tail != 0)
    {
        tail->next=new Node (el);
        tail = tail->next;
    }
    else 
    {
        head = tail = new Node (el);
    }
}

void Lista::AddToAny (const int& num_el, const int& el) // >=2 elementos
{
    Node *tmp;

    int i=0;

    for ( tmp = head;
          tmp!=0 && i<num_el-1;
          tmp = tmp -> next); // Chega ao elemento anterior ao que será colocado
    
    tmp->next = new Node (el);


    if (tmp->next==tail)
    {
        tail=tmp->next;
    }

}

void Lista::AddToCenter (const int& qtd_el, const int& el)
{
    if (qtd_el>=2 && qtd_el%2==0)
    {
        AddToAny (qtd_el/2, el);
    }

}

int Lista::DeleteFromHead ()
{
    int el = head->info;
    Node *tmp=head;

    if (head == tail)
    {
        head = tail= 0;
    }
    else
    {
        head = head->next;
    }
    delete tmp;

    return el;
}

int Lista::DeleteFromTail ()
{
    int el=tail->info;

    if (head == tail)
    {
        delete head;
        head = tail = 0;
    }
    else
    {
        Node *tmp;

        for (tmp = head; tmp->next!= tail; tmp=tmp->next);
        
        delete tail;
        tail=tmp;
        tail->next=0;
    }

    return el;
}

void Lista::DeleteNodeV (int el)
{
    if (head != 0)
    {
        if (head == tail && el == head-> info)
        {
            delete head;
            head=tail=0;
        }
        else if (el == head->info)
        {
            Node *tmp = head;
            head=head->next;
            delete tmp;
        }
        else
        {
            Node *pred, *tmp;

            for (pred=head, tmp = head->next;
            tmp != 0 && !(tmp->info == el);
            pred=pred->next, tmp=tmp->next);

            if (tmp != 0)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                {
                    tail=pred;
                }
                delete tmp;
            }
        }
    }
}

void Lista::DeleteNodeP (int el) //não feito ainda
{
    if (head != 0)
    {
        if (head == tail && el == head-> info)
        {
            delete head;
            head=tail=0;
        }
        else if (el == head->info)
        {
            Node *tmp = head;
            head=head->next;
            delete tmp;
        }
        else
        {
            Node *pred, *tmp;

            for (pred=head, tmp = head->next;
            tmp != 0 && !(tmp->info == el);
            pred=pred->next, tmp=tmp->next);

            if (tmp != 0)
            {
                pred->next = tmp->next;
                if (tmp == tail)
                {
                    tail=pred;
                }
                delete tmp;
            }
        }
    }
}

bool Lista::isInLista (int el) const
{
    Node *tmp;
    for (tmp=head;
    tmp!=0 && !(tmp->info==el);
    tmp=tmp->next);

    return tmp!=0;
}

void Lista::MaiorMenor (int& maior,int& menor)
{
    int temp;

    if (maior<menor)
    {
        temp=maior;
        maior=menor;
        menor=temp;
    }
}

float Lista::Media ()
{
    Node *p = head;

    int soma=0, i=0;

    for (soma=0,i=0; p != NULL; p = p->next, i++)
    {
        soma=soma+(p->info);
    }

    return soma/i;
}

void Lista::Concatena (Lista l2)
{
    if (tail!=0) tail->next=l2.head;
    else head=l2.head;
}

void Lista::PrintLista()
{
    Node *p = head;
    while (p != NULL)
    {
        cout << "p->info=" << p->info << "\n\n";
        //cout << "\n p=" << p;
        //cout << "\n p->next=" << p->next;
        p = p->next;
    }
}

int Lista::QtdElementos ()
{
    int i=0;
    for (Node *p = head;p != NULL;p = p->next, i++);
    
    return i;
}

#include "linkedList.h"

mutex m;

linkedList::linkedList()
{
    head = NULL;
    tail = NULL;
}
//---------------------------To add new nodes to the linked list------------------------------------

void linkedList::addNode(int value)
{
    m.lock();

    if(head == NULL)
    {
        head = new node;

        head->data = value;
        head->next = NULL;
        tail=head;
    }
    else
    {
        node *x = new node;
        x->data = value;
        x->next =NULL;
        tail->next = x;
        tail = x;
    }
    m.unlock();
}


//-------------------------Displaying the linked list before removing any duplicate values--------------------

void linkedList::displayNodes()
{
    node *current = head;

    if(current == NULL)
        cout<<"List is empty"<<endl;
    else
    {
        int i=1;
        while(current != NULL)
        {
            cout<<"Node "<<i<<"->"<<current->data<<endl;
            i++;
            current = current->next;
        }
        cout<<endl;
        cout<<endl;
    }
}


//----------------------To remove duplicate value from the linked list---------------------------------

void linkedList::removeDuplicates()
{
    node *i, *j;

    i = head;
    while(i != NULL)
    {
        j = i;
        while((j != NULL)&&(j->next != NULL))
        {
            if(i->data == j->next->data)
            {
                node *t;
                t = j->next;
                j->next = j->next->next;
                delete[] t;

            }
            else
                j = j->next;
        }
        i = i->next;
    }
}

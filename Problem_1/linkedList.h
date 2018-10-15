#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#include <iostream>
#include <cstddef>
#include <mutex>


using namespace std;

class linkedList
{
        struct node
    {
        int data;
        node* next;
    };

    node *head;
    node *tail;
public:
    linkedList();
    void addNode(int);
    void displayNodes();
    void removeDuplicates();


};



#endif // LINKEDLIST_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "linkedList.h"

using namespace std;

int main()
{
    int choice;
    again:
        system ("CLS");
    int n;

    cout<<"Enter the size of the linked list: ";
    cin>>n;
    cout<<endl;

    linkedList list1;

    for(int i=1 ; i<=n ; i++)
    {
        int x;
        cout<<"Enter the value of node "<<i<<": ";
        cin>>x;
        cout<<endl;
        list1.addNode(x);
    }

    list1.displayNodes();
    list1.removeDuplicates();
    cout<<"After removing duplicates: "<<endl;
    list1.displayNodes();

    cout<<"Enter \'1\' to continue \'any other key\' to exit: "<<endl;
    cin>>choice;
    if(choice == 1)
        goto again;
    else
        exit(0);
}

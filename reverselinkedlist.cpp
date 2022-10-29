using namespace std;
#include <bits/stdc++.h>
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
 
struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }
 
    void reverse()
    {
        // Initialize current, previous and next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->next;
            // Reverse current node's pointer
            current->next = prev;
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }
 
    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
 
    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    /* Function to search for a data in linked list */
    void search(int key)
    {
        struct Node* temp = head;
        bool found= false;

        /* checking each node for matching data */
        while (temp != NULL)
         {
            if(temp->data == key)
            found=true;
            temp = temp->next;
        }

        if(found == true)
        cout << "Yes";

        else
        cout << "No";
    }
};
 
/* Driver code*/
int main()
{
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);
 
    cout << "Given linked list\n";
    ll.print();
 
    ll.reverse();
 
    cout << "\nReversed linked list \n";
    ll.print();

    cout << "\nIs 20 present in the linked list : ";
    ll.search(20);          //ll.search(*data to be searched goes here*);  

    cout << "\nIs 40 present in the linked list : ";
    ll.search(40);          //ll.search(*data to be searched goes here*);

    return 0;
}

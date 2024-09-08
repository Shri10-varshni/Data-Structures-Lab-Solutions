#ifndef WEBPAGE_H

#include<iostream>
using namespace std;

// Class for Doubly Linked List ADT
class list
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    };

    private:
        void deleterest();

    // Head (Points to the First Node) & Tail (Points to the Last Node)
    struct node *head, *current;
        
    public:
        list()
        {
            head = nullptr;        // Initializing head as NULL - Empty list
            current = head;
        }

        void displayCurrentPage();
        void displayAllPages();

        bool front();
        bool back();
        
        bool insertPage(int);

};

/*Moves to the Next Webpage (Moves Front)

    Return type: bool

    return{
        true => Move successful
        false => Empty Browser Tab || At first page
    }
*/
bool list::front(){
    if (head == nullptr){
        cout << "\nEmpty Browser Tab. ";
        return false;
    }
    else if (current->next != nullptr){
        current = current -> next;
        return true;
    }

    else{
        cout << "\nYou have already reached the Last Page. ";
        return false;
    }

}

/*Moves to the Previous Webpage (Moves Back)

    Return type: bool

    return{
        true => Move successful
        false => Empty Browser Tab || At last page
    }
*/
bool list::back(){
    if (head == nullptr){
        cout << "\nEmpty Browser Tab. ";
        return false;
    }
    else if (current->prev != nullptr){
        current = current -> prev;
        return true;
    }

    else{
        cout << "\nYou have reached the Last Page. ";
        return false;
    }
}

/*Displays the current Page the user is at

    Return type: void
*/
void list::displayCurrentPage(){
    cout << "\nCurrent Page: " << current->data;
}

/*Displays all the Valid Pages

    Return type: void
*/
void list::displayAllPages(){

    struct node *temp;
    temp = head;

    if(temp == nullptr){
        cout << "\nEmpty Browser Tab. ";
    }
    
    else{
        cout << "\nPages in Browser Tab: ";
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "End";
    }
}

/*Inserts Page at the immediate next Position in the Browser Tab

    Current is set to the inserted Page

    Deletes the rest of the Pages (func: list::deleterest())

    return {
        true  => Insertion Successful
        false => Failure in Memory Allocation
    }

*/
bool list::insertPage(int num) {

    struct node *newnode = new node;   // Memory allocation for NewNode to be inserted

    // Memory allocation Check
    if (newnode == nullptr) {
        cout << "\nMemory allocation failed. ";
        return false;
    }

    newnode->data = num;
    newnode -> next = nullptr;

    // Boundary condition - Empty List; Inserting the First Node
    if (head == nullptr){
        
        //In a circular linked list with a single element, current points to the only/ NewNode
        newnode -> prev = nullptr;
        // Single Node Condition
        head = newnode;
    }

    else{

        deleterest();

        newnode->prev = current;
        current->next = newnode;
    }

    current = newnode;
    return true;
}

/*Deletes all the pages following the Current Page

    Return type: void
*/
void list::deleterest(){

    struct node *temp = current->next;

    current->next = nullptr;

    while(temp!=nullptr){
        struct node *deletePage = temp;
        temp = temp->next;
        delete deletePage;
    }
}


#endif // WEBPAGE_H

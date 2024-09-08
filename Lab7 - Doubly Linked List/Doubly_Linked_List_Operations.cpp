#include<iostream>
using namespace std;

// Assumption - The list doesn't hold the value -1;

class list
{
    struct node
    {
        struct node *prev;
        int data;
        struct node *next;
    };

    // Head (Points to the First Node) & Tail (Points to the Last Node)
    struct node *head, *tail;
        
    public:
        list()
        {
            head = nullptr;        // Initializing head as NULL - Empty list
            tail = head;
        }

        void display();              // Time Complexity: O(n)
        
        void insertBeginning(int);   // Time Complexity: O(1)
        void insertEnd(int);         // Time Complexity: O(1)
        bool insertPos(int, int);    // Time Complexity: O(n)

        int deleteBeginning();       // Time Complexity: O(1)
        int deleteEnd();             // Time Complexity: O(1)
        int deletePos(int);          // Time Complexity: O(n)

        int search(int);             // Time Complexity: O(n)
        
        void displayReverse();       // Time Complexity: O(n)

};

void menu();

int main(){

    menu();

    list l;            // creating a list object (instance of "class: <list>")

    int choice;

    do{

        cout << "\n\nEnter choice: ";
        cin >> choice;
        
        switch(choice){

            case 1:
                {
                    int num;
                    cout << "\nEnter number: ";
                    cin >> num;

                    l.insertBeginning(num);
                    
                    cout << "Element Inserted in the Beginning successfully.\nYour updated list: ";
                    l.display();
    
                    break;
                }
            case 2:
                {
                    int num;
                    cout << "\nEnter number: ";
                    cin >> num;

                    l.insertEnd(num);
                    
                    cout << "Element Inserted in the End successfully.\nYour updated list: ";
                    l.display();
    
                    break;
                }
            case 3:
                {
                    int pos;
                    cout << "\nEnter position: ";
                    cin >> pos;

                    if (pos<0){
                        cout << "Invalid Position. Position must be a non-negative integer.";
                        break;
                    }

                    int num;
                    cout << "\nEnter number: ";
                    cin >> num;

                    bool result = l.insertPos(num, pos);

                    if (result){
                        cout << "Element Inserted at position " << pos << " successfully.\nYour updated list: ";
                        l.display();
                    }
                    else{
                        cout << "Insertion Unsuccessful.";
                    }

                    break;
                }
            case 4:
                {
                    int result = l.deleteBeginning();

                    if (result!=-1){
                        cout << "Element in the beginning deleted successfully.\nDeleted element: " << result << "\nYour updated list: ";
                        l.display();
                    }
                    else{
                        cout << "Deletion Unsuccessful.";
                    }

                    break;
                }
            case 5:
                {
                    int result = l.deleteEnd();

                    if (result!=-1){
                        cout << "Element in the End deleted successfully.\nDeleted element: " << result << "\nYour updated list: ";
                        l.display();
                    }
                    else{
                        cout << "Deletion Unsuccessful.";
                    }

                    break;
                }
            case 6:
                {
                    int pos;
                    cout << "\nEnter position: ";
                    cin >> pos;

                    if (pos<0){
                        cout << "Invalid Position. Position must be non-negative.";
                        break;
                    }

                    int result = l.deletePos(pos);

                    if (result != -1){
                        cout << "Element at position " << pos << " has beeen deleted successfully.\nDeleted Element: " << result << "\nYour updated list: ";
                        l.display();
                    }
                    else{
                        cout << "Deletion Unsuccessful.";
                    }

                    break;
                }
            case 7:
                {
                    int element;
                    cout << "\nEnter element: ";
                    cin >> element;
                    
                    int index = l.search(element);
                    
                    if (index != -1){
                        cout << "The element is found at the index " << index << "\n";
                    }
                    
                    else{
                        cout << "Element not found.";
                    }
                    
                    break;
                }
            case 8:
                {
                    l.display();
                    break;
                }
            case 9:
                {
                    l.displayReverse();
                    break;
                }
            case 10:
                {
                    cout << "Exiting Program.";
                    break;
                }
            default:
                cout << "Invalid Choice.\n";
        }
    }
    while(choice!=10);
    
    return 0;
}

/*Displays the available operations in Doubly Linked List ADT Implementation

    Return type: void
*/
void menu(){
    cout << "\n\n----Doubly Linked List ADT Implementation----\n\n";
    cout << "1 - Insert in Beginning\n";
    cout << "2 - Insert in End\n";
    cout << "3 - Insert at a position\n";
    cout << "4 - Delete in Beginning\n";
    cout << "5 - Delete in End\n";
    cout << "6 - Delete at a position\n";
    cout << "7 - Search Element\n";
    cout << "8 - Display\n";
    cout << "9 - Display Reverse\n";
    cout << "10 - Exit\n\n";
}

/* Displays the Doubly linked list in the forward direction

    Format: Head -> {Nodes} -> Tail

    Return type: void
*/
void list::display(){
    struct node *temp;
    temp = head;

    if(temp == nullptr){
        cout << "Empty Doubly Linked List.\n";
    }
    
    else{
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

/*Inserts Node in the beginning of the Circular Linked List
    
    Return type: void
*/
void list::insertBeginning(int num){

    struct node *newnode = new node;   // Memory allocation for NewNode to be inserted
    
    // Memory allocation Check
    if (newnode == nullptr) {
        cout << "Memory allocation failed.\n";
        return;
    }

    // Populating NewNode -> Data with the given number & NewNode -> Prev with nullptr (FirstNode)
    newnode->data = num;
    newnode -> prev = nullptr;      

    // Boundary condition - Empty List; Inserting the First Node
    if (head == nullptr){
        
        //In a circular linked list with a single element, Tail points to the only/ NewNode
        tail = newnode;

        // Single Node Condition
        newnode -> next = nullptr;
    }

    else{

        // NewNode -> Next points to the first element in existing DLL 
        newnode -> next = head;
        head -> prev = newnode;
    }

    head = newnode;                 // Head points to the NewNode since it is inserted in the beginning

}

/*Inserts Node at the End of Doubly Linked List
    
    Return type: void
*/
void list::insertEnd(int num){

    struct node *newnode = new node;   // Memory allocation for NewNode to be inserted

    // Memory allocation Check
    if (newnode == nullptr) {
        cout << "Memory allocation failed.\n";
        return;
    }

    newnode->data = num;
    newnode->next = nullptr;

    // Boundary condition - Empty List; Inserting the First Node
    if (head == nullptr){

        // Single Node Conditions
        head = newnode;
        newnode -> prev = nullptr;
    }

    else{
        tail -> next = newnode;     // Forward Link Condition
        newnode -> prev = tail;     // Reverse Link Condition
    }

    tail = newnode;                 // Tail points to the NewNode since it is inserted in the End
}

/*Inserts Node at the given position(index) in the Doubly Linked List

    Note: Indexing starts from '0'

    Return type: bool

    return {
        true  => Insertion Successful
        false => Position out of bounds || Failure in Memory Allocation
    }
*/
bool list::insertPos(int num, int pos) {

    struct node *newnode = new node;   // Memory allocation for NewNode to be inserted

    // Memory allocation Check
    if (newnode == nullptr) {
        cout << "Memory allocation failed.\n";
        return false;
    }

    newnode->data = num;

    // Boundary Condition - Insertion at the beginning of the list
    if (pos == 0) {
        insertBeginning(num);
        return true;
    }

    // Boundary condition - Trying to insert at an invalid position in an Empty list
    else if( pos != 0 && head == nullptr){
        cout << "Position out of bounds. ";         // Error message
        return false;
    }
    
    else {

        // Temporary Node pointer to Traverse the list
        struct node *current = head;

        // Traversal until current reaches the Node Position after which the NewNode is to be inserted
        int index; 
        for (index = 1; index < pos && current != tail; index++) {
            current = current->next;
        }
        
        // Boundary Condition - Insertion of element in an invalid position (pos > sizeoflist)
        if (index<pos) {
            cout << "Position out of bounds. ";      // Error message
            return false;
        }

        newnode->next = current->next;      // Forward Link Condition
        
        // Boundary Condition - Updation of Tail in case of Insertion at the End
        if (current == tail){
            tail = newnode;
        }
        
        else{
            current->next->prev = newnode;  // Reverse Link Condition
        }
        
        current->next = newnode;            // Forward Link Condition
        newnode->prev = current;            // Reverse Link Condition
    
        return true;
    }
}

/*Deletes the First Node of Doubly Linked List

    return {
        -1   => Empty List || Deletion Unsuccessful
        :int => Integer stored in Deleted Node
    }
*/
int list::deleteBeginning(){

    // Boundary condition - Empty List
    if (head == nullptr){
        cout << "Empty Doubly Linked List. ";
        return -1;
    }

    // Boundary Condition - Deleting the only Node in the List
    else if(head == tail){
        
        int deletedNum = head->data;

        delete head;          // Deletion by freeing the memory of Deleted Node

        // Empty List conditions
        head = nullptr;
        tail = nullptr;

        return deletedNum;
    }

    else{
        
        struct node *deleteNode = head; 
        int deletedNum = deleteNode->data;
    
        head = head->next;          // Head needs to point to the new First Node since the deletion occurs in the beginning
        head->prev = nullptr;       // Reverse Link Condition for Head
        
        delete deleteNode;           // Deletion by freeing the memory of Deleted Node

        return deletedNum;
    }
    
}

/*Deletes the Last Node of Doubly Linked List

    return {
        -1   => Empty List || Deletion Unsuccessful
        :int => Integer stored in Deleted Node
    }
*/
int list::deleteEnd(){
    
    // Boundary condition - Empty List
    if (head == nullptr){
        cout << "Empty Doubly Linked List. ";
        return -1;
    }

    // Boundary Condition - Deleting the only Node in the List
    else if(head == tail){

        int deletedNum = tail->data;

        delete tail;           // Deletion by freeing the memory of Deleted Node

        // Empty List conditions
        head = nullptr;
        tail = nullptr; 

        return deletedNum;          

    }

    else{

        struct node *deleteNode = tail; 
        int deletedNum = deleteNode->data;

        tail = tail->prev;      // Tail needs to point to the new Last Node since the deletion occurs in the End
        tail->next = nullptr;   // Forward Link Condition for Tail
        
        delete deleteNode;       // Deletion by freeing the memory of Deleted Node

        return deletedNum;
    } 

    return -1;
}

/*Deletes the Node at given position(index)

    Note: Indexing starts from '0'

    return {
        -1   => Empty List || Position Out of Bounds 
        :int => Integer stored in Deleted Node   
    }
*/
int list::deletePos(int pos) {

    // Boundary Condition - Empty List
    if (head == nullptr) {

        cout << "Empty Doubly Linked List. ";
        return -1;
    }

    // Boundary Condition - Deletion in the beginning
    if (pos == 0) { 
        return deleteBeginning();
    }

    struct node *current = head;
    
    int index = 0;
    
    // Traversal until DeleteNode 
    while (index < pos && current != tail) {   
        current = current->next;
        index++;
    }
    
    // Boundary Condition - Deletion of element in an invalid position (pos > sizeoflist)
    if (index<pos) {
        cout << "Position out of bounds. ";      // Error message
        return -1;
    }

    // Boundary Condition - Deletion at the end
    if (current == tail){
        return deleteEnd();
    }

    // Perform the deletion
    int deletedNum = current->data;

    current->prev->next = current->next;    // Forward Link Condition
    current->next->prev = current->prev;    // Reverse Link Condition
    
    delete current;
    
    return deletedNum;
}

/*Searches for the first occurrence of an element in the Doubly Linked List

    return {
        -1 => Empty List || Element not Found
        :int => index of the first occurrence of the element
    }
*/
int list::search(int element){

    // Boundary Condition - Empty List
    if (head == nullptr) { 
        cout << "Empty Doubly Linked List. ";
        return -1;
    }

    struct node *current = head;    // Temporary Node pointer to Traverse the list

    int index = 0;
    
    // Traverse the list until the node just before the one we want to delete
    while (current != nullptr) {

        if (current-> data == element){
            return index;
        }
        current = current->next;
        index++;
    }

    return -1;
}

/* Displays the Doubly linked list in the reverse direction

    Format: Tail -> {Nodes} -> Head

    Return type: void
*/
void list::displayReverse(){
    
    struct node *temp;
    temp = tail;
    
    if(temp == nullptr){
        cout << "Empty Doubly Linked List.\n";
    }
    
    else{
        while(temp != nullptr){
            cout << temp->data << " -> ";
            temp = temp->prev;
        }
        cout << "nullptr\n";
    }
}

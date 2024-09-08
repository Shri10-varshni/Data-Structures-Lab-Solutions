#include<iostream>
#include "WebPage.h"

using namespace std;

void menu();

int main(){
    list l;            // creating a list object (instance of "class: <list>")
    int choice;
    do{
        menu();
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                {
                    int num;
                    cout << "\nEnter WebPage Title (integer): ";
                    cin >> num;
                    bool result = l.insertPage(num);
                    if (result){
                        cout << "\nWebpage Inserted Successfully.";
                        l.displayCurrentPage();
                    }
                    else{
                        cout << "Couldn't insert WebPage.";
                    }
                    
                    break;
                }
            case 2:
                {
                    bool result = l.front();
                    if (result){
                        cout << "\nMoved Front Successfully.";
                        l.displayCurrentPage();
                    }
                    
                    else{
                        cout << "Cannot move Front.";
                    }
                    break;
                }
            case 3:
                {
                    bool result = l.back();
                    if (result){
                        cout << "\nMoved Back Successfully.";
                        l.displayCurrentPage();
                    }
                    
                    else{
                        cout << "Cannot move Back.";
                    }
                    break;
                }
            case 4:
                {
                    l.displayAllPages();
                    break;
                }
            case 5:
                {
                    cout << "\nExiting Program.";
                    break;
                }
            default:
                cout << "\nInvalid Choice.";
        }
    }
    while(choice!=5);
    
    return 0;
}

void menu(){
    cout << "\n\n----Browser Tab Navigation Implementation----\n";
    cout << "1 - Insert WebPage\n";
    cout << "2 - Move Front\n";
    cout << "3 - Move Back\n";
    cout << "4 - Display all Pages\n";
    cout << "5 - Exit\n\n";
}

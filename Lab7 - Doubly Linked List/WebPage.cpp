#include<stdio.h>
#include<stdlib.h>

#include "WebPage.h"

void menu();

int main(){
    list l;            // creating a list object (instance of "class: <list>")

    int choice;

    do{

        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice){

            case 1:
                {
                    int num;
                    printf("\nEnter WebPage Title (integer): ");
                    scanf("%d", &num);

                    bool result = l.insertPage(num);

                    if (result){
                        printf("\nWebpage Inserted Successfully.");
                        l.displayCurrentPage();
                    }
                    else{
                        printf("Couldn't insert WebPage.");
                    }
                    
                    break;
                }
            case 2:
                {
                    bool result = l.front();

                    if (result){
                        printf("\nMoved Front Successfully.");
                        l.displayCurrentPage();
                    }
                    
                    else{
                        printf("Cannot move Front.");
                    }

                    break;
                }
            case 3:
                {
                    bool result = l.back();

                    if (result){
                        printf("\nMoved Back Successfully.");
                        l.displayCurrentPage();
                    }
                    
                    else{
                        printf("Cannot move Back.");
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
                    printf("\nExiting Program.");
                    break;
                }
            default:
                printf("\nInvalid Choice.");
        }
    }
    while(choice!=5);
    
    return 0;
}

void menu(){
    printf("\n\n----Browser Tab Navigation Implementation----\n");
    printf("1 - Insert WebPage\n");
    printf("2 - Move Front\n");
    printf("3 - Move Back\n");
    printf("4 - Display all Pages\n");
    printf("5 - Exit\n\n");
}




#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "linked_list.h"

void process_user_input(){
    while (1){
        printf("1 - Add new Node\n");
        printf("2 - Show the whole List\n");
        printf("3 - Insert a new Node\n");
        printf("4 - Delete a Node\n");
        printf("5 - Save List on Harddrive\n");
        printf("6 - Load List from Harddrive\n");
        char option;
        int user_input;
        scanf(" %c", &option);
        switch(option){
            case '1':
                printf("Enter Number you want to add: \n");
                int result;
                printf("Number: ");
                result = scanf("%d", &user_input);
                if (result == 0) {
                    printf("Not a number\n");
                    break;
                }
                add(user_input);
                scanf("%*[^\n]");
                break;
            case '2':
                show_list();
                break;
            case '3':
                printf("Enter Number you want to add: \n");
                scanf("%d", &user_input);
                int nodeData;
                printf("Enter the Data of the Node, where you want to insert your node after: \n");
                scanf("%d", &nodeData);
                Node* ins = insert(user_input, nodeData);
                if (ins == NULL) 
                    printf("Can not find a Node with the data: %d\n", nodeData);
                break;
            case '4':
                printf("Enter Number you want to remove: \n");
                scanf("%d", &user_input);
                Node* removed;
                removed = removeNode(user_input);
                if (removed == -1)
                    printf("Can not find an Element with this data: %d\n", user_input);
                break;
            case '5':
                int list = save_list();
                if (list == 0){
                    printf("List sucessfully saved\n");
                } else if (list == -1) {
                    printf("You can not store an empty list\n");
                } else if (list == -2) {
                    printf("Folder or File not found ./data/test.txt \n");
                }
                break;
            case '6':
                load_list();
                break;
            default:
                printf("Wrong Input. Please try again.\n\n");
                break;
        }
    }
}

int main(){
    process_user_input();
    return 0;
}


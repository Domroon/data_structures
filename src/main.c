#include <stdio.h>
#include "linked_list.h"

void process_user_input(){
    while (1){
        printf("1 - Add new Node\n");
        printf("2 - Show the whole List\n");
        printf("3 - Insert a new Node\n");
        printf("4 - Delete a Node\n");
        char option;
        int user_input;
        scanf(" %c", &option);
        switch(option){
            case '1':
                printf("Enter Number you want to add: \n");
                scanf("%d", &user_input);
                add(user_input);
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
                insert(user_input, nodeData);
                break;
            case '4':
                printf("Enter Number you want to remove: \n");
                scanf("%d", &user_input);
                removeNode(user_input);
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


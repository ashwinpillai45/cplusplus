#include <iostream>
#include <stdint.h>

/*Structure of a node*/
struct node {
    uint8_t value;
    struct node * nextNode; 
};

/*Linked list operations*/
class linked_list{
    struct node* head = nullptr;
    public:
        
        /*Returns the next node address pointed by the last node */
        struct node* last_value(){
            struct node* ptr=head;
            while(ptr->nextNode==nullptr){
                ptr=ptr->nextNode;
            }
            return ptr->nextNode;
        }

        /*Create a new node and also check if the new node is the first node. Returns the pointer to the new node created*/
        struct node* create_node(uint8_t value){
          struct node* ptr = (struct node*)std::malloc(sizeof(struct node));
           if(head==nullptr){
                head=ptr;
                return ptr;
            }
          struct node* ptr1=last_value();
          ptr=ptr1;
          ptr->value = value;
          ptr->nextNode = nullptr;
          return ptr;
        }

        /*Go through linked list until it matches the value*/
        struct node* search_value(uint8_t value){
            struct node* ptr=head;
            struct node* address_array=(struct node*)malloc(3*sizeof(struct node*));
            while(ptr->value!=value){
                ptr=ptr->nextNode;
            }
            return address_array;
        }

        /*Delete the head node*/
        void delete_head(){

        }

        /*Delete the first node with the value*/
        void delete_node(uint8_t value){
            if(value==head->value){
                std::cout << "You are deleting value from head" <<std::endl;
                delete_head();
                return;
            }
            struct node* ptr = search_value(value);
            free(ptr);
        }

        void print_linked_list();
        void delete_linked_list();
};

int main(){
    linked_list ll;

    return; 
}
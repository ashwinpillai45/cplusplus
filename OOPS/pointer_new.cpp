#include <iostream>
#include <stdint.h>

/*Structure of a node*/
struct node {
    uint8_t value;
    struct node * nextNode; 
};

/*Linked list operations*/
class linked_list{
    struct node* head = nullptr;                //this the main variable that points to the head

    /*Returns the next node address pointed by the last node */
    struct node* last_value(){
    struct node* ptr=head;
    while(ptr->nextNode!=nullptr){               //go through the linked list and return the pointer to the last node
        ptr=ptr->nextNode;
        }
    return ptr;
    }

    public:
        /*Create a new node and also check if the new node is the first node. Returns the pointer to the new node created*/
        void create_node(uint8_t value1){
          struct node* ptr = new struct node;
          ptr->value=value1;
          ptr->nextNode=nullptr;
           if(head==nullptr){
                head=ptr;
                head->value=ptr->value;
                head->nextNode=ptr->nextNode;
                return;
            }
          struct node* ptr1=last_value();
          ptr1->nextNode=ptr;
        }

        /*Delete the entire linked list*/
        void delete_linked_list(){
            struct node* ptr = head;
            struct node* ptr1 = ptr;
            while(ptr1->nextNode!=nullptr)                          //go through the linked list and delete all the nodes from head to last value
            {
                ptr1=ptr->nextNode;
                delete ptr;
                ptr=ptr1;
            }
            delete ptr;
            return;
        }

        /*Delete the head node*/
        void delete_head(){
            struct node* ptr=head;
            if(head->nextNode==nullptr){                            //check if the head is the only node. in that case it deletes the entire node
                delete_linked_list();
                return;
            }
            head=head->nextNode;
            delete ptr;
            return;
        }

        /*Delete the first node with the value*/
        void delete_node(uint8_t value){
            if(value==head->value){                                                 //if the value to be deleted is head then use delete_node
                std::cout << "You are deleting value from head" <<std::endl;
                delete_head();
                return;
            }
            struct node* ptr=head->nextNode;
            struct node* ptr1=head;
            while(ptr->value!=value){                                               //go through the linked list and stop at the first instance
                ptr1=ptr;
                ptr=ptr->nextNode;
            }
            ptr1->nextNode=ptr->nextNode;
            delete ptr;
        }

        /*Print the entire linked list*/
        void print_linked_list(){
            struct node* ptr=head;
            while(ptr->nextNode!=nullptr){                                          //go through the linked list and print all the values in the node
                std::cout << static_cast<int>(ptr->value) << "\t";
                ptr=ptr->nextNode;
            }
            std::cout << static_cast<int>(ptr->value)<<std::endl;
            return;
        }
};

int main(){
    linked_list ll;
    ll.create_node(23);
    ll.create_node(45);
    ll.create_node(78);
    ll.create_node(103);
    ll.create_node(89);
    ll.create_node(99);
    ll.print_linked_list();
    ll.delete_head();
    ll.print_linked_list();
    ll.delete_node(45);
    ll.print_linked_list();
    ll.delete_node(89);
    ll.print_linked_list();
    ll.delete_linked_list();
    return 0;
}
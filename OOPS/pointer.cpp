#include <iostream>
#include <stdint.h>

struct node {
    uint8_t value;
    struct node * nextNode; 
};

class linked_list{
    struct node* head;
    struct node* create_node();
    struct node* delete_node();
    void print_linked_list(); 
    public:

};

int main(){
    
    return; 
}
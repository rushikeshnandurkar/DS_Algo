#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
    int data;
    struct node* next;
}node;

node* insert(node*);
node* reverse_list(node*);
node* get_node();
void print_list(node*);

int main()
{
    // head node which is null at this time
    node* head = NULL;

    head = insert(head);
    head = insert(head);
    head = insert(head);
    head = insert(head);
    head = insert(head);
    print_list(head);

    head = reverse_list(head);
    printf("After reverse: \n");
    print_list(head);
    return 0;
}

node* insert(node* head)
{
    int num;
    node* temp = get_node();
    printf("Enter new data: ");
    scanf("%d", &num);
    temp->data = num;
    if (head == NULL)
    {
        return temp;
    }
    node* p = head;
    while(p->next != NULL)
        p = p->next;
    
    p->next = temp;
    return head;
}

node* get_node()
{
    node* temp = (node*) malloc(sizeof(node));
    temp->next = NULL;
    return temp;
}


void print_list(node* head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->next;
    }
    printf("\n");
    
}

node* reverse_list(node* head)
{
    node* current = head;
    node* ahead = current;
    node* prev = NULL;

    // logic starts
    while(current != NULL)
    {
        ahead = current->next;
        current->next = prev;
        prev = current;
        current = ahead;
    }
    head = prev;
    return head;
}
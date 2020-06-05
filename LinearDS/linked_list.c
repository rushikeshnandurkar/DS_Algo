#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *append(node *);
node *front(node *);
node *middle(node *);
node *delete_node(node *);
void print_list(node *);
node *create_node();

int main()
{

    node *head = NULL;
    while (1)
    {
        printf("1. Append\n2. Insert at beginning\n3. Insert at middle\n4. Delete\n5. Print List\nEnter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            head = append(head);
            break;
        case 2:
            head = front(head);
            break;
        case 3:
            head = middle(head);
            break;
        case 4:
            head = delete_node(head);
            break;
        case 5:
            print_list(head);
            break;

        default:
            exit(0);
        }
    }
    return 0;
}

node *create_node()
{
    int temp_data;
    printf("Enter data to be inserted: ");
    scanf("%d", &temp_data);

    node *temp = (node *)malloc(sizeof(node));
    temp->data = temp_data;
    temp->next = NULL;
}

node *append(node *head)
{
    node *temp = create_node();

    if (head == NULL)
    {
        return temp;
    }

    node *p;
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;

    return head;
}

node *front(node *head)
{
    node *temp = create_node();
    temp->next = head;
    return temp;
}

node *middle(node *head)
{
    node *temp = create_node();
    int pos;
    printf("Enter the position of new node: ");
    scanf("%d", &pos);

    node *ptr = head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }

    temp->next = ptr->next;
    ptr->next = temp;

    return head;
}

node *delete_node(node *head)
{
    int pos;
    printf("Enter the index of node to be removed: ");
    scanf("%d", &pos);

    node *ptr = head;
    node *p;

    if (pos == 0)
    {
        head = head->next;
        free(ptr);
        return head;
    }
    for(int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }

    p = ptr->next;
    ptr->next = p->next;
    free(p);
    return head;
}

void print_list(node *h)
{
    while (h != NULL)
    {
        printf("%d -> ", h->data);
        h = h->next;
    }
    printf("NULL\n");
}
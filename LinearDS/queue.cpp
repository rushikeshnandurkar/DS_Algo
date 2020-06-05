#include <iostream>

using namespace std;

class Queue
{
private:
    typedef struct node
    {
        int data;
        node *next;
    } node;

    node *rear;
    node *front;

public:
    Queue();
    void enqueue(int);
    int dequeue();
    void print_queue();
};

Queue::Queue()
{
    front = NULL;
    rear = NULL;
}

void Queue::enqueue(int num)
{
    node *temp = new node;
    temp->data = num;
    temp->next = NULL;
    if (rear == NULL)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int Queue::dequeue()
{
    int num = front->data;
    node *temp;
    temp = front;
    delete(temp);
    front = front->next;
    if (front == NULL)
    {
        rear = NULL;
    }
    return num;
}

void Queue:: print_queue()
{
    node* temp = front;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    q.print_queue();

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.print_queue();
    return 0;
}
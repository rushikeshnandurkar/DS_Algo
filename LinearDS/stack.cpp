#include<iostream>
#define MAX 10
using namespace std;

//  Defining stack design
class stack{
    private:
        typedef struct node{
            int data;
            struct node* next;
        };

        node* top;
    public:
        stack();    // Constructor
        int top_element();
        void push(int);
        int pop();
        int isEmpty();
};


// defining functions of stack

stack::stack(){
    top = NULL;
}

int stack::isEmpty(){
    return top == NULL;
}

int stack::top_element(){
    if (isEmpty()){
        return -1;
    } else{
        return top->data;
    }
}



void stack::push(int num){
    node* temp = new node;
    temp->data = num;
    temp->next = top;
    top = temp;
}



int stack::pop(){
    int x;
    x = top->data;
    node* temp = top;
    top = top->next;
    delete temp;
    return x;
}



//  defining functions of stack

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout<< s.pop();
    s.push(4);
    cout<< s.pop();
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
// Structure to create a node with data and the next pointer
struct node {
    int data;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;
struct node * top = NULL;

// Push() operation on a  stack
void push(int value) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value; // assign value to the node
    if (top == NULL) {
        newNode->next = NULL;
    } else {
        newNode->next = top; // Make the node as top
    }
    top = newNode; // top always points to the newly created node
    printf("Node is Inserted\n\n");
    display();
}

int pop() {
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        struct node *temp = top;
        int temp_data = top->data;
        top = top->next;
        free(temp);
        printf("Popped element is :%d\n",temp_data);
        display();
    }
}

void display() {
    // Display the elements of the stack
    if (top == NULL) {
        printf("\nStack Underflow\n");
    } else {
        printf("The stack is \n");
        struct node *temp = top;
        while (temp->next != NULL) {
            printf("%d--->", temp->data);
            temp = temp->next;
        }
        printf("%d--->NULL\n\n", temp->data);
    }
}

// Enqueue() operation on a queue
void enqueue(int value) {
    struct node * ptr;
    ptr = (struct node * ) malloc(sizeof(struct node));
    ptr -> data = value;
    ptr -> next = NULL;
    if ((front == NULL) && (rear == NULL)) {
        front = rear = ptr;
    } else {
        rear -> next = ptr;
        rear = ptr;
    }
    printf("Node is Inserted\n\n");
    displayq();
}

// Dequeue() operation on a queue
int dequeue() {
    if (front == NULL) {
        printf("\nUnderflow\n");
    
    } else {
        struct node * temp = front;
        int temp_data = front -> data;
        front = front -> next;
        free(temp);
        printf("Popped element is :%d\n",temp_data);
        displayq();
       }
}

// Display all elements of the queue
void displayq() {
    struct node * temp;
    if ((front == NULL) && (rear == NULL)) {
        printf("\nQueue is Empty\n");
    } else {
        printf("The queue is \n");
        temp = front;
        while (temp) {
            printf("%d--->", temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n\n");
    }
}

int main() {
    int choice=0, value,y=0,choiceq=0;
    while(y!=3){
        printf("Choose: 1-Stack, 2-queue, 3-exit\n");
        scanf("%i",&y);
        switch(y){
            case 1:
            printf("\nImplementation of Stack using Linked List\n");
            while (choice!=4) {
                printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
                printf("\nEnter your choice : ");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    printf("\nEnter the value to insert: ");
                    scanf("%d", &value);
                    push(value);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    display();
                    break;
                case 4:
                    printf("Stack function ended\n");
                        break;
                default:
                    printf("\nWrong Choice\n");
                }
            }
            break;
            case 2:
            printf("\nImplementation of Queue using Linked List\n");
            while (choiceq != 4) {
                printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
                printf("\nEnter your choice : ");
                scanf("%d", & choiceq);
                switch (choiceq) {
                    case 1:
                        printf("\nEnter the value to insert: ");
                        scanf("%d", & value);
                        enqueue(value);
                        break;
                    case 2:
                        dequeue();
                        break;
                    case 3:
                        displayq();
                        break;
                    case 4:
                        printf("Queue function ended\n");
                        break;
                    default:
                        printf("\nWrong Choice\n");
                }
            }
            break;
            case 3:
            exit(0);
            break;
        }}
    return 0;
}
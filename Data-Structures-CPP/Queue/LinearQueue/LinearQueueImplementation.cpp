#include <iostream>
#define SIZE 5
using namespace std;
int q[SIZE],front=0, rear=-1;
void push() {
    if (rear==SIZE-1) {
        cout << "Queue is full, cannot insert element.\n";
    }else {
        int val;
        cout << "Enter element to insert: ";
        cin >> val;
        rear++;
        q[rear]=val;
    }
}
void pop() {
    if (front>rear) {
        cout << "Queue is empty, cannot delete any element.\n";
    }else {
        cout << "Element deleted: " << q[front] << endl;
        front++;
    }
}
void display() {
    if (front>rear) {
        cout << "Queue is empty, cannot display any element.\n";
    }else {
        for (int i=front; i<=rear; i++) {
            cout << q[i] << "\n";
        }
    }
}
int main() {
    int ch,j=1;
    while (j==1) {
        cout << "Enter option:\n" << "1.Insert\n2.Delete\n3.Display\n4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Exiting program.";
                j=0;
                break;
            default:
                cout << "Invalid option.\n";
                j=0;
                break;
        }
    }
}

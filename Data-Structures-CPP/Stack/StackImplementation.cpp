#include <iostream>
#define SIZE 10
using namespace std;
int stack[SIZE],top=-1;
void push() {
    if (top==SIZE-1) {
        cout << "Stack is full, Overflow!\n" << endl;
    }else {
        int val;
        cout << "Enter element to push: \n";
        cin >> val;
        top++;
        stack[top] = val;
    }
}
void pop() {
    if (top==-1) {
        cout << "Stack is empty, Underflow!\n" << endl;
    }else {
        cout << "Deleted element is: \n" << stack[top] << endl;
        top--;
    }
}
void display() {
    if (top==-1) {
        cout << "Stack is empty, Underflow!\n" << endl;
    }else {
        cout << "The elements of the stack are: \n";
        for (int i=top; i>=0; i--) {
            cout << stack[i] << "\n";
        }
    }
}
int main() {
    int ch,j=1;
    while (j==1) {
    cout << "Enter option:" << "\n" << "1.Push onto stack\n" << "2.Pop from stack\n" << "3.Display\n" << "4.Exit\n" << endl;
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
                cout << "Exiting program." << endl ;
                j=0;
                break;
            default:
                cout << "Invalid option." << endl;
                j=0;
                break;
        }
    }
    return 0;
}

#include <iostream>
#define SIZE 5
using namespace std;
int q[SIZE],front=0,rear=-1,count=0;
void enqueue() {
    if (count==SIZE) {
        cout << "Queue is full, cannot insert elements." << endl;
    }else {
        int val;
        cout << "Enter element to insert: ";
        cin >> val;
        rear=(rear+1)%SIZE;
        q[rear]=val;
        count++;
    }
}
void dequeue() {
    if (count==0) {
        cout << "Queue is empty, cannot delete elements." << endl;
    }else {
        cout << "Element " << q[front] << " deleted." << endl;
        front = (front+1)%SIZE;
        count--;
    }
}
void display() {
    if (count==0) {
        cout << "Queue is empty, cannot display." << endl;
    }else {
        for (int i=0; i<count; i++) {
            int index=(front+i)%SIZE;
            cout << q[index] << endl;   
        }
    }
}
int main() {
    int j=1,ch;
    while (j==1) {
        cout << "Enter your option\n" << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cin >> ch;
        switch (ch) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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
                break;
        }
    }
}

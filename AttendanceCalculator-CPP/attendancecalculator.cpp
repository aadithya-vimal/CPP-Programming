#include<iostream>
using namespace std;

void subjectwiseattend() {
    int attended, total;
    float requiredperc;
    cout << "Enter hours attended:\n ";
    cin >> attended;
    cout << "Enter total no. of classes:\n ";
    cin >> total;
    float perc=float(attended) * 100 / float(total);
    cout << "Attendance percentage :\n " << perc << "%\n";
    cout << "Enter required percentage:\n ";
    cin >> requiredperc;
    float tempattended=attended;
    while (perc<requiredperc) {
        attended+=1;
        total+=1;
        perc=float(attended) * 100 / float(total);
    }
    cout << "You need to attend " << attended-tempattended << " more classes to achieve " << requiredperc << " attendance percentage.\n";
}
void allsubjectsattend() {
    int n;
    cout << "Enter number of subjects:-\n";
    cin >> n;
    int attended, total, requiredperc;
    for (int i=0;i<n;i++) {
        cout << "Subject " << i+1 << ":\n";
        cout << "Enter hours attended:\n";
        cin >> attended;
        cout << "Enter total no. of classes:\n";
        cin >> total;
        float perc=float(attended) * 100 / float(total);
        cout << "Attendance percentage :\n " << perc << "%\n";
        cout << "Enter required percentage:\n ";
        cin >> requiredperc;
        float tempattended=attended;
        while (perc<requiredperc) {
            attended+=1;
            total+=1;
            perc=float(attended) * 100 / float(total);
        }
        cout << "You need to attend " << attended-tempattended << " more classes to achieve " << requiredperc << " attendance percentage.\n";
    }
}
void subjectwisebunk() {
    int attended, total;
    float requiredperc;
    cout << "Enter hours attended:\n ";
    cin >> attended;
    cout << "Enter total no. of classes:\n ";
    cin >> total;
    float perc=float(attended) * 100 / float(total);
    cout << "Attendance percentage :\n " << perc << "%\n";
    cout << "Enter required percentage:\n ";
    cin >> requiredperc;
    int count=0;
    while (perc>requiredperc) {
        total+=1;
        perc=float(attended) * 100 / float(total);
        count++;
    }
    cout << "You can bunk " << count-1 << " more classes to keep " << requiredperc << " attendance percentage.\n";
}
void allsubjectbunk() {
    int n;
    cout << "Enter number of subjects:-\n";
    cin >> n;
    int attended, total;
    float requiredperc;
    for (int i=0;i<n;i++) {
        cout << "Subject " << i+1 << ":\n";
        cout << "Enter hours attended:\n";
        cin >> attended;
        cout << "Enter total no. of classes:\n";
        cin >> total;
        float perc=float(attended) * 100 / float(total);
        cout << "Attendance percentage :\n " << perc << "%\n";
        cout << "Enter required percentage:\n ";
        cin >> requiredperc;
        int count=0;
        while (perc>requiredperc) {
            total+=1;
            perc=float(attended) * 100 / float(total);
            count++;
        }
        cout << "You can bunk " << count-1 << " more classes to keep " << requiredperc << " attendance percentage.\n";
    }
}
int main() {
    int choice;
    cout << "----------Welcome to Attendance Application!----------\n";
    choiceenter:
    cout << "Enter your choice:-\n1.Subject Wise(How many more classes to attend)\n2.All Subjects(How many more classes to attend)\n3.Subject wise(How many classes can I bunk)\n4.All Subjects(How many classes can I bunk)\n5.Exit\n";
    cin >> choice;
    switch (choice) {
        case 1:
            subjectwiseattend();
            break;
        case 2:
            allsubjectsattend();
            break;
        case 3:
            subjectwisebunk();
            break;
        case 4:
            allsubjectbunk();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid Choice\n";
            goto choiceenter;
    }
    cin.ignore();
    cout << "Press any key to exit.\n";
    cin.get();
    return 0;
}

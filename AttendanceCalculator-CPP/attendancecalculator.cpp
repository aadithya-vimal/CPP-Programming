    #include<iostream>
    #include <vector>
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
        if (requiredperc==100) {
            cout << "100% attendance is not achievable.";
            return;
        }
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
        int sumclass=0;
        float sumperc=0;
        cout << "Enter number of subjects:-\n";
        cin >> n;
        int attended, total, requiredperc;
        vector<float> attendances;
        vector<int> classes;
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
            if (requiredperc==100) {
                cout << "100% attendance is not achievable.\n";
                continue;
            }
            float tempattended=attended;
            while (perc<requiredperc) {
                attended+=1;
                total+=1;
                perc=float(attended) * 100 / float(total);
            }
            int deltaclasses=attended-tempattended;
            classes.push_back(deltaclasses);
            attendances.push_back(perc);
            cout << "You need to attend " << deltaclasses << " more classes to achieve " << requiredperc << " attendance percentage.\n";
        }
        for (int i=0; i<size(classes); i++) {
            sumclass+=classes[i];
        }
        for (int i=0; i<size(attendances); i++) {
            sumperc+=attendances[i];
        }
        float numperc=size(attendances);
        float avgperc=sumperc/numperc;
        cout << "Attendance percentage :\n " << avgperc << "%\n";
        cout << "Total no. of more classes to be attended:\n " << sumclass;
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
        if (perc < requiredperc) {
            cout << "You are already below the required percentage. No bunks allowed.\n";
            return;
        }
        int bunks=0;
        while (true) {
            float futuretotal=total+bunks+1;
            float futureperc=attended*100/(futuretotal);
            if (futureperc<requiredperc) {
                break;
            }
            bunks++;
        }
        cout << "You can bunk " << bunks << " more classes to keep " << requiredperc << " attendance percentage.\n";
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
            if (perc < requiredperc) {
                cout << "You are already below the required percentage. No bunks allowed.\n";
                continue;
            }
            int bunks=0;
            while (true) {
                float futuretotal=total+bunks+1;
                float futureperc=attended*100/(futuretotal);
                if (futureperc<requiredperc) {
                    break;
                }
                bunks++;
            }
            cout << "You can bunk " << bunks << " more classes to keep " << requiredperc << " attendance percentage.\n";
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

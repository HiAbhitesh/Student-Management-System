#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

class Student
{
public:
    int roll;
    string name;
    float marks;

public:
    void input()
    {
        cout << "Enter roll number: ";
        cin >> roll;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter marks: ";
        cin >> marks;
    }
    void output() 
    {
        cout << "\nRoll no : " << roll << endl;
        cout << "Student name : " << name << endl;
        cout << "Marks : " << marks << endl;
    }
};

int main()
{
    int rollno;
    list<Student> slist;
    while (true)
    {
        cout << "\tStudent Management System\n"<< endl;
        cout << "\t1. Insert Record" << endl;
        cout << "\t2. Delete Record" << endl;
        cout << "\t3. Update Record" << endl;
        cout << "\t4. Show All Records" << endl;
        cout << "\t5. Exit\n\n"<< endl;
        int choice;
        cout << "Enter Choice: ";
        cin >> choice;
        Student ob;
        switch (choice)
        {
        case 1:
            ob.input();
            slist.push_back(ob);
            break;
        case 2:
            cout << "Enter the roll no to delete: ";
            cin >> rollno;
            {
                int flag = 0;
                for (auto it = slist.begin(); it != slist.end(); it++)
                {
                    if (it->roll == rollno)//for comparing new roll no 
                    {
                        slist.erase(it);
                        cout << "RECORD SUCCESSFULLY DELETED " << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "Record not found \n";
                }
            }
            break;
        case 3:
            cout << "Enter the roll no to update: ";
            cin >> rollno;
            {
                int flag = 0;
                for (auto &student : slist)
                {
                    if (student.roll == rollno)
                    {
                        cout << "Enter new Details:\n";
                        student.input();
                        cout << "RECORD SUCCESSFULLY UPDATED" << endl;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "Record not found \n";
                }
            }
            break;
        case 4:
            for (Student &i : slist)
            {
                i.output();
            }
            break;

        case 5:
            cout << "Thank you for visiting" << endl;
            return 0;

        default:
            cout << "Invalid choice" << endl;
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
    return 0;
}
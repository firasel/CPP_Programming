#include<bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    char section;
    int roll;
protected:
    int english_marks;
private:
    string password;
public:
    void set_marks(int marks){ english_marks = marks; }
    void set_password(string pw){ password = pw; }
    int get_marks(){ return english_marks; }
    void update_marks(string pw, int marks){
        if(password == pw){
            english_marks = marks;
            cout<<"Marks Updated!"<<endl;
        }else{
            cout<<"Password not matched!"<<endl;
        }
    }
};


int main()
{
    int n;
    cout<<"Enter the total student numbers: ";
    cin>>n;
    Student stdnt[n];

    // Student details get
    for(int i=0; i<n; i++){
        int marks;
        string password;

        cout<<i+1<<" No Student Details"<<endl<<"Name: ";
        getline(cin >> ws, stdnt[i].name);
        cout<<"Section: ";
        cin>>stdnt[i].section;
        cout<<"Roll: ";
        cin>>stdnt[i].roll;
        cout<<"Marks: ";
        cin>>marks;
        cout<<"Password: ";
        cin>>password;

        stdnt[i].set_marks(marks);
        stdnt[i].set_password(password);
    }

    // Run infinite loop for student mark update
    while(true){
        cout<<"Enter '0' for stop the update process"<<endl<<"Student Roll: ";
        int roll,marks;
        string password;
        cin>>roll;
        if(roll!=0){
            bool notFound = true;
            for(int i=0; i<n; i++){
                if(stdnt[i].roll == roll){
                    cout<<"Update Marks: ";
                    cin>>marks;
                    cout<<"Password: ";
                    cin>>password;
                    stdnt[i].update_marks(password, marks);
                    notFound = false;
                }
            }
            notFound && cout<<"Student not found!"<<endl;

        }else break;
    }

    // Print all student details
    for(int i=0; i<n; i++) cout<<stdnt[i].name<<' '<<stdnt[i].section<<' '<<stdnt[i].roll<<' '<<stdnt[i].get_marks()<<endl;

    return 0;
}

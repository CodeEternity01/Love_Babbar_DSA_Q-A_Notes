#include<iostream>
using namespace std;
class student
{
    int age;
    public:
    
        student()
        {
            cout<<"constructor called"<<endl;
        }
        student(int a)
        {
            age=a;
        }
        int get()
        {
           return age;
        }
        ~student()
        {
            cout<<"Destructor called"<<endl;
        }
};
int main(){
    student s1;
    student s2(15);
    cout<<s2.get()<<endl;
}
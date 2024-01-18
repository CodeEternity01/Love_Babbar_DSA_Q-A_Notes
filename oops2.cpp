/*encapsulation rapping up data member and function ,the single entity combine both in a single capsule
for example :- data member are red tablet and function are blue one we turn them into single
packet capsule
fully encapsulated class:- all data member are private: mean they are only use in same class 
Encapsulation is data hiding && memory hiding
Advantages:
    1. data hide-> security increase:
    2. if we want we can make read only--"read only"
    3.code Reusability
    4. Encapsulation -> Unit Testing
#include <iostream>
using namespace std;
class student{
    private:
      string name;
      int age;
      int health;
    public:
      int getAge(){
        return this->age;
      }
};
 
 int main(){
    student first;
    cout<<"sab sahi chal raha hai";
 }
 */
// Inheritance:- male is inherit from human class
// private member of data class cannot be inheritable
/*base/super class  type class       derived class
public            public           public
public            private          private
public            protected        protected
protected         public           protected
protected         protected        protected
protected         private          private
private           public           NA
private           protected        NA
private           private          NA */
#include <iostream>
using namespace std;
class human{
    private:
      int height;
    public:
      int weight;
      int age;
     void setheight(int h){
        this->height=h;
     }
     int getAge(){
        return  this->age;
     }
     void setweight(int w){
        this->weight=w;
     }
};
// single inheritance
class male: public human{
   public:
     string color;
   void sleep(){
    cout<<"male sleeping"<<endl;
   }  
};
// multi level inheritance
class female: public male{

};

int main(){
    female obj;
    obj.setweight(61);
    obj.setheight(52);
    cout<<obj.age<<endl;
    cout<<obj.weight<<endl;
    //  cout<<obj.height<<endl;
    cout<<obj.color<<endl;
}
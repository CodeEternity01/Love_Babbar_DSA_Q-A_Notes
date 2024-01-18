// Home Work
// padding && gready alingment
// deep copy shallow copy
// const keyword
// initialisation list
#include <iostream>
using namespace std;
class hero{
public:
  hero(){
    name = new char[100];
    
    cout<< "default contractor called"<<endl;}
  
  ~hero(){
   cout<< "contractor destroye"<<endl;
  }
  int health; 
  char *name;
  char level;
//   static variable
  static int timetocomplete;
  char getlevel(){
   return level;}
   int gethealth(){
      return health;
   }
  void setlevel(char l){
   level=l;
  }
  void sethealth(int h){
   health=h;
}
// Here This is used to stored the current object address:
 hero(int health,char level){
   cout<<this<<endl;
   this->level=level;
   this->health=health;
 }
 hero(hero &temp){
    cout<<"Copy constructor "<<endl ;
    this->name=temp.name;
    this->health=temp.health;
    this->level=temp.level;
 }
  void print(){
    cout<<"name : "<<this->name<<endl;
    cout<<"health : "<<this->health<<endl;
    cout<<"level  : " <<this->level<<endl;
  }
// static function
static void random(){
    cout<<timetocomplete<<endl; //static function can only call static variable
}

};
int hero::timetocomplete=5;  // :: are called scope resolution operator
int main(){
   hero suresh(70,'C');
    cout<<suresh.gethealth()<<endl;
    cout<<suresh.getlevel()<<endl;
    hero ramesh(suresh);
     suresh.health=23;
    cout<<suresh.gethealth()<<endl;
    cout<<ramesh.gethealth()<<endl;
    cout<<ramesh.getlevel()<<endl;

hero hero1;
hero1.sethealth(23);
hero1.setlevel('D');
char nam[7]="babbar";
hero1.name=nam;
hero1.print();
cout<<endl<<endl;
hero hero2(hero1);
hero2.print();
cout<<endl<<endl;
hero1.name[0]='g';
hero2.print();
/*
hero a(75,'B');
hero b(49,'C');
// hero a=b; Copy  
a=b;
char nam[7]="babbar";
a.name=nam;
a.print();*/
/* // Contractor are called automatecally in both static and dynamic memory allocation But
// Destructor are only called automatecally in satic,For dynamic memory free we have to
//call Destructor manually
hero h1; // constructor call first and then destructor automatically
hero *h2=new hero(); // constuctor called automatically
delete h2; // here manually destructor is called for dyanmic memory allocation */

 cout<<hero::timetocomplete<<endl; //call of staic function without using object
   hero::random();

}
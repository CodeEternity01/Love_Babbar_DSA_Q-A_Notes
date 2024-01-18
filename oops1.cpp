// Home Work
// padding && gready alingment
#include <iostream>
using namespace std;
class hero{
public:
  hero(){
    cout<< "contractor called"<<endl;}
  
  ~hero(){
   cout<< "contractor destroye"<<endl;
  }
  int health; 
  string name;
  char level;
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
};
int main(){
  // here the value are assignest through parametrised constructor
 hero h(45,'C');
 hero h2;
// cout<< &hero.h<<endl;
 h.name="Ramesh";
 cout<<h.name<<endl;
 cout<<h.health<<endl;
 cout<<h.level<<endl;

 hero *h1=new hero;
  (*h1).health=75;
 (*h1).name="Ramesh";
  (*h1).level='a';
 cout<<"health of h1: "<<h1->health<<endl;
 cout<<(*h1).getlevel()<<endl;
 (*h1).setlevel('B');
 cout<<(*h1).getlevel()<<endl;
 (*h1).setlevel('A');
 cout<<(*h1).getlevel()<<endl;
 cout<<(*h1).gethealth()<<endl;
 (*h1).sethealth(79);
 cout<<(*h1).gethealth();
 
    return 0;
}
#include <iostream>
using namespace std;
class father{
    public:
      int income;
      int weight;
      int color;
};
class son{
    public:
      int expances;
      int weight;
      int height;
};
// muliple inheritance male is hybrid class from father and son
// male has both data member and function of father and son

class male: public father,public son{

};
int main(){
    male m1;
    m1.income=1200000;
    m1.expances=100000;
    // for avoid ambiquity using scope resolution operator
    m1.father::weight=62;
    m1.son::weight=55;
    cout<<m1.father::weight<<endl;
   cout<<m1.son::weight<<endl;
    cout<< m1.income<<endl;
    cout<< m1.expances<<endl;
    cout<< m1.height<<endl;
}
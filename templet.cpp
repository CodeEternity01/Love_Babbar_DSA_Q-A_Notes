#include<iostream>

using namespace std;
template <typename T>

class solution
{
    T x;
    T y;
    public:
    void setx(T x)
    {
        this->x=x;

    }
    T getx()
    {
        return x;
    }

    void sety(T y)
    {
        this->y=y;

    }
    T gety()
    {
        return y;
    }
};
int main()
{
solution<int> p1;


p1.setx(10);
p1.sety(20);

cout<<p1.getx()<<" "<<p1.gety()<<endl;




return 0;
}
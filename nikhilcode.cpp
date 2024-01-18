#include<iostream>

using namespace std;
template <typename T>

struct pair
{
    public:
    T x;
    T y;

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
pair<int,int_least64_t> p1;


p1.setx(10);
p1.sety(20);

cout<<p1.getx()<<" "<<p1.gety()<<endl;




return 0;
}
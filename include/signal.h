#include <iostream>
using namespace std;

class signal
{
private:

    char t;  ///t is the type
    double mag; /// mag is the magnitude

public:
    signal(){t='A';  mag=0.0;}
    ~signal(){}
    void setmag(double m){mag = m;}
    double getmag(){return mag;}
    void display(){cout<<"Type: "<<t<<" signal magnitude: "<<mag<<endl;}

};

#include <iostream>
using namespace std;

class target
{
private:
    int id;
    double x;
    double y;
    signal mySig;

public:
    target(){id=0; x=0; y=0;}
    ~target(){}

    void setid(int i){id =i;}
    void setx(double d){x=d;}
    void sety(double d){y=d;}

    int getid(){return id;}
    double getx(){return x;}
    double gety(){return y;}

    void display()
        {
            cout<<"target id# "<<id
                <<" at ("<<x<<", "<<y<<")"<<endl;
            mySig.display();
            cout<<"-------------"<<endl<<endl;
        }

        ///vx and vy are the "velocities" in x and y
    void target_move(double vx, double vy)
                {
                    x=x+vx;
                    y=y+vy;
                }

        ///ask the target to please set its signal magnitude
    void setSigMag(double m){mySig.setmag(m);}
    double getSigMag(){return mySig.getmag();}
    void gen_signal(){}
};

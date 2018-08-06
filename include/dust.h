#ifndef DUST_H
#define DUST_H
#include <iostream>
#include <cmath> ///this has pow(x,y)and sqrt()   e.g. x to the y exponent
using namespace std;

class dust
{
    public:
        dust(){dist=1.0;id=0;}
        dust(int i){id=i;}
        virtual ~dust(){}  ///everyone doesnt NEED their own destructor!!

        void setid(int i){id=i;}
        int getid(){return id;}

        double Getx() { return x; }
        void Setx(double val) { x = val; }

        double Gety() { return y; }
        void Sety(double val) { y = val; }

        char Gett() { return t; }
        void Sett(char val){t = val;}

        void display(){cout<<"dust at ("<<x<<", "<<y<<")"<<"Dust #"<<id<<endl;}

        ///get x,y info from target
        void getFromT(double tx, double ty)
            {   ///compute the distance from the target to this dust.
                ///cout<<"my x = "<<x<<" you gave me x = "<<tx<<endl;
                ///   pow(base,exp) in this case dx squared and dy squared
                dist = sqrt(pow((x-tx),2.0)+pow((y-ty),2.0));
                cout<<"Target distance: "<<dist<<endl;
            }
            ///  listen to target: ss is the signal strength of the target
        void listen2T(double ss)
        {   ihear = ss/dist;
            if(ihear<1.0){ihear = 0.0; cout<<"I hear nothing"<<endl;}
            else{cout<<"this dust hears "<<ihear<<endl;}
        }
        double getihear(){return ihear;}
    private:
        int id;
        double x;  ///x,y are locations on a grid
        double y;
        char t;   ///type character
        double dist;
        double ihear;
};

#endif /// DUST_H

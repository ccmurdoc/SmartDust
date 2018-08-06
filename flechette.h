#include <iostream>
#include <cmath> ///this has pow(x,y)and sqrt()   e.g. x to the y exponent
#include "dust.h"
#include <list>

using namespace std;



class flechette
{
    public:
        flechette(){x=0.0; y=0.0;}
        flechette(double a, double b){x = a; y = b;}
        ~flechette() {}

        double getx() { return x; }
        void setx(double val) { x = val; }

        double gety() { return y; }
        void sety(double val) { y = val; }

        void listen(dust *dptr)
        {
            ditr=mydust.begin();
            while(ditr!=mydust.end())
            {
                ditr++;
            }
            cout<<"Listen----"<<endl;
        }
        void inrange(dust *dptr)
        {
            double dx = x - (dptr -> Getx());
            double dy = y - (dptr -> Gety());
            double dist = sqrt(pow(dx,2.0)+pow(dy,2.0));
            cout<<"distance from dust to flechette: "<<dist<<endl;
            if(dist<20)
            {
                mydust.push_back(dptr);
                cout<<"adding nearby dust"<<endl;
                dptr->display();
            }
        }

        void display(){cout<<"flechette x: "<<x<<" y: "<<y<<endl;
              ditr= mydust.begin();
              while(ditr!=mydust.end())
                { ///*aitr gives us a pointer
                  (*ditr)->display();
                  ditr++;
                }
              }///end of display()

    protected:

    private:
        double x;
        double y;
        list<dust*> mydust;
        list<dust*>::iterator ditr;
};

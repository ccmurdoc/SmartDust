#include <iostream>  ///all my files are on the desktop..so...
#include <ctime>
#include <random>
#include <fstream>
#include <string>
#include <sstream>
#include <signal.h>
#include <target.h>
#include <dust.h>
#include <flechette.h>
#include <cstdlib> //this has system in it.

using namespace std;

int main()
{
    /// command
    fstream f1out;
    fstream comout;
///comout  is a connection to the file command.txt
///that gnuplot will use
    comout.open("command.txt",ios::out);
    comout<<"set yrange [-50:70]"<<endl;
    comout<<"set xrange [-100:100]"<<endl;
    comout<<"set xlabel \"X Axis\""<<endl;
    comout<<"set ylabel \"Y Axis\""<<endl;
    comout<<"set terminal png"<<endl;



    string basefile ="dustdata";
    string letterstr;
    string filename;
    string pngfile;

    char letter = 'A';
    signal S;
    S.setmag(5.4);

   default_random_engine gen(time(NULL));
   uniform_real_distribution<double> xdist(-100,100);
   normal_distribution<double> ydist(0,15);

   fstream fout;
   ///fout.open("smartdust.txt",ios::out);

   target T;
   T.setid(7);
   T.setSigMag(15); ///we provide info to target, the
                    ///target sets the signal

   cout<<endl<<endl<<"--------------------------"<<endl;

   list<dust> D;
   list<dust>::iterator ditr;
   dust * dptr;

   int N;
   cout<<"How many dust?"<<endl;
   cin>>N;

   for(int i=0; i<N; i++){dptr=new dust;
                          dptr->Sett('A');
                          dptr->Setx(xdist(gen));
                          dptr->Sety(ydist(gen));
                          dptr->display();
                          D.push_back(*dptr);
                          }


    flechette * fptr;                   ///
    list <flechette> myFz;              ///
    list <flechette>::iterator fitr;    ///

    for(int i=0; i<N/10; i++){fptr=new flechette;

                          fptr->setx(xdist(gen));
                          fptr->sety(ydist(gen));
                          fptr->display();
                          myFz.push_back(*fptr);
                          }


 ///-----------------------------------------------
 fitr=myFz.begin();
 while(fitr!=myFz.end())
 {
     ditr=D.begin();
     while(ditr!=D.end())
     {   dptr=&(*ditr);
         fitr->inrange(dptr);
         ditr++;
     }
     fitr++;
 }
///------------------------------------------------------------------
   cout<<endl<<endl;
   cout<<"--------------------"<<endl;
   cout<<"reset target to origin"<<endl;
   T.setx(-100);
   T.sety(-50);

   for(int i=0; i<20; i++) ///is the time steps, or movement loop
   {    ///Dust D receives x and y from Target T
            stringstream ss;
            letter='A'+i;
            letterstr="";
            ss << letter;
            ss >> letterstr;
            filename=basefile+letterstr+".txt";
            cout<<"creating  " <<filename<<endl;
            fout.open(filename.c_str(),ios::out);
            ///fout<<i<<endl;
            ditr=D.begin();
            while(ditr!=D.end())///dust visit loop
        {


        ditr->getFromT(T.getx(),T.gety());
        ditr->listen2T(T.getSigMag());
        ///fout<<D[j].listen2T(T.getSigMag())<<endl;;

        if(ditr->getihear()>0)
            {fout<<ditr->Getx()<<" "<<ditr->Gety()<<" "<<ditr->getihear()<<endl;

            }

        ///fout<<D[j].Getx()<<" "<<D[j].Gety()<<" "<<D[j].getihear()<<endl;
        ditr++;
        }

        {

        ///pngfile is the name of the image that gnuplot makes
        pngfile=basefile+letterstr+".png";
        comout<<"set output \'"<<pngfile<<"\'"<<endl;
        comout<<"plot \'"<<filename<<"\' with circles linecolor rgb \"#FA3FBC\" fill solid noborder"<<endl;

        }

    ///the command file is ready, close it..and use it.
    ///system needs the <cstdlib> library



        ///filename="";
    cout<<"End of Step #"<<i<<endl;
    cout<<"-----------------------"<<endl;

       T.target_move(10,5);
   }
   comout.close();
  system("gnuplot command.txt");

   ///fout.close();
    return 0;
}

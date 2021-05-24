#include<iostream>
#include <iomanip>
#include <fstream>

/*******************************
 *Author: Prateek Garg
 *Date: 24th May 2021 
 *Max no. Groundworks taht can be attended
********************************/

#define MaxNum 36

using namespace std;

struct Groundworks
{
    int Start_time;
    int Duration;
    int End_time;    
};

struct Available_Groundworks
{
    int n;                                                      //No. of Groundworks available
    Groundworks AvailableGw[MaxNum];                            //Groundwork_Details
                                                                
    Available_Groundworks(){                                    //Default_Constructor
        n= MaxNum;
        for (int i = 0; i < n; i++)
        {
            AvailableGw[i].Duration=-1;
        }
        
    }

};

Available_Groundworks* initialize (int start_time[ ], int duration[ ], int n){
    Available_Groundworks* a;
    a->n=n;

    for (int i = 0; i < n; i++)
        {   a->AvailableGw[i].Start_time=start_time[i];
            a->AvailableGw[i].Duration=duration[i];
            a->AvailableGw[i].End_time= start_time[i] + duration[i];
        }
    return a;    

}

int CalculateMaxGroundworks(Available_Groundworks* ptr){
    int n=ptr->n;
    
    int a[n];
     int b[n];
    for (int i = 0; i < n; i++){
        a[i]=ptr->AvailableGw[i].Start_time;
        b[i]= ptr->AvailableGw[i].Duration;
    }
   

    int x=0;
    int y[23];

    for (int i = 0; i < 23; i++) {y[i]=0;}
    for (int i = 0; i < n; i++)
    {
        if(b[i]==1){
            y[a[i]]=1;
            a[i]=0;
            x++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(b[i]==2 & y[a[i]] !=1 & y[a[i+1]] !=1){
            y[a[i]]=1;
            a[i]=0;
            x++;
        }
    }
    return x;
}

int main(){
    string names[MaxNum];
    int start_time[MaxNum];
    int duration[MaxNum];
    int n=0;

    ifstream inFile;
    
    inFile.open("Schedule.txt");
    if (!inFile) {
        cout << "Error: Unable to locate file";
        exit(1);                                                           // terminate with error
    }
    

    while (inFile >>names[n]>>start_time[n]>>duration[n]) {
        n++;
    }
    
    cout<<CalculateMaxGroundworks(initialize(start_time,duration,n))<<endl;

    inFile.close();



    return 0;
}
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
    Available_Groundworks a;
    a.n=n;

    for (int i = 0; i < n; i++)
        {   a.AvailableGw[i].Start_time=start_time[i];
            a.AvailableGw[i].Duration=duration[i];
            a.AvailableGw[i].End_time= start_time[i] + duration[i];
        }
    return &a;    

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
    
    string tempString;

    while (inFile >>names[n]>>start_time[n]>>duration[n]) {
        n++;
    }
    
    inFile.close();

    return 0;
}
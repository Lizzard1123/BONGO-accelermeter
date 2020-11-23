#include <iostream>
#include <cmath>
using namespace std;
#define FLnum 1
#define FRnum 2
#define BLnum 2
#define BRnum 1

double FL;
double FR;
double BL;
double BR;

double speed;
double angle;

//sum x and y parts of angle
//find the multipler of what the speed should be
//FR and BL sum of x and y calcel where they should and pos means forward neg means reverse 
//reverse x axis for FL and BR
double multiplier(int num, double angle){
    double x = ;
    double y = ;
    switch(num){
        case 1:

        break;
        case 2:

        break;
    }
    //just in case
    return 0;
}


//input angle and speed
//speed is controlled by PID 
int main(){
    cin >> angle;
    cin >> speed;
    FL = multiplier(FLnum,angle) * speed;
    FR = multiplier(FRnum,angle) * speed;
    BL = multiplier(BLnum,angle) * speed;
    BR = multiplier(BRnum,angle) * speed;
    return 0;
}

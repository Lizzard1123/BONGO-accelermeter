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

//to degress from r
double toDegrees(double r){
    return (r * 180) /  M_PI;
}

//sum x and y parts of angle
//find the multipler of what the speed should be
//FR and BL sum of x and y calcel where they should and pos means forward neg means reverse 
//reverse x axis for FL and BR
double multiplier(int num, double angle){
    int hyp = 1;
    double x = sin(angle);
    double y = cos(angle);
    switch(num){
        case 1:
            x *= -1;
            return y + x;
        break;
        case 2:
            return y + x;
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
    cout << "FL ";
    cout << (FL) << endl;
    cout << "FR ";
    cout << (FR) << endl;
    cout << "BL ";
    cout << (BL) << endl;
    cout << "BR ";
    cout << (BR) << endl;
    return 0;
}

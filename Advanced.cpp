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

double sRound(double num, int decimal){
    int mult = pow(10, decimal);
    return round(num * mult)/mult;
}

//sum x and y parts of angle
//find the multipler of what the speed should be
//FR and BL sum of x and y calcel where they should and pos means forward neg means reverse 
//reverse x axis for FL and BR
double multiplier(int num, double angle){
    double x = sin(angle*M_PI/180);
    double y = cos(angle*M_PI/180);
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

double greatest(double FL, double FR, double BL, double BR){
    if(FL >= 100 || FR >= 100 || BL >= 100 || BR >= 100){
        double final = FL;
        if(final <= FR ){
            final = FR;
        }
        if(final <= BL){
            final = BL;
        }
        if(final <= BR){
            final = BR;
        }
        if(final != 0){
            return final;
        } else {
            return 100;
        }
    } else {
        return 100;
    }
}

//input angle and speed
//speed is controlled by PID 
int main(){
    cin >> angle;
    cin >> speed;
    FL = sRound(multiplier(FLnum,angle) * speed, 3);
    FR = sRound(multiplier(FRnum,angle) * speed, 3);
    BL = sRound(multiplier(BLnum,angle) * speed, 3);
    BR = sRound(multiplier(BRnum,angle) * speed, 3);
    double under = greatest(fabs(FL), fabs(FR), fabs(BL), fabs(BR))/100;
    cout << "new" << endl;
    cout << under << endl;
    cout << "FL ";
    cout << (FL)/under << endl;
    cout << "FR ";
    cout << (FR)/under << endl;
    cout << "BL ";
    cout << (BL)/under << endl;
    cout << "BR ";
    cout << (BR)/under << endl;
    return 0;
}

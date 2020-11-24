
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
double Dangle;

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
double slope(double Xone,double Yone,double Xtwo,double Ytwo){
    if((Xtwo - Xone) == 0){
        return 0;
    }
    return (Ytwo - Yone) / (Xtwo - Xone);
}


bool Left(double Xone,double Yone,double Xtwo,double Ytwo, double PX, double PY){
    return ((PX - Xone)*(Ytwo- Yone) - (PY - Yone)*(Xtwo - Xone)) < 0;
}

bool Right(double Xone,double Yone,double Xtwo,double Ytwo, double PX, double PY){
    return ((PX - Xone)*(Ytwo- Yone) - (PY - Yone)*(Xtwo - Xone)) > 0;
}

double distance(double thisSlope, double PX, double PY){
    return fabs((-thisSlope * PX + PY)) / sqrt(1 + pow(thisSlope,2));
}

double multiplier(int num, double angle, double Dangle){
    double movingAngle = Dangle;
    double mathAngle;
    double currentAngle = angle;
    int check;
    switch(num){
        case 1:
            //FL BR
            mathAngle = movingAngle + 45;
            currentAngle = currentAngle - 45;
            check = 1;
        break;
        case 2:
            //FR BL
            mathAngle = movingAngle - 45;
            currentAngle = currentAngle + 45;
            check = -1;
        break;
    }
    double slopeLineX = sin(mathAngle*M_PI/180);
    double slopeLineY = cos(mathAngle*M_PI/180);
    double targetX = sin(currentAngle*M_PI/180);
    double targetY = cos(currentAngle*M_PI/180);
    double dist = distance(slope(0,0,slopeLineX, slopeLineY), targetX, targetY);

    if(!Left(0,0,slopeLineX, slopeLineY, targetX, targetY) && !Right(0,0,slopeLineX, slopeLineY, targetX, targetY)){
        return 0;
    } else if (Left(0,0,slopeLineX, slopeLineY, targetX, targetY)){
        return dist * check;
    } else if (Right(0,0,slopeLineX, slopeLineY, targetX, targetY)){
        return -dist * check;
    } 
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
    cout << "C angle : ";
    cin >> angle;
    cout << "D angle : ";
    cin >> Dangle;
    cout << "speed : ";
    cin >> speed;
    FL = sRound(multiplier(FLnum,angle,Dangle) * speed, 3);
    FR = sRound(multiplier(FRnum,angle,Dangle) * speed, 3);
    BL = sRound(multiplier(BLnum,angle,Dangle) * speed, 3);
    BR = sRound(multiplier(BRnum,angle,Dangle) * speed, 3);
    double under = greatest(fabs(FL), fabs(FR), fabs(BL), fabs(BR))/100;
    cout << "new" << endl;
    cout << under << endl;
    cout << "FL ";
    cout << sRound((FL)/under, 5) << endl;
    cout << "FR ";
    cout << sRound((FR)/under, 5) << endl;
    cout << "BL ";
    cout << sRound((BL)/under, 5) << endl;
    cout << "BR ";
    cout << sRound((BR)/under, 5) << endl;
    return 0;
}

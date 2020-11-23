




/*


#include <iostream>
#include <cmath>
using namespace std;
//goal take in CX and CY and find path to TX and TY
//output 4 motor speeds that doesnt turn bongo
//make it turn and move later
double CX;
double CY;
double TX;
double TY; 
double X_starting_offset_in = 5;//offset in inch
double Y_starting_offset_in = 5;//offset in inch
double CA = 0;
double TA;
double DegreesToTurn;

//finds denominator
double allUnder(double FL, double FR, double BL, double BR){
    if(FL <= 100 || FR <= 100 || BL <= 100 || BR <= 100){
        return true;
    }
    return true;
}

//finds denominator
double lowest(double FL, double FR, double BL, double BR){
        double final = FL;
        if(final >= FR ){
            final = FR;
        }
        if(final >= BL){
            final = BL;
        }
        if(final >= BR){
            final = BR;
        }
        if(final != 0){
            return final;
        } else {
            return 100;
        }
}


//finds denominator
double greatest(double FL, double FR, double BL, double BR){
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
}

//get hypotonuse 
double getHyp(double cx,double cy,double tx,double ty){
    return sqrt(pow((tx - cx), 2) + pow((ty - cy), 2));
}


//to degress from r
double toDegrees(double r){
    return (r * 180) /  M_PI;
}

//true if neg
bool isNeg(double num){
    return num < 0;
}

//returns quad + neg for tan ASTC
double quadrent(double x, double y){
    if(isNeg(x) && isNeg(y)){
        //quad 3
        return -3;
    } else if (isNeg(x) && !isNeg(y)){
        //quad 2
        return 2;
    } else if (!isNeg(x) && isNeg(y)){
        //quad 4
        return 4;
    }
    //quad 1
    return 1;
}

//returns angle in r
double angle(double changeX, double changeY){
    return atan(changeX/changeY)*quadrent(changeX, changeY);
}



int notnot_main(){
    cout << "Enter current X" << endl;
    cin >> CX;
    cout << "Enter current Y"  << endl;
    cin >> CY;
    cout << "Enter angle"  << endl;
    cin >> CA;
    while(true){
        cout << "Enter Target X"  << endl;
        cin >> TX;
        cout << "Enter Target Y"  << endl;
        cin >> TY;
        cout << getHyp(CX, CY, TX, TY)  << endl;
        double changeX = TX - CX;
        double changeY = TY - CY;
        //TA = toDegrees(angle(changeX, changeY));
        cout << TA  << endl;
        cout << "Current Angle"  << endl;
        cout << TA << endl;
        CX = TX;
        CY = TY; 
        //motor speeds
        double Y = changeY;
        double X = changeX;
        double FL = Y + X;
        double FR = Y - X;
        double BL = Y - X;
        double BR = Y + X;
        cout << "FL ";
        cout << (FL) << endl;
        cout << "FR ";
        cout << (FR) << endl;
        cout << "BL ";
        cout << (BL) << endl;
        cout << "BR ";
        cout << (BR) << endl;
        double under;
        if(allUnder(fabs(FL), fabs(FR), fabs(BL), fabs(BR))){
            under = greatest(fabs(FL), fabs(FR), fabs(BL), fabs(BR))/100;
        } else {
            under = greatest(fabs(FL), fabs(FR), fabs(BL), fabs(BR))/100;
        }
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
    }
    return 0;
}

*/
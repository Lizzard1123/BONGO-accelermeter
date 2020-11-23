







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

//get hypotonuse 
double getHyp(double cx,double cy,double tx,double ty){
    return sqrt(pow((tx - cx), 2) + pow((ty - cy), 2));
}

double toDegrees(double r){
    return (r * 180) /  M_PI;
}

//returns angle in r
double angle(double cx,double cy,double tx,double ty){
    double changeX = tx - cx;
    double changeY = ty - cy;
    return atan(changeX/changeY);
}



int main(){
    cout << "Enter current X" << endl;
    cin >> CX;
    cout << "Enter current Y"  << endl;
    cin >> CY;
    while(true){
        cout << "Enter Target X"  << endl;
        cin >> TX;
        cout << "Enter Target Y"  << endl;
        cin >> TY;
        cout << getHyp(CX, CY, TX, TY)  << endl;
        TA = toDegrees(angle(CX, CY, TX, TY));
        cout << toDegrees(angle(CX, CY, TX, TY))  << endl;
        DegreesToTurn = CA - TA;
        cout << "turnng"  << endl;
        cout << DegreesToTurn << endl;
        cout << "Current Angle"  << endl;
        CA += DegreesToTurn;
        cout << CA  << endl;
        CX = TX;
        CY = TY; 
    }
    
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
const double G = 9.80665;
double delayTime = 1000;
double timeinSec = delayTime/1000;
double Xacceleration, Yacceleration, VX, VY, X, Y;
double X_starting_offset_in = 5;//offset in inch
double X_starting_offset = X_starting_offset_in * 39.37;//offset in meter
double Y_starting_offset_in = 5;//offset in inch
double Y_starting_offset = Y_starting_offset_in * 39.37;//offset in meter


//get new velocity
double updateV(double Vo, double A, double T){
    return Vo + A * T;
}

//return the Acc in m/s^2
double normalize(double acc){
    return acc * G;
}

//Input current accelartion and velocity
//Outputs change in position
double update_position(double accel, double velo){
    return (timeinSec*velo+.5*accel*pow(timeinSec, 2))*39.37;
}
  
int main() {
  
  while(true){
    cout << "Enter X acc";
    cin >> Xacceleration;
    Xacceleration = normalize(Xacceleration);
    cout << "Enter Y acc";
    cin >> Yacceleration;
    Yacceleration = normalize(Yacceleration);
    //update current X
    X +=  update_position(Xacceleration, VX);
    //update current Y
    Y +=  update_position(Yacceleration, VY);
    //updates X velocity
    VX =  updateV(VX, Xacceleration, timeinSec);
    //updates Y velocity
    VY =  updateV(VY, Yacceleration, timeinSec);
    //outputs 
    cout << "X acc" << endl;
    cout << Xacceleration << endl;
    cout << "Y acc" << endl;
    cout << Yacceleration << endl; 
    cout << "VX" << endl;
    cout << VX << endl;
    cout << "VY" << endl;
    cout << VY << endl;
    cout << "X" << endl;
    cout << X << endl;
    cout << "Y" << endl;
    cout << Y << endl;
  }
    return 0;
}
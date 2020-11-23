#include <iostream>
#include <cmath>
using namespace std;
const double G = 9.80665;
double delayTime = 1.0;
double Xacceleration;
double Yacceleration;
double VX;
double VY;
double X;
double Y;
//get new velocity
double updateV(double Vo, double A, double T){
    return Vo + A * T;
}

//return the Acc in m/s^2
double normalize(double acc){
    return acc * G;
}

double update_position(double accel, double velo){//Input current accelartion and velocity
  double position;                             //Output change in direction
  position =  delayTime*velo+.5*accel*delayTime*delayTime;
  return position;
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
    VX =  updateV(VX, Xacceleration, delayTime);
    //updates Y velocity
    VY =  updateV(VY, Yacceleration, delayTime);
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
/*
#include <iostream>
#include <cmath>
using namespace std;
double Xone, Yone, Xtwo, Ytwo, PX, PY;

double slope(double Xone,double Yone,double Xtwo,double Ytwo){
    return (Ytwo - Yone) / (Xtwo - Xone);
}

int main(){
    cout << "Enter X one" << endl;
    cin >> Xone;
    cout << "Enter Y one"  << endl;
    cin >> Yone;
    cout << "Enter X two" << endl;
    cin >> Xtwo;
    cout << "Enter Y two"  << endl;
    cin >> Ytwo;
    cout << "PX" << endl;
    cin >> PX;
    cout << "PY"  << endl;
    cin >> PY;
    double thisSlope = slope(Xone, Yone, Xtwo, Ytwo);
    cout << fabs((-thisSlope * PX + PY)) / sqrt(1 + pow(thisSlope,2));
    return 0;
}
*/
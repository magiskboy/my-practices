#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int vi;
    long vl;
    char vch;
    float vf;
    double vd;
    
    cin >> vi >> vl >> vch >> vf >> vd;
    
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", vi, vl, vch, vf, vd);
    
    
    return 0;
}
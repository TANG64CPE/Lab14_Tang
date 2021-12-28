#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int N,double B[]){
    double am = 0,sd = 0,gm = 1,v = 0,n = N,c = 0,min = 0,max = 0;
    for ( int i = 0; i < N;i++){
        am += A[i];
    }
    B[0] = am/N;
    for ( int i = 0; i < N;i++){
        sd += pow(A[i]-B[0],2);
    }
    B[1] = sqrt(sd/N);
    for ( int i = 0; i < N;i++){
        gm *= A[i];
    }
    v = 1/n;
    B[2] = pow(gm,v);
    for ( int i = 0; i < N ;i++){
        c += 1/A[i];
    }
    B[3] = N/c;
    for ( int i = 0; i < N ;i++){
        if( A[i] == A[0] || A[i] > max ) max = A[i];
    }
    B[4] = max;
    for ( int i = 0; i < N ;i++){
        if( A[i] == A[0] || A[i] < min ) min = A[i];
    }
    B[5] = min;
}

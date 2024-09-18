#include <iostream>
using namespace std;

long double stp(long double num, long double x){
    long double z = 1;
    for(int i{1};i <= x;i+=1){
        z = z * num;
    }
    return z;
}

long long fuct(long long y){
    long long res = 1;
    if (y % 2 == 0){
        for (int i{2};i <= y; i+=2 ){
            res = res * i;
        }
    }
    else if(y % 2 != 0){
        for (int i{3}; i <= y; i += 2){
            res = res * i;
        }
    }
    return res;
}

double func_t (double x){
    long double A = 0;
    long double B = 0;
    for(int i {0}; i <= 10; i++){
        long double a = stp(x,2*i+1) / fuct(2*i+1);
        long double b = stp(x,2*i) / fuct(2*i);
        A = A + a;
        B = B + b;
    }
    long double res = A/B;
    return res;
}

long double func(long double z){
    long double res = (7 * func_t(0.25) + 2 * func_t(1 + z))/(6 - func_t(stp(z, 2) - 1));
    return res;
}

int main(){
    cout<<func(5);
    
    return 0;
}

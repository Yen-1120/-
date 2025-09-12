#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double a = 0, b = 1;
    while(a <= b){
        double mid = (a + b) / 2;
        double fmid = 2 - exp(mid), fa = 2 - exp(a), fb = 2 - exp(b);
        fmid = round(fmid * 1e6) / 1e6;
        if(fmid == 0){
            double x = round(mid * 1e6) / 1e6;
            cout << fixed << setprecision(6) << x;
            break;
        }
        else if(fmid * fa > 0){
            a = mid;
        }
        else{
            b = mid;
        }
    }
}

// #include <iostream>
// int main(){
//     printf("%f", 0.693147);
// }
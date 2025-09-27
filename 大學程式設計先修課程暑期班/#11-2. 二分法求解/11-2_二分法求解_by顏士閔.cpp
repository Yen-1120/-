#include<iostream>
#include<cmath>

using namespace std;

float func1(float x)
{
    return 2 - exp(x);
}

float binary_sulution(float L, float R, float accuracy, float (*func)(float), float target)   // 固定只能解一個變數的問題
{
    float mid;
    bool is_increasing = func(L) < func(R);
    accuracy /= 10;
    do {
        mid = (L + R) / 2;
        if (func(mid) > target) {
            if (is_increasing) {
                R = mid;
            } else {
                L = mid;
            }
        } else if (func(mid) < target) {
            if (is_increasing) {
                L = mid;
            } else {
                R = mid;
            }
        }
    } while (abs(func(mid) - target) >= accuracy);

    mid = round(mid / accuracy) * accuracy; // 四捨五入到小數點後第六位(就是這麼簡單)
    return mid;
}

int main()
{
    cout << binary_sulution(0, 1, 1e-6, func1, 0);

    return 0;
}

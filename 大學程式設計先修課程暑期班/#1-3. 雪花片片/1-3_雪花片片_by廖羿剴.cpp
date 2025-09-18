#include <iostream>
using namespace std;
int main(){
    int n;
    int nums[100] = {0};
    nums[0] = 1;
    cin >> n;
    for(int i = 1; i < n; i++){
        nums[0] *= 4;
        for(int a = 1; a < 100; a++){
            nums[a] *= 4;
            if(nums[a - 1] >= 10){
                nums[a] += nums[a - 1] / 10;
                nums[a - 1] %= 10;
            }
        }
        nums[0] += 1;
        for(int a = 1; a < 100; a++){
            if(nums[a - 1] == 10){
                nums[a] += 1;
                nums[a - 1] %= 10;
            }
            else break;
        }
    }  
    int ind;
    for(int i = 99; i >= 0; i--){
        ind = i;
        if(nums[i] != 0) break;
    }
    for(int i = ind; i >= 0; i--){
        cout << nums[i];
    }
    return 0;
}
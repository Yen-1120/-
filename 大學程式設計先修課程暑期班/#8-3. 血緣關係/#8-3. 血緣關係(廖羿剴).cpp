#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(){
    int n, p, c, Parent[100000], height[100000] = {0}, mx = -1;
    vector<int> Children[100000];
    cin >> n;
    fill(Parent, Parent + 100000, -1);
    for(int i = 0; i < n - 1; i++){
        cin >> p >> c;
        Parent[c] = p;
        Children[p].push_back(c);
    }
    for(int i = 0; i < n; i++){
        int h = 1, now = i;
        if(Children[i].size() == 0){ //葉節點
            while(now != -1){
                if(h <= height[now]) break; //一定要大於
                height[now] = max(height[now], h); //h
                h++;
                now = Parent[now];
            }
        }
    }
    priority_queue<int> allChild; //allChild會由大到小，就不需要sort了
    for(int i = 0; i < n; i++){
        if(Children[i].size() == 0) continue;
        while(!allChild.empty()) allChild.pop();
        allChild.push(0); allChild.push(0);
        for(auto it : Children[i]){
            allChild.push(height[it]);
        }
        int a = allChild.top(); allChild.pop();
        int b = allChild.top(); allChild.pop();
        mx = max(mx, a + b);
    }
    cout << mx;
}
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int step[8][2] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};
int plate[3][10], n;
vector<int> temp;
vector<vector<int>> p;
bool can = false;

void dfs(int x, int y, int now_step){
    plate[x][y] = now_step;
    if(now_step == 3 * n){
        can = true;
        if(plate[0][0] == 1){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < n; j++){
                    temp.push_back(plate[i][j]);
                }
            }
            p.push_back(temp);
            temp.clear();
        }
        return;
    }
    for(int i = 0; i < 8; i++){
        int xt = x + step[i][0], yt = y + step[i][1];
        if(xt >= 0 && xt < 3 && yt >= 0 && yt < n){ //邊界內
            if(plate[xt][yt] == -1){
                //cout << "由(" << x << ", " << y << ")移動到(" << xt << ", " << yt << ")\n";
                dfs(xt, yt, now_step + 1);
                plate[xt][yt] = -1;
            }
        }
    }
}

int main(){
    cin >> n;
    memset(plate, -1, sizeof(plate));
    dfs(0, 0, 1);
    sort(p.begin(), p.end());
    if(!can) cout << 0;
    else{
        for(int it : p[0]){
            cout << it << " ";
        }
    }
}

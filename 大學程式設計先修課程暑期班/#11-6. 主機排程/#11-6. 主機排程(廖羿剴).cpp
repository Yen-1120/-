#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct host{
    int core, ram, bw;
};

int main(){
    int n, D, m, td, ts, th, c, r, b, stop;
    int in_start, in_end;
    cin >> n >> D;
    D *= 24;
    vector<host> h(D);
    for(int i = 0; i < n; i++){
        for(auto &x : h){
            x = host{0, 0, 0};
        }
        int max_core = -1, max_ram = -1, max_bw = -1;
        cin >> m;
        for(int j = 0; j < m; j++){
            cin >> td >> ts >> th >> c >> r >> b;
            in_start = (td * 24 + ts) % D;
            in_end = in_start + th;
            for(int j = in_start; j < in_end; j++){
                h[j % D].core += c;
                max_core = max(max_core, h[j % D].core);
                h[j % D].ram += r;
                max_ram = max(max_ram, h[j % D].ram);
                h[j % D].bw += b;
                max_bw = max(max_bw, h[j % D].bw);
            }
        }
        cin >> stop;
        cout << max_core << " " << max_ram << " " << max_bw << '\n';
    }
}
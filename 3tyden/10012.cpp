#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 10;

int m;
double rad[MAXN], pos[MAXN];
int ord[MAXN];
bool used[MAXN];
double bestAns;

double gap(double a, double b){ 
    return 2.0 * sqrt(a * b); 
}

double place_x(int id, int count){
    double x = 0.0;
    for (int j = 0; j < count; j++){
        x = max(x, pos[j] + gap(rad[id], rad[ord[j]]));
    }
    return x;
}

double width_now(int cnt){
    double L = 1e100, R = -1e100;
    for (int j = 0; j < cnt; j++){
        int id = ord[j];
        L = min(L, pos[j] - rad[id]);
        R = max(R, pos[j] + rad[id]);
    }
    return R - L;
}

void dfs(int count){
    if (count == m){ 
        bestAns = min(bestAns, width_now(count)); 
        return; 
    }
    for (int i = 0; i < m; i++){
        if (used[i]) continue;
        ord[count] = i;
        pos[count] = place_x(i, count);
        if (width_now(count + 1) < bestAns){
            used[i] = true;
            dfs(count + 1);
            used[i] = false;
        }
    }
}

int main(){
    int input;
    cin >> input;
    cout.setf(ios::fixed);
    cout << setprecision(3);
    while (input--){
        cin >> m;
        for (int i = 0; i < m; ++i){ 
            cin >> rad[i];
        }
        fill(used, used + m, false);
        bestAns = 1e100;
        dfs(0);
        cout << bestAns << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int solve(int i, int j, const vector<int>& cuts, vector<vector<int>>& memo) {
    if (i + 1 == j) { 
        return 0;
    }

    int &best = memo[i][j];

    if (best != -1) { 
        return best;
    }

    best = INT_MAX / 2;

    for (int k = i + 1; k < j; k++) {
        int cost = solve(i, k, cuts, memo) + solve(k, j, cuts, memo) + (cuts[j] - cuts[i]);
        if (cost < best) {
            best = cost;
        }
    }
    return best;
}

int main() {

    int L;
    while ((cin >> L) && L != 0) {
        int n; 
        cin >> n;

        vector<int> cuts(n + 2);
        cuts[0] = 0;

        for (int i = 1; i <= n; i++) {
            cin >> cuts[i];
        }
        
        cuts[n + 1] = L;
        int m = n + 2;
        vector<vector<int>> memo(m, vector<int>(m, -1));

        cout << "The minimum cutting is " << solve(0, m - 1, cuts, memo) << ".\n";
    }
    return 0;
}

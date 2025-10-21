#include <bits/stdc++.h>
using namespace std;

long long maxSumForString(const string& s) {

    int n = (int)s.size();
    vector<long long> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {

        if (s[i] == '0') {
            dp[i] = dp[i + 1];
            continue;
        }

        long long best = 0;
        long long value = 0;

        for (int j = i; j < n && j < i + 10; ++j) {
            value = value * 10 + (s[j] - '0');

            if (value > INT_MAX) {
                break;
            }

            best = max(best, value + dp[j + 1]);
        }
        dp[i] = best;
    }

    return dp[0];
}

int main() {

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string s;
        cin >> s;
        cout << maxSumForString(s) << '\n';
    }
    
    return 0;
}

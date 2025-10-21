#include <bits/stdc++.h>
using namespace std;

static string addStrings(const string& a, const string& b) {

    string res;
    int i = (int)a.size() - 1;
    int j = (int)b.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {
        int s = carry;

        if (i >= 0) {
            s += a[i--] - '0';
        }

        if (j >= 0) {
            s += b[j--] - '0';
        }

        res.push_back(char('0' + (s % 10)));
        carry = s / 10;
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() {

    int T;
    if (!(cin >> T)) return 0;

    while (T--) {
        string X, Z;
        cin >> X >> Z;

        const int m = (int)Z.size();
        vector<string> dp(m + 1, "0");
        dp[0] = "1";

        for (char c : X) {
            // right to left to avoid overwriting dp[j-1] before using it
            for (int j = m; j >= 1; j--) {
                
                if (Z[j - 1] == c) {
                    dp[j] = addStrings(dp[j], dp[j - 1]);
                }
            }
        }
        cout << dp[m] << '\n';
    }
    return 0;
}

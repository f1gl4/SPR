#include <bits/stdc++.h>
using namespace std;

int main() {

    int testCount;
    if (!(cin >> testCount)) return 0;

    for (int tc = 0; tc < testCount; tc++) {
        int numDigits;
        cin >> numDigits;

        vector<int> sumNoCarry(numDigits);
        for (int i = 0; i < numDigits; i++) {
            int a, b;
            cin >> a >> b; // from highest to lowest
            sumNoCarry[i] = a + b;
        }

        string result(numDigits, '0');
        int carry = 0;
        for (int i = numDigits - 1; i >= 0; i--) {
            int s = sumNoCarry[i] + carry;
            result[i] = char('0' + (s % 10));
            carry = s / 10; 
        }

        cout << result << '\n';
        if (tc + 1 < testCount){
            cout << '\n'; 
        }
    }
    return 0;
}

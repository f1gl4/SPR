#include <bits/stdc++.h>
using namespace std;

struct Elephant { 
    int w;
    int iq; 
    int id; 
};

static bool by_weight_iq(const Elephant& a, const Elephant& b) {
    if (a.w != b.w) {
        return a.w < b.w;
    }

    return a.iq > b.iq; 
}

vector<int> build_chain(vector<Elephant> a) {

    sort(a.begin(), a.end(), by_weight_iq);

    int n = (int)a.size();
    vector<int> len(n, 1), parent(n, -1);

    // w - up, iq - down
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[j].w < a[i].w && a[j].iq > a[i].iq && len[j] + 1 > len[i]) {
                len[i] = len[j] + 1;
                parent[i] = j;
            }
        }
    }

    int best = 0;
    for (int i = 1; i < n; ++i) {
        if (len[i] > len[best]) {
            best = i;
        }
    }

    vector<int> seq;
    for (int k = best; k != -1; k = parent[k]) {
        seq.push_back(a[k].id);
    }

    reverse(seq.begin(), seq.end());
    return seq;
}

int main() {

    vector<Elephant> a;
    int w, iq, line = 1;

    while (cin >> w >> iq) {
        a.push_back({w, iq, line++});
    }

    if (a.empty()) { 
        cout << 0 << "\n"; return 0; 
    }

    vector<int> seq = build_chain(move(a));

    cout << seq.size() << "\n";
    for (int id : seq) {
        cout << id << "\n";
    }
    return 0;
}

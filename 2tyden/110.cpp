#include <bits/stdc++.h>
using namespace std;

static const string letters = "abcdefghijklmnopqrstuvwxyz";

void print_space(int n) {
    for (int i = 0; i < n; ++i) cout << ' ';
}

void print_writeln(const vector<char>& order, int space) {
    print_space(space);
    cout << "writeln(";
    for (size_t i = 0; i < order.size(); i++) {
        if (i) cout << ",";
        cout << order[i];
    }
    cout << ")\n";
}


void add_if_chain(char var_name, const vector<char>& order, int pos, int space, function<void(const vector<char>&, int)> after_add)
{
    if (pos == (int)order.size()) {
        auto next = order;
        next.push_back(var_name);
        after_add(next, space);
        return;
    }

    print_space(space);
    cout << "if " << var_name << " < " << order[pos] << " then\n";

    auto next = order;
    next.insert(next.begin() + pos, var_name);
    after_add(next, space);

    print_space(space);
    cout << "else\n";
    add_if_chain(var_name, order, pos + 1, space, after_add);
}



void add_tree(int used, int n, const vector<char>& order, int space) {
    if (used == n) {
        print_writeln(order, space);
        return;
    }
    char cur = letters[used];
    add_if_chain(cur, order, 0, space, [&](const vector<char>& next, int sp){
        add_tree(used + 1, n, next, sp);
    });
}


void add_program(int n) {
    if (n < 1) n = 1;
    if (n > (int)letters.size()) n = (int)letters.size();

    cout << "program sort(input,output);\n";
    cout << "var\n";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ",";
        cout << letters[i];
    }
    cout << " : integer;\n";
    cout << "begin\n";

    cout << "readln(";
    for (int i = 0; i < n; ++i) {
        if (i) cout << ",";
        cout << letters[i];
    }
    cout << ");\n";

    vector<char> order;
    add_tree(0, n, order, 0);

    cout << "end.\n";
}

int main() {

    int m;
    if (!(cin >> m)) return 0;

    vector<int> ns;
    ns.reserve(m);
    for (int i = 0, x; i < m && (cin >> x); i++) {
        ns.push_back(x);
    }


    for (int i = 0; i < (int)ns.size(); i++) {
        if (i) cout << "\n";
        add_program(ns[i]);
    }
    return 0;
}

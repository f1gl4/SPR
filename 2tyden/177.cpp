#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


static const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

static const int flip_dir[4] = {LEFT, RIGHT, DOWN, UP};

static vector<int> make_path(int n) {

    vector<int> dir = {RIGHT};

    for (int i = 1; i <= n; i++) {
        int m = (int)dir.size();
        dir.reserve(m * 2);
        for (int j = m - 1; j >= 0; j--) {
            dir.push_back(flip_dir[dir[j]]);
        }
    }
    return dir; // 2^n
}


static map<int, vector<pair<int,int>>> build_lines(int n) {

    vector<int> dir = make_path(n);
    map<int, vector<pair<int,int>>> lines;

    int px = 0, py = 0;

    for (int d : dir) {
        int x = 0;
        int y = 0;

        if (d == UP) {
            x = px * 2;     
            y = py;     
            lines[y].push_back({x, UP});    
            py++; 
        } else if (d == DOWN) {
            x = px * 2;     
            y = py - 1; 
            lines[y].push_back({x, DOWN});  
            py--; 
        } else if (d == LEFT) {
            x = px * 2 - 1; 
            y = py;     
            lines[y].push_back({x, LEFT});  
            px--; 
        } else /* RIGHT */ {
            x = px * 2 + 1; 
            y = py;     
            lines[y].push_back({x, RIGHT}); 
            px++; 
        }
    }

    for (auto &kv : lines) {
        sort(kv.second.begin(), kv.second.end(),
             [](const pair<int,int>& a, const pair<int,int>& b){ return a.first < b.first; });
    }

    return lines;
}


static void print_picture(const map<int, vector<pair<int,int>>>& lines) {

    int min_x = 1e9;

    for (auto &kv : lines) {
        for (auto &p : kv.second) {
            min_x = min(min_x, p.first);
        }
    }

    for (auto it = lines.rbegin(); it != lines.rend(); it++) {

        int cur_x = min_x;

        for (auto &p : it->second) {

            while (cur_x < p.first) {
                putchar(' '); 
                cur_x++; 
            }

            cur_x++;
            int t = p.second;

            if (t == UP || t == DOWN) {
                putchar('|');
            } else {                     
                putchar('_');
            }
        }

        putchar('\n');
    }

    puts("^");
}

int main() {

    for (int n; (cin >> n) && n; ) {
        auto lines = build_lines(n);
        print_picture(lines);
    }
    return 0;
}

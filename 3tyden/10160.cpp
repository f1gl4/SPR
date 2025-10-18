#include <bits/stdc++.h>
using namespace std;

const int MAXN = 40;

int nearCity[MAXN][MAXN];
int nearCount[MAXN];
int coverTimes[MAXN];
int cityCount, roadCount, minStations;

void search(int city, int stationCount, int coveredCount) {
    if (stationCount >= minStations) return;
    
    if (coveredCount == cityCount) { 
        minStations = stationCount; 
        return; 
    }

    if (city > cityCount) return;

    // 
    for (int i = 1; i < city; i++)
        if (coverTimes[i] == 0 && nearCity[i][0] < city) return;

    // to city
    int newCovered = 0;
    for (int k = 0; k < nearCount[city]; k++) {
        int u = nearCity[city][k];
        if (coverTimes[u] == 0) ++newCovered;
        ++coverTimes[u];
    }

    if (newCovered){
        search(city + 1, stationCount + 1, coveredCount + newCovered);
    }

    for (int k = 0; k < nearCount[city]; k++){ 
        --coverTimes[nearCity[city][k]]; //
    }

    // not to city
    search(city + 1, stationCount, coveredCount);
}

int main() {

    while ((cin >> cityCount >> roadCount) && (cityCount || roadCount)) {
        memset(nearCity, 0, sizeof(nearCity));
        memset(nearCount, 0, sizeof(nearCount));
        memset(coverTimes, 0, sizeof(coverTimes));

        for (int i = 0; i < roadCount; i++) {
            int a, b; 
            cin >> a >> b;
            nearCity[a][nearCount[a]++] = b;
            nearCity[b][nearCount[b]++] = a;
        }
        for (int i = 1; i <= cityCount; i++) {
            nearCity[i][nearCount[i]++] = i;
            sort(nearCity[i], nearCity[i] + nearCount[i], greater<int>()); // down
        }

        minStations = cityCount;
        search(1, 0, 0);
        cout << minStations << '\n';
    }
    return 0;
}

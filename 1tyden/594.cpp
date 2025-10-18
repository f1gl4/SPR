#include <iostream>
#include <cstdint>
#include <iomanip>

using namespace std;

struct Number {
    int32_t value;
};


int32_t swapEndian(int32_t x) {

    uint32_t u = static_cast<uint32_t>(x);

    uint32_t b0 = (u & 0x000000FF) << 24;
    uint32_t b1 = (u & 0x0000FF00) << 8;
    uint32_t b2 = (u & 0x00FF0000) >> 8;
    uint32_t b3 = (u & 0xFF000000) >> 24;

    uint32_t swapped = b0 | b1 | b2 | b3;

    return static_cast<int32_t>(swapped);
}


void printConversion(const Number &num) {
    int32_t converted = swapEndian(num.value);
    cout << num.value << " converts to " << converted << endl;
}

int main() {

    Number num;
    while (cin >> num.value) {
        printConversion(num);
    }

    return 0;
}

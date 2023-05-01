#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long x;
    long y;
    while (cin >> x)
    {
        cin >> y;
        cout << std::labs(x - y) << '\n';
    }
    return 0;
}
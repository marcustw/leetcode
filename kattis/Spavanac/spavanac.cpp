#include <iostream>
using namespace std;

int main() {
    int h, m;
    cin >> h >> m;
    int new_m = m - 45;
    int new_h = h;
    if (new_m < 0)
    {
        new_h = new_h - 1;
        new_m = 60 + new_m;
    }
    if (new_h < 0)
    {
        new_h = 23;
    }
    cout << new_h << ' ' << new_m;
    return 0;
}

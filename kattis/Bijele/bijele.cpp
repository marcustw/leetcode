#include <iostream>
#include <list>
using namespace std;

int main() {
    int ki, q, r, b, kn, p;
    cin >> ki >> q >> r >> b >> kn >> p;
    cout << (1 - ki) << ' ';
    cout << (1 - q) << ' ';
    cout << (2 - r) << ' ';
    cout << (2 - b) << ' ';
    cout << (2 - kn) << ' ';
    cout << (8 - p);
    return 0;
}

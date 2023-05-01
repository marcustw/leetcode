#include <math.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int numDays = 1;
    double req = log(n)/log(2);
    numDays += ceil(req);
    cout << numDays;
    return 0;
}

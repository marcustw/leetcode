#include <iostream>
#include <string>
using namespace std;

int main() {
    string m;
    string d;
    cin >> m >> d;
    if (m.length() >= d.length())
    {
        cout << "go";
    }
    else
    {
        cout << "no";
    }
    return 0;
}

#include <stack>
#include <string>
#include<bits/stdc++.h>
using namespace std;


void showstack(stack<char> s)
{
    string str = "";
    stack<char> stek;
    while (!s.empty())
    {
        str += s.top();
        s.pop();
    }
    reverse(str.begin(), str.end());
    cout << str;
}

int main()
{
    stack<char> stek;
    string s;
    char c;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '<')
        {
            stek.pop();
        }
        else
        {
            stek.push(s[i]);
        }
    }
    showstack(stek);
}

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    

    while (N--)
    {
        string str;
        cin >> str;

        stack<char> s;
        bool isVPS = true;

        for (auto chr : str)
        {
            if (chr == '(')
            {
                s.push(chr);
            }
            else
            {
                if (s.empty())
                {
                    isVPS = false;
                    break;
                }
                s.pop();
            }
        }

        if (!s.empty())
        {
            isVPS = false;
        }

        if (isVPS) cout << "YES\n";
        else cout << "NO\n";
    }
}
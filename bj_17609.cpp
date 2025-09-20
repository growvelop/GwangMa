#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        int str = 0, ed = s.size() - 1;
        int result = 0;

        while (str < ed)
        {
            if (s[str] == s[ed])
            {
                str++; ed--;
            }
            else
            {
                int l1 = str + 1, r1 = ed;
                int l2 = str, r2 = ed - 1;
                bool ok1 = true, ok2 = true;

                while (l1 < r1) 
                {
                    if (s[l1++] != s[r1--])
                    {
                        ok1 = false; 
                        break;
                    }
                }

                while (l2 < r2)
                {
                    if (s[l2++] != s[r2--])
                    {
                        ok2 = false; 
                        break;
                    }
                }

                if (ok1 || ok2) 
                {
                    result = 1;
                }
                else 
                {
                    result = 2;
                }
                break;
            }
        }

        cout << result << "\n";
    }
}

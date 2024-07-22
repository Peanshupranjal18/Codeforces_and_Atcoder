#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    if (s[0] == 'C')
    {
        cout << "NO"
             << "\n";
        return;
    }
    bool flag = false;
    int i = 0, j = 0, cnt = 0;
    while (j < n and cnt < m)
    {
        if (s[j] == 'L')
        {
            i = j;
            flag = true;
            break;
        }
        j++;
        cnt++;
    }
    if (!flag)
    {
        j = 0;
        while (j < n and cnt < m)
        {
            if (s[j] == 'W')
            {
                i = j;
                flag = true;
                break;
            }
            j++;
            cnt++;
        }
    }
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
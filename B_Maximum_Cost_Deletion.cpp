#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    int ans1 = (a + b) * n;
    int ans2 = 0;

    if (b >= 0)
    {
        ans2 = (a + b) * n;
    }
    else
    {
        int segments = 1;
        for (int i = 1; i < n; ++i)
        {
            if (s[i] != s[i - 1])
            {
                segments++;
            }
        }
        ans2 = a * n + b * ((segments / 2) + 1);
    }

    cout << max(ans1, ans2) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}

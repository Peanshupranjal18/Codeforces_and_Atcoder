#include <bits/stdc++.h>
using namespace std;

void run()
{
    int n, m, k;
    cin >> n >> m >> k;
    string A;
    cin >> A;

    vector<int> logs;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 'L')
        {
            logs.push_back(i);
        }
    }
    logs.push_back(n + 1);

    int i = -1;
    int next_log = 0;
    while (i < n - 1)
    {
        if (m >= logs[next_log] - i)
        {
            i = logs[next_log];
        }
        else
        {
            i += m;
            if (i > n - 1)
            {
                cout << "YES\n";
                return;
            }
            while (i < n && i < logs[next_log])
            {
                if (A[i] != 'C' && k > 0)
                {
                    i++;
                    k--;
                }
                else
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
        next_log++;
    }
    cout << "YES\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        run();
    }

    return 0;
}

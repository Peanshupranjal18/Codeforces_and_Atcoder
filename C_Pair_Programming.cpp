#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll k, n, m;
    cin >> k >> n >> m;
    vector<ll> a(n), b(m);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    ll i = 0, j = 0;
    vector<ll> ans;

    while (i < n || j < m)
    {
        bool action_taken = false;

        if (i < n && (a[i] == 0 || a[i] <= k))
        {
            ans.push_back(a[i]);
            if (a[i] == 0)
                k++;
            i++;
            action_taken = true;
        }

        if (j < m && (b[j] == 0 || b[j] <= k))
        {
            ans.push_back(b[j]);
            if (b[j] == 0)
                k++;
            j++;
            action_taken = true;
        }

        if (!action_taken)
        {
            cout << -1 << "\n";
            return;
        }
    }

    for (ll i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return;
}

signed main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
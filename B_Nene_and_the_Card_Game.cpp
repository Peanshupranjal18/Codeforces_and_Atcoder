#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    ll cnt = 0;
    for (ll i = 0; i < n - 1; i++)
    {
        if (v[i] == v[i + 1])
            cnt++;
    }
    cout << cnt << "\n";
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
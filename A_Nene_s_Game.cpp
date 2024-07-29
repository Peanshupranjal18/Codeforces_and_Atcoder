#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll k, q;
    cin >> k >> q;
    vector<ll> a(k);
    for (ll i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    vector<ll> v(q);
    for (ll i = 0; i < q; i++)
    {
        cin >> v[i];
    }

    for (ll i = 0; i < q; i++)
    {
        ll n = v[i];
        vector<bool> kicked(n, false);

        while (true)
        {
            bool any_kicked = false;
            ll count = 0;
            for (ll j = 0; j < n; j++)
            {
                if (!kicked[j])
                {
                    count++;
                    if (binary_search(a.begin(), a.end(), count))
                    {
                        kicked[j] = true;
                        any_kicked = true;
                    }
                }
            }
            if (!any_kicked)
            {
                break;
            }
        }

        ll winners = 0;
        for (ll j = 0; j < n; j++)
        {
            if (!kicked[j])
            {
                winners++;
            }
        }

        cout << winners << " ";
    }
    cout << endl;
}

int main()
{
    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}

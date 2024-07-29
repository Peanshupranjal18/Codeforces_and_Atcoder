#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll solve(ll n, ll x)
{
    ll count = 0;

    for (ll a = 1; a <= min(x - 2, n / 3 + 1); ++a)
    {
        for (ll b = 1; b <= min(x - a - 1, n / a); ++b)
        {
            ll c_max = min(x - a - b, (n - (a * b)) / (a + b));
            if (c_max >= 1)
            {
                count += c_max;
            }
        }
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        cout << solve(n, x) << '\n';
    }

    return 0;
}
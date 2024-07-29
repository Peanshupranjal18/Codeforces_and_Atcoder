#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> A(n), B(n);

    for (int &i : A)
        cin >> i;
    for (int &i : B)
        cin >> i;

    auto getInfo = [&](int cutoff)
    {
        ll ops = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++)
        {
            ll a = A[i];
            ll b = B[i];

            if (cutoff > a)
                continue;

            // a - uses * b >= cutoff
            ll uses = (a - cutoff) / b;
            sum += (uses + 1) * a - b * uses * (uses + 1) / 2;
            ops += uses + 1;

            sum = min(sum, 2 * (ll)1e18);
        }
        return make_pair(sum, ops);
    };

    int L = 0, H = 1e9 + 5;

    while (L < H)
    {
        int M = (L + H) / 2;
        getInfo(M).second <= k ? H = M : L = M + 1;
    }

    // Replace structured binding with separate variable assignments
    pair<ll, ll> result = getInfo(L);
    ll ans = result.first;
    ll opsUse = result.second;
    cout << ans + (k - opsUse) * max(L - 1, 0) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;

    while (tc--)
        solve();
}
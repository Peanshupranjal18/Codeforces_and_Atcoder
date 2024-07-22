#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define ll long long
#define ld long double
#define fl float
#define f(i, n) for (ll i = 0; i < n; i++)
#define ff(i, a, b) for (ll i = a; i < b; i++)
#define vl vector<ll>
#define vll vector<vector<ll>>
#define vpl vector<pair<ll, ll>>
#define fi first
#define sec second
#define all(x) x.begin(), x.end()
#define rev_all(x) x.rbegin(), x.rend()
#define minv *min_element
#define maxv *max_element
#define rt return
#define um unordered_map
#define acc accumulate
#define sz(x) x.size()
#define ub upper_bound
#define lb lower_bound
#define mt multiset
#define rs resize
#define pb push_back
#define mah priority_queue<ll>
#define mih priority_queue<ll, vector<ll>, greater<ll>>
#define mahp priority_queue<pair<ll, ll>>
#define mihp priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
#define PI 3.1415
#define clr(x) x.clear()
#define set_bits __builtin_popcountll
#define MOD 1000000007
#define MOD1 998244353

typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> pbds;

void solve()
{
    ll n, m;
    cin >> n >> m;

    vll v(n, vl(m));
    vl v1;
    f(i, n)
    {
        f(j, m)
        {
            cin >> v[i][j];
            v1.pb(v[i][j]);
        }
    }
    if (n == 1 && m == 1)
    {
        cout << -1 << "\n";
        rt;
    }
    ll x = n * m + 1;
    vll ans(n, vl(m));
    pair<ll, ll> index = {-1, -1};

    f(i, n)
    {
        f(j, m)
        {
            ll a = x - v[i][j];
            if (a != v[i][j])
                ans[i][j] = a;
            else
            {
                ans[i][j] = v[i][j];
                index = {i, j};
            }
        }
    }

    ll a = index.fi, b = index.sec;

    if (a == -1 and b == -1)
    {
        f(i, n)
        {
            f(j, m)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        rt;
    }

    else if (a - 1 >= 0)
    {
        swap(ans[a][b], ans[a - 1][b]);
        f(i, n)
        {
            f(j, m)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        rt;
    }
    else if (a + 1 < n)
    {
        swap(ans[a][b], ans[a + 1][b]);
        f(i, n)
        {
            f(j, m)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        rt;
    }
    else if (b - 1 >= 0)
    {
        swap(ans[a][b], ans[a][b - 1]);
        f(i, n)
        {
            f(j, m)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        rt;
    }
    else if (b + 1 < m)
    {
        swap(ans[a][b], ans[a][b + 1]);
        f(i, n)
        {
            f(j, m)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        rt;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto start = high_resolution_clock::now();

    ll tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() * 1e-6 << " s\n";

    return 0;
}
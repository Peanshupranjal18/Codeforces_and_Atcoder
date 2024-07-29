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
#define vpl vector<pair<ll, ll>>
#define fi first
#define sec second
#define pb push_back
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
    ll n;
    cin >> n;
    vl v(n);
    f(i, n) cin >> v[i];
    ll a = maxv(all(v));
    ll b = minv(all(v));
    ll cnt = 0;
    vl select;
    for (cnt = 0; cnt <= 40; cnt++)
    {
        if (a == 0 and b == 0)
            break;
        ll m1 = (a + b) / 2;
        select.pb(m1);
        b = LLONG_MAX, a = 0;
        for (int i = 0; i < n; i++)
        {
            v[i] -= m1;
            if (v[i] < 0)
                v[i] = -v[i];
            if (v[i] < b)
                b = v[i];
            if (v[i] > a)
                a = v[i];
        }
    }
    if (cnt == 41)
    {
        cout << -1 << "\n";
        rt;
    }
    cout << select.size() << "\n";
    for (ll i = 0; i < select.size(); i++)
        cout << select[i] << " ";
    cout << "\n";
    rt;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    auto start = high_resolution_clock::now();

    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() * 1e-9 << " "
    //      << "s"
    //      << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define print(arr, n)           \
    for (int i = 0; i < n; i++) \
        cout << arr[i] << ' ';
#define int long long
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define dbg(x) cout << #x << " = " << x << "\n"

signed main(void)
{
    fastio();
    int n;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    bool f = false;
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (f == true)
        {
            cout << "No" << '\n';
            return 0;
        }
        if (v[i] == "sweet" && v[i + 1] == v[i])
        {
            f = true;
        }
    }
    cout << "Yes" << '\n';
    return 0;
}
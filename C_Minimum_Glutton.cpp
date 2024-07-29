#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main()
{
    int n;
    ll x, y;
    cin >> n >> x >> y;

    vector<ll> sweet(n), salt(n);
    for (int i = 0; i < n; i++)
        cin >> sweet[i];
    for (int i = 0; i < n; i++)
        cin >> salt[i];

    sort(sweet.rbegin(), sweet.rend());

    sort(salt.rbegin(), salt.rend());

    ll sweet_sum = 0, salt_sum = 0;
    int sweet_count = 0, salt_count = 0;

    for (int i = 0; i < n && sweet_sum <= x; i++)
    {
        sweet_sum += sweet[i];
        sweet_count++;
    }

    for (int i = 0; i < n && salt_sum <= y; i++)
    {
        salt_sum += salt[i];
        salt_count++;
    }

    cout << min(sweet_count, salt_count) << endl;

    return 0;
}
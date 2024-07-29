#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve_test_case()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int max_value = 0;
    for (int i = 0; i < n; i += 2)
    {
        max_value = max(max_value, a[i]);
    }

    return max_value;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve_test_case() << endl;
    }

    return 0;
}
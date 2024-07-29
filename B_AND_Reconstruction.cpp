#include <iostream>
#include <vector>

using namespace std;

void solve_test_case()
{
    int n;
    cin >> n;

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }

    vector<int> a(n);
    a[0] = b[0];
    a[n - 1] = b[n - 2];

    for (int i = 1; i < n - 1; i++)
    {
        a[i] = b[i - 1] | b[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        if ((a[i] & a[i + 1]) != b[i])
        {
            cout << "-1" << endl;
            return;
        }
    }

    // Output the good array
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve_test_case();
    }

    return 0;
}
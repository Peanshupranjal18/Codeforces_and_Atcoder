#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        int n, q;
        cin >> n >> q;

        string a, b;
        cin >> a >> b;

        vector<vector<int>> prefixA(n + 1, vector<int>(26, 0));
        vector<vector<int>> prefixB(n + 1, vector<int>(26, 0));

                for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 26; ++j)
            {
                prefixA[i + 1][j] = prefixA[i][j];
                prefixB[i + 1][j] = prefixB[i][j];
            }
            prefixA[i + 1][a[i] - 'a']++;
            prefixB[i + 1][b[i] - 'a']++;
        }

        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            vector<int> countA(26, 0), countB(26, 0);

            for (int i = 0; i < 26; ++i)
            {
                countA[i] = prefixA[r + 1][i] - prefixA[l][i];
                countB[i] = prefixB[r + 1][i] - prefixB[l][i];
            }

            int changes = 0;
            for (int i = 0; i < 26; ++i)
            {
                changes += abs(countA[i] - countB[i]);
            }

            cout << changes / 2 << "\n";
        }
    }

    return 0;
}

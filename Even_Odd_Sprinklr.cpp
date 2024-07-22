#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
private:
    vector<long long> tree;

public:
    FenwickTree(long long n) : tree(n + 1, 0) {}

    void update(long long i, long long val)
    {
        while (i < tree.size())
        {
            tree[i] += val;
            i += i & (-i);
        }
    }

    long long query(long long i)
    {
        long long sum = 0;
        while (i > 0)
        {
            sum += tree[i];
            i -= i & (-i);
        }
        return sum;
    }
};

vector<long long> solve(vector<long long> &A)
{
    long long n = A.size();
    vector<long long> ans(n, 0);
    vector<pair<long long, long long>> sorted(n);
    for (long long i = 0; i < n; i++)
    {
        sorted[i] = {A[i], i};
    }
    sort(sorted.begin(), sorted.end());

    FenwickTree sumTree(n);
    FenwickTree countTree(n);

    for (long long i = 0; i < n; i++)
    {
        long long index = sorted[i].second;
        long long value = sorted[i].first;

        long long value1 = sumTree.query(index);
        long long value2 = index - countTree.query(index);

        long long result = value1 + (value2 * value);
        ans[index] = (result % 2 == 0) ? 1 : 0;

        sumTree.update(index + 1, value);
        countTree.update(index + 1, 1);
    }

    return ans;
}

int main()
{
    long long tc;
    cin >> tc;
    while (tc--)
    {
        long long n;
        cin >> n;
        vector<long long> A(n);
        for (long long i = 0; i < n; i++)
            cin >> A[i];
        vector<long long> result = solve(A);

        for (long long val : result)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

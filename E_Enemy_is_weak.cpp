#include <bits/stdc++.h>
using namespace std;

#define ll long long

class FenwickTree
{
public:
    vector<int> bit;
    int n;

    FenwickTree(int size)
    {
        n = size;
        bit.assign(n, 0);
    }

    void update(int idx, int val)
    {
        while (idx < n)
        {
            bit[idx] += val;
            idx = idx | (idx + 1);
        }
    }

    int query(int idx)
    {
        int sum = 0;
        while (idx >= 0)
        {
            sum += bit[idx];
            idx = (idx & (idx + 1)) - 1;
        }
        return sum;
    }

    int rangeQuery(int l, int r)
    {
        if (l > r)
            return 0;
        return query(r) - (l > 0 ? query(l - 1) : 0);
    }
};

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> left(n), right(n);

    FenwickTree leftTree(n + 1), rightTree(n + 1);
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> rank;
    for (int i = 0; i < n; i++)
        rank[sortedArr[i]] = i + 1;

    for (int i = 0; i < n; i++)
    {
        left[i] = leftTree.query(n) - leftTree.query(rank[arr[i]]);
        leftTree.update(rank[arr[i]], 1);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = rightTree.query(rank[arr[i]] - 1);
        rightTree.update(rank[arr[i]], 1);
    }

    ll result = 0;
    for (int i = 0; i < n; i++)
        result += (ll)left[i] * right[i];

    cout << result << "\n";
    return 0;
}
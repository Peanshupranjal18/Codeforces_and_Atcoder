#include <bits/stdc++.h>
using namespace std;
#define ll long long

class SegmentTree
{
    vector<ll> tree;
    vector<ll> array;
    vector<ll> count_of_min;
    int n;

private:
    void buildTree(int node, int start, int end)
    {
        if (start == end)
        {
            tree[node] = array[start];
            count_of_min[node] = 1;
            return;
        }
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);

        if (tree[2 * node] == tree[2 * node + 1])
        {
            tree[node] = tree[2 * node];
            count_of_min[node] = count_of_min[2 * node] + count_of_min[2 * node + 1];
        }
        else if (tree[2 * node] < tree[2 * node + 1])
        {
            tree[node] = tree[2 * node];
            count_of_min[node] = count_of_min[2 * node];
        }
        else
        {
            tree[node] = tree[2 * node + 1];
            count_of_min[node] = count_of_min[2 * node + 1];
        }
    }

    void updateTree(int node, int start, int end, int index, ll value)
    {
        if (start == end)
        {
            array[index] = value;
            tree[node] = value;
            count_of_min[node] = 1;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            updateTree(2 * node, start, mid, index, value);
        else
            updateTree(2 * node + 1, mid + 1, end, index, value);

        if (tree[2 * node] == tree[2 * node + 1])
        {
            tree[node] = tree[2 * node];
            count_of_min[node] = count_of_min[2 * node] + count_of_min[2 * node + 1];
        }
        else if (tree[2 * node] < tree[2 * node + 1])
        {
            tree[node] = tree[2 * node];
            count_of_min[node] = count_of_min[2 * node];
        }
        else
        {
            tree[node] = tree[2 * node + 1];
            count_of_min[node] = count_of_min[2 * node + 1];
        }
    }

    pair<ll, ll> queryTree(int node, int start, int end, int left, int right)
    {
        if (left > end || right < start)
            return {LLONG_MAX, 0};

        if (left <= start && end <= right)
            return {tree[node], count_of_min[node]};

        int mid = (start + end) / 2;
        pair<ll, ll> leftResult = queryTree(2 * node, start, mid, left, right);
        pair<ll, ll> rightResult = queryTree(2 * node + 1, mid + 1, end, left, right);

        if (leftResult.first == rightResult.first)
        {
            return {leftResult.first, leftResult.second + rightResult.second};
        }
        else if (leftResult.first < rightResult.first)
        {
            return leftResult;
        }
        else
        {
            return rightResult;
        }
    }

public:
    SegmentTree(vector<ll> &arr) : array(arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        count_of_min.resize(4 * n);
        buildTree(1, 0, n - 1);
    }

    void update(int index, ll value)
    {
        updateTree(1, 0, n - 1, index, value);
    }

    pair<ll, ll> query(int left, int right)
    {
        return queryTree(1, 0, n - 1, left, right);
    }
};

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    SegmentTree segTree(v);

    for (int i = 0; i < m; i++)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll b, c;
            cin >> b >> c;
            segTree.update(b, c);
        }
        else
        {
            ll b, c;
            cin >> b >> c;
            pair<ll, ll> ans = segTree.query(b, c - 1);
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    return;
}

int main()
{
    solve();
    return 0;
}
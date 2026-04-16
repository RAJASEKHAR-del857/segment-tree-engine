
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree, lazy;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        lazy.resize(4*n, 0);
        build(arr, 0, 0, n-1);
    }

    void build(vector<int>& arr, int node, int start, int end) {
        if (start == end) tree[node] = arr[start];
        else {
            int mid = (start+end)/2;
            build(arr, 2*node+1, start, mid);
            build(arr, 2*node+2, mid+1, end);
            tree[node] = tree[2*node+1] + tree[2*node+2];
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end-start+1)*lazy[node];
            if (start != end) {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);

        if (r < start || end < l) return;

        if (l <= start && end <= r) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }

        int mid = (start+end)/2;
        updateRange(2*node+1, start, mid, l, r, val);
        updateRange(2*node+2, mid+1, end, l, r, val);

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int query(int node, int start, int end, int l, int r) {
        propagate(node, start, end);

        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node];

        int mid = (start+end)/2;
        return query(2*node+1, start, mid, l, r) +
               query(2*node+2, mid+1, end, l, r);
    }
};

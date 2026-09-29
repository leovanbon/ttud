#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> tree(2 * n);

    // Leaves
    for (int i = 0; i < n; i++) {
        cin >> tree[n + i];
    }

    // Build
    for (int i = n - 1; i > 0; i--) {
        tree[i] = min(tree[i << 1], tree[i << 1 | 1]);
    }

    // query minimum on [l, r)
    auto query = [&](int l, int r) {
        int ans = INT_MAX;

        l += n;
        r += n;

        while (l < r) {
            if (l & 1) {
                ans = min(ans, tree[l]);
                l++;
            }

            if (r & 1) {
                r--;
                ans = min(ans, tree[r]);
            }

            l >>= 1;
            r >>= 1;
        }

        return ans;
    };

    int m;
    cin >> m;

    long long Q = 0;

    while (m--) {
        int i, j;
        cin >> i >> j;

        Q += query(i, j + 1);
    }

    cout << Q << '\n';

    return 0;
}
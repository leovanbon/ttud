#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, r, c;
    cin >> n >> m >> r >> c;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    r-- ; c-- ;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int,int>> q;

    q.push({r,c});
    dist[r][c] = 0;

    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};

    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();

        for (int k =0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist[x][y] + 1;
                return 0;
            }

            if (a[nx][ny] == 1 || dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[x][y] +1;
            q.push({nx,ny});
        }
    }
    
    cout << -1;
}
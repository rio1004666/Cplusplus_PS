#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define NM 105
using namespace std;
typedef long long int ll;
int N, M, K, R, C;
char a[NM][NM];
ll dp[505][NM][NM];
int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int MOD = 1000000007;
void input() {
    cin >> N >> M >> K;
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            cin >> a[i][j];
            if (a[i][j] == 'S') R = i, C = j;
        }
    }
}
void pro() {
    for (int k=0;k<=K;k++) for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) dp[k][i][j] = 0;
    dp[0][R][C] = 1;
    ll ans = 0;
    for (int k=0;k<K;k++){
        for (int r=1;r<=N;r++){
            for (int c=1;c<=M;c++){
                if (a[r][c] == 'X') continue;
                for (int d=0;d<4;d++){
                    int nr = r + dir[d][0], nc = c + dir[d][1];
                    if (nr < 1 || nc < 1 || nr > N || nc > M) {
                        ans += dp[k][r][c];
                        ans %= MOD;
                        continue;
                    }
                    if (a[nr][nc] == 'X') continue;
                    dp[k + 1][nr][nc] += dp[k][r][c];
                    dp[k + 1][nr][nc] %= MOD;
                }
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    freopen("../input.txt", "r", stdin);
//    freopen("output.txt","w", stdout);
    int TT;
    cin >> TT;
    for (int tt = 1; tt <= TT; tt++) {
        input();
        cout << "#" << tt << " ";
        pro();
    }
    return 0;
}

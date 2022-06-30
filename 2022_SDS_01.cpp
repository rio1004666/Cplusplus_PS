#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define NM 100005
using namespace std;
typedef long long int ll;
int N, M, D;
int a[NM];
deque<int> dq;
void input() {
    cin >> N >> M >> D;
    int idx = 0;
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> a[++idx];
    sort(a + 1, a + 1 + N * M);
    dq.clear();
    for (int i = N * M; i >= 1; i--) dq.push_back(a[i]);
}
void pro() {
    ll ans = 0;
    for (int day = 1; day <= D; day++) {
        int K;
        cin >> K;
        for (int i = 1; i <= K; i++) {
            int height = dq.front();
            dq.pop_front();
            ans += (height + day - 1) * day;
            dq.push_back(1 - day);
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

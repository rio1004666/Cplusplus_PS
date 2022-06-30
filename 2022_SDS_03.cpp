#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define NM 105
using namespace std;
typedef long long int ll;
int N, costs[20], ans, cnt[4][2];
const int SELECT = 1;
const int UNSELECT = -1;
void input() {
    cin >> N;
    for (int i=0;i<16;i++) cin >> costs[i];
}
void update(int idx, int val){
    for (int i=0;i<4;i++){
        cnt[i][idx % 2] += val;
        idx /= 2;
    }
}
void backtracking(int idx, int cost) {
    if (idx == 16) {
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++)
                if (cnt[i][j] < N)
                    flag = false;
        }
        if (flag) ans = min(ans, cost);
        return;
    }
    update(idx, SELECT);
    backtracking(idx + 1, cost + costs[idx]);
    update(idx, UNSELECT);
    backtracking(idx + 1, cost);
}
void pro() {
    ans = 0x7fffffff;
    backtracking(0, 0);
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

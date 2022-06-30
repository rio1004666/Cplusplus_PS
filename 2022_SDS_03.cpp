#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
// 가장 나이브하게 완전탐색을 생각해본다 

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
        cnt[i][idx % 2] += val; // 비트마스킹으로 표현 가능하다 0번째 사람은 0000  1번째 사람은 0001 
        idx /= 2;
    }
}
void backtracking(int idx, int cost) {
    if (idx == 16) {
        bool flag = true;
        // 가능한 성향 8가지 각각이 모든 사람에 걸쳐서 전부 T명이상이 되었으면 한다  
        // 비트마스킹형식으로 테크니컬하게 짯지만 그냥 0번째 사람의 성향에 대해 각 성향 선택을 하게 하면된다 
		// ENFJ면 0000이 되므로 cnt[0][0] cnt[1][0] cnt[2][0] cnt[3][0]에 +1 씩 사람수가  추가된다 
		// ENFP면 00001이 되므로 cnt[0][0] cnt[1][0] cnt[2][0] cnt[3][1]에 +1 이 사람 수가 추가된다 
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 2; j++)
            	// 해당하는 각 MBTI 유형에 모든 사람들이 N명이상있으면 통과 아니면 실패  
                if (cnt[i][j] < N)
                    flag = false;
        }
        // N명이상의 사람들이 각각 모든 MBTI유형에 조건이 만족되면 최소연봉 업데이트  
        if (flag) ans = min(ans, cost);
        return;
    }
    update(idx, SELECT); // 이 사람을 고용했을 경우 mbti유형에 해당하는 곳을 +1 증가시킨다  
    // 선택을 했을 경우  
    backtracking(idx + 1, cost + costs[idx]);
    // 선택을 하지 않았을 경우  
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

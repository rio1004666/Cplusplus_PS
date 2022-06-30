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
    // 시간복잡도상 줄이려면 2차원격자에 있는 숫자들만 전부 담아서 정렬후 큐에 큰값부터 넣어서 내림차순 정렬한다  
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) cin >> a[++idx];
    sort(a + 1, a + 1 + N * M);
    dq.clear();
    for (int i = N * M; i >= 1; i--) dq.push_back(a[i]);
}
void pro() {
    ll ans = 0;
    for (int day = 1; day <= D; day++) {
        // 매 라운드 즉 하루가 지날 때마다 STEP1과 STEP2를 수행한다  
		int K;
        cin >> K;
        for (int i = 1; i <= K; i++) {
            int height = dq.front(); // 내림차순으로 이미 정렬되어 잇기때문에 가장 앞에 있는 수가 최댓값이고 그다음 큰값이 뒤를 이어 나타나므로 K 번 반복하면 최상위 숫자 K개 합이 더해진다. 
            dq.pop_front();
            // 우선 현재 height값에서 day만큼 지났으므로 + day를 갈겨준다 
			// 근데 문제는 step1에서 모든 값에 1을 더하는것을 큐에도 적용한다면 의미가 없어진다. 
			// 큐에 다른 숫자를 만들어서 모든 원소의 특정한 값을 더해진거다라고 최면을 건다 
			// day가 3이면 8 7 4 2가 큐에 들어있다면 모든 원소에 이미 3이 들어있다고 생각한다
			// 모든 원소에 굳이 1씩 더한다고 생각하지말고 이미 3이 추가되어있다고 생각하고 
			//  11 10 7 5 가 되어 있다고 생각하는것이다 
			// 그리고 1로 바꾸어서 넣을 때에는  day만큼 빼주고 넣어야 1이된다 원래 day만큼 더한상태엿으므로 
			// 그리고 day만큼 흘렀으므로 * day를 해준다 => 문제에서 day를 곱해라는 말이 나왓을 듯  
			// 즉 일일이 더하는것보다 라운드수가 지나간만큼 더해주기만 하면 복잡도 1이된다  
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

//  bfs 탐색을 활용하여 최단거리 기록을 이용한다 각 지점에서 출발하여 모든 지점에 최단거리로 도착하는 2차원 격자를 여러개 백업하기 위해 3차원배열을 이용한다
// 이것도 A,B,C 순서가 최단거리에 영향을 미치므로 순열을 이용하는 브루트 포스와 최단시간 기록을 하는 BFS가 합쳐진 문제이다. 
 
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define NM 105
using namespace std;
typedef long long int ll;
int N, M, R[5], C[5];
int dist[5][NM][NM]; 
// 이 자료구조는 2차원 격자를 총 4개의 판으로 구성하기 위해 3차원 배열을 정의하였다 0번쨰는 출발지점 1번째는 A지정 2번째는 B지점 3번째는 C지점으로부터 출발하여 각 최소거리를 구하는 데이터를 기록함. 
// 즉 핵심은 미리 전처리로 구해놓으면 복잡도 1로 해결될 수 잇다  
char a[NM][NM];
int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void input() {
    cin >> N >> M >> R[0] >> C[0];
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            cin >> a[i][j];
            // 각 지점을 배열로 정의해놓으면 반복문 사용하기가 편리하다  
            if (a[i][j] == 'A') R[1] = i, C[1] = j;
            if (a[i][j] == 'B') R[2] = i, C[2] = j;
            if (a[i][j] == 'C') R[3] = i, C[3] = j;
            if (a[i][j] == 'S') R[4] = i, C[4] = j;
        }
    }
}
void get_dist(int startR, int startC, int dist[][NM]) {
    queue<int> Q;
    Q.push(startR);
    Q.push(startC);
    for (int i = 1; i <= N; i++) for (int j = 1; j <= M; j++) dist[i][j] = -1;
    dist[startR][startC] = 0;
    while (!Q.empty()) {
        int r = Q.front();
        Q.pop();
        int c = Q.front();
        Q.pop();
        for (int k = 0; k < 4; k++) {
            int nr = r + dir[k][0], nc = c + dir[k][1];
            if (nr < 1 || nc < 1 || nr > N || nc > M) continue;
            if (a[nr][nc] == 'X') continue;
            if (dist[nr][nc] != -1) continue;
            dist[nr][nc] = dist[r][c] + 1;
            Q.push(nr);
            Q.push(nc);
        }
    }
}
void pro() {
	// A,B,C 중 순서에 따라 결과가 즉 최솟가되는 경로 비용이 달라지므로 순영 3! 을 하드코딩한다 이렇게 경우의 수가 얼마 안되는 경우에는 그냥 하드코딩한다  
    int paths[][4] = {{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}};
    // 시작점, A, B,C 각각 지점에서 출발하여 다른 지점까지 최단경로를 dist 2차원 격자배열을 또 여러개 만들어 각각 저장한다 
	// dist[0][N][M]은 첫번째 R[0]C[0]에서 출발했을 떄 A,B,C,에 도착하면서 최소비용이 드는 데이터를 기록한다 
	// dist[1][N][M]은 두번째 R[1]C[1] 즉 A에서 B,C로 도착했을 때 최소 비용이 드는 데이터를 기록한다. 
	for (int i=0;i<4;i++) get_dist(R[i], C[i], dist[i]);
    int ans = 0x7fffffff;
    for (int i=0;i<6;i++){
    	// 첫번째 0,1,2,3은 특정 출발지점부터 A,B,C순서대로 거쳐서 이동했을 경우 최소값을 구하는 과정이다 . 
        int sum = 0;
        for (int k=0;k<3;k++){ // 먼저 특정 지점에서 A까지 최단경로는 dist[0]에 기록되어 잇따 
		 
            int cur = paths[i][k], next = paths[i][k + 1]; // cur은 현재 출발지점으로부터 각 A,B,C,까지 기록되어 있는 판을 가져온다는 의미이고 
			// next는 그다음 지점인 A지점의 인덱스를 불러오기 위한 것이다  
            sum += dist[cur][R[next]][C[next]]; // dist[0][1][1]은 특정출발지점으로부터 A까지의 거리이다.
			// 그 후 A->B   B->C까지의 거리를 최종적으로 구할 수 있다  
        }
        // 여기서 맨해튼 거리를 사용하여 시간복잡도를 낮추엇다 BFS를 써도 상관없지만 검을 쥐고나서 더이상 맹수를 피할 필요가 없으므로 굳이 BFS를 써가며 탐색할 필요가 없어졋다  
        sum += abs(R[paths[i][3]] - R[4]) + abs(C[paths[i][3]] - C[4]);
        ans = min(ans, sum);
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

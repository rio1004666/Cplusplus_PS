//  bfs Ž���� Ȱ���Ͽ� �ִܰŸ� ����� �̿��Ѵ� �� �������� ����Ͽ� ��� ������ �ִܰŸ��� �����ϴ� 2���� ���ڸ� ������ ����ϱ� ���� 3�����迭�� �̿��Ѵ�
// �̰͵� A,B,C ������ �ִܰŸ��� ������ ��ġ�Ƿ� ������ �̿��ϴ� ���Ʈ ������ �ִܽð� ����� �ϴ� BFS�� ������ �����̴�. 
 
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
// �� �ڷᱸ���� 2���� ���ڸ� �� 4���� ������ �����ϱ� ���� 3���� �迭�� �����Ͽ��� 0������ ������� 1��°�� A���� 2��°�� B���� 3��°�� C�������κ��� ����Ͽ� �� �ּҰŸ��� ���ϴ� �����͸� �����. 
// �� �ٽ��� �̸� ��ó���� ���س����� ���⵵ 1�� �ذ�� �� �մ�  
char a[NM][NM];
int dir[][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
void input() {
    cin >> N >> M >> R[0] >> C[0];
    for (int i=1;i<=N;i++){
        for (int j=1;j<=M;j++){
            cin >> a[i][j];
            // �� ������ �迭�� �����س����� �ݺ��� ����ϱⰡ ���ϴ�  
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
	// A,B,C �� ������ ���� ����� �� �ּڰ��Ǵ� ��� ����� �޶����Ƿ� ���� 3! �� �ϵ��ڵ��Ѵ� �̷��� ����� ���� �� �ȵǴ� ��쿡�� �׳� �ϵ��ڵ��Ѵ�  
    int paths[][4] = {{0, 1, 2, 3}, {0, 1, 3, 2}, {0, 2, 1, 3}, {0, 2, 3, 1}, {0, 3, 1, 2}, {0, 3, 2, 1}};
    // ������, A, B,C ���� �������� ����Ͽ� �ٸ� �������� �ִܰ�θ� dist 2���� ���ڹ迭�� �� ������ ����� ���� �����Ѵ� 
	// dist[0][N][M]�� ù��° R[0]C[0]���� ������� �� A,B,C,�� �����ϸ鼭 �ּҺ���� ��� �����͸� ����Ѵ� 
	// dist[1][N][M]�� �ι�° R[1]C[1] �� A���� B,C�� �������� �� �ּ� ����� ��� �����͸� ����Ѵ�. 
	for (int i=0;i<4;i++) get_dist(R[i], C[i], dist[i]);
    int ans = 0x7fffffff;
    for (int i=0;i<6;i++){
    	// ù��° 0,1,2,3�� Ư�� ����������� A,B,C������� ���ļ� �̵����� ��� �ּҰ��� ���ϴ� �����̴� . 
        int sum = 0;
        for (int k=0;k<3;k++){ // ���� Ư�� �������� A���� �ִܰ�δ� dist[0]�� ��ϵǾ� �յ� 
		 
            int cur = paths[i][k], next = paths[i][k + 1]; // cur�� ���� ����������κ��� �� A,B,C,���� ��ϵǾ� �ִ� ���� �����´ٴ� �ǹ��̰� 
			// next�� �״��� ������ A������ �ε����� �ҷ����� ���� ���̴�  
            sum += dist[cur][R[next]][C[next]]; // dist[0][1][1]�� Ư������������κ��� A������ �Ÿ��̴�.
			// �� �� A->B   B->C������ �Ÿ��� ���������� ���� �� �ִ�  
        }
        // ���⼭ ����ư �Ÿ��� ����Ͽ� �ð����⵵�� ���߾��� BFS�� �ᵵ ��������� ���� ����� ���̻� �ͼ��� ���� �ʿ䰡 �����Ƿ� ���� BFS�� �ᰡ�� Ž���� �ʿ䰡 �����  
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

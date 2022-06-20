// �ϴ� naive�ϰ� �����ϸ� �ð��ʰ� �׳� naive�ϰ� Ǯ���� �� ����ȴ� ������ �����ȳ���
// ȿ�������� �������� �˰����� ���÷����� dp, �̺�Ž��, �ڷᱸ�� map ��� ����  

#include <iostream>
using namespace std;

#define MAX 500

int N, M, Answer;
int DP[MAX][MAX];
bool Visit[MAX][MAX];
char Map[MAX][MAX];

int dy[] = {0,0,1,-1}; // �ε����� �޶����� ������ �޶����Ƿ� ��������  
int dx[] = {1,-1,0,0};
void Input()
{
	cin >> N >> M;
	for(int i = 0 ; i < N; i++){
		for(int j = 0 ; j < M ; j++){
			cin >> Map[i][j];
			DP[i][j] = -1;
		}
	}
}
int Dir_To_Idx(char A){
	if(A == 'U') return 3;
	else if(A == 'R') return 0;
	else if(A == 'D') return 2;
	else if(A == 'L') return 1;
	
}

int DFS(int y, int x){
	
	if(y < 0 || x < 0|| y >= N || x >= M ){return 1;} // ������ Ž���ϴٰ� ������ ����� Ż�Ⱑ���� ĭ�̶�� ����  
	// �� ���� ���ǹ��� ���������̴� Ž���� ��������  
	if(DP[y][x] != -1) {return DP[y][x];} // �̹� Ż���� ĭ�̶�� ���̻� ���͵� ���� Ż���� ĭ�̴� �Ǵ� �湮�� ������ Ż��Ұ����� ĭ�̶�� ���̻� Ž������ �ʾƵ� �ȴ� 
	// ���� ���ǹ��� �ѹ� �湮�Ѱ��� �湮���� �ʴ´ٴ� �ǹ̿� �Բ� Ż���߳� ���߳ĸ� ����ϴ� ������ ���������̴� ( ȿ���� )
 
	DP[y][x] = 0; // �ϴ� �湮�߰� Ż����� ĭ�̶�� ���� 
	int dir = Dir_To_Idx(Map[y][x]); // ���ڷε� ������ ���ڷ� �ٲٴ� �޼���  
	DP[y][x] = DFS(y+dy[dir],x+dx[dir]); // �״���ĭ�� Ž���Ѵ� �׸��� ���ƿ��� �� ĭ�� Ż�Ⱑ���� ĭ���� �˰Եȴ� (��Ʈ��ŷ) 
	return DP[y][x];
	
}
void Solution(){
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			Answer += DFS(i,j);
		}
	}
	cout << Answer << '\n';
}
void Solve()
{
	
	Input();
	Solution();
	
}
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
	
}

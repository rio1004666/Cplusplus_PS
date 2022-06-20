// 일단 naive하게 생각하면 시간초과 그냥 naive하게 풀더라도 걍 내면된다 도저히 생각안나면
// 효율성에서 여러가지 알고리즘을 떠올려본다 dp, 이분탐색, 자료구조 map 등등 많다  

#include <iostream>
using namespace std;

#define MAX 500

int N, M, Answer;
int DP[MAX][MAX];
bool Visit[MAX][MAX];
char Map[MAX][MAX];

int dy[] = {0,0,1,-1}; // 인덱스가 달라지면 방향이 달라지므로 조심하자  
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
	
	if(y < 0 || x < 0|| y >= N || x >= M ){return 1;} // 끝까지 탐색하다가 범위를 벗어나면 탈출가능한 칸이라고 본다  
	// 즉 위의 조건문은 종료조건이다 탐색의 종료조건  
	if(DP[y][x] != -1) {return DP[y][x];} // 이미 탈출한 칸이라면 더이상 볼것도 없이 탈출한 칸이다 또는 방문은 했지만 탈출불가능한 칸이라면 더이상 탐색하지 않아도 된다 
	// 위의 조건문은 한번 방문한것은 방문하지 않는다는 의미와 함께 탈출했냐 안했냐를 기록하는 것으로 종료조건이다 ( 효율성 )
 
	DP[y][x] = 0; // 일단 방문했고 탈출안한 칸이라고 본다 
	int dir = Dir_To_Idx(Map[y][x]); // 문자로된 방향을 숫자로 바꾸는 메서드  
	DP[y][x] = DFS(y+dy[dir],x+dx[dir]); // 그다음칸을 탐색한다 그리고 돌아오면 이 칸이 탈출가능한 칸인지 알게된다 (백트래킹) 
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

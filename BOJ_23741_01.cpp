// 각 노드에 연결된 간선부터 탐색한다 BFS 
// 각 노드마다 인접 노드와 교환횟수를 기록한다 그래야 그 다음 인접 노드와 교환했을 경우 공이 어디로 가는지 알 수 잇다 
// 인덱스에 각 노드에 공이 있었을 때 교환횟수도 같이 기록해두었다가 나중에 그 노드에 도착했을 때 공이 있다면 그 다음 인접 노드와 교환하면 다음 후보노드가 된다는.... 
// 또 1번바꾸엇을 경우 인접한 노드들을 방문하여 기록해주고 2번 바꾸엇을 경우 다시 그 노드의 인접노드를 기록해주는 방식으로 하면 해결된다. 
// 모든 노드를 각 1번 2번 3번..Y번 바꿨을 경우 전부 탐색한다

// 현재 노드 기준으로 인접한 모든 노드와 1번 바꾸었을 경우 공이 있을 노드들의 후보가 된다 
// 이것을 기록해두어야 한다 예를 들어 1번 노드에서 인접한 노드가 2번과 6번이면 
// 1번 바꾸었을 경우 2번노드에 공이 있을것이므로 DP[2][1] 로 2번노드에 1번바꾸었는데 공이 있다로 체크해준다 
// 마찬가지로 6번노드에도 공이 있을 것이므로 DP[6][1]로 체크해준다 
// 그 다음에 두번째 바꿀때 DP[2][1] 이 true이므로 이 2번노드에 다시 인접한 노드들을 방문하여
// 2번 바꾸엇을 경우 인접한 노드 1번과 3번 노드에도 체크해준다 즉 DP[1][2] 와 DP[3][2] 에 true가 된다
// 이렇게 여러개의 알고리즘과 자료구조가 섞인다    

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int N,M,X,Y;

bool visited[MAX][MAX]; // i번 노드에 j번 교환했다  

vector<vector<int>> graph(MAX);

queue<int> q;

void Input(){

	cin >> N  >> M >> X >> Y;
	for(int i = 0 ; i < M ;  i++){
		int s,e;
		cin >> s >> e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}

}
void BFS(int start, int cnt){
	q.push(start);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		for(int  i = 0 ; i < graph[start].size() ; i++){ // 인접한 노드수 2개 
			int next = graph[start][i];
			visited[next][cnt + 1] = true;
		}
	}
}
void Solution(){
	for(int i = 0 ; i < N ; i++){ // 100만 
		for(int j = 0 ; j < N ; j++){
			visited[i][j] = false;
		}
	}
	if(graph[X].size() == 0){
		cout << -1 << '\n';
		
	} 
	else{ // N^2도 된다  
		visited[X][0] = true; // 시작점은 이미 방문한것으로 친다  
		for(int i = 0 ; i < Y ; i++){ // Y <= 1000 
			for(int j = 1; j <= N ; j++){ // N <= 1000
				// 여기서 인접한 노드수 2개가 최소탐색  
				if(visited[j][i]){ // 현재 노드가 j번 바꿔치기해서 가지고 있다면 
					BFS(j,i); // 현재 노드를 기준으로 인접한 노드와 또 바꿔치기한다  
				}
			}
		} // 100만 x 2....이상  
		for(int  i = 1; i <= N ; i++){
			if(visited[i][Y]){ // Y번 교환했더니 공이 있었던 모든 자신의 노드들을 출력한다  
				cout << i << ' ';
			}
		}
	}
}
void Solve(){
	
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

// �� ��忡 ����� �������� Ž���Ѵ� BFS 
// �� ��帶�� ���� ���� ��ȯȽ���� ����Ѵ� �׷��� �� ���� ���� ���� ��ȯ���� ��� ���� ���� ������ �� �� �մ� 
// �ε����� �� ��忡 ���� �־��� �� ��ȯȽ���� ���� ����صξ��ٰ� ���߿� �� ��忡 �������� �� ���� �ִٸ� �� ���� ���� ���� ��ȯ�ϸ� ���� �ĺ���尡 �ȴٴ�.... 
// �� 1���ٲپ��� ��� ������ ������ �湮�Ͽ� ������ְ� 2�� �ٲپ��� ��� �ٽ� �� ����� ������带 ������ִ� ������� �ϸ� �ذ�ȴ�. 
// ��� ��带 �� 1�� 2�� 3��..Y�� �ٲ��� ��� ���� Ž���Ѵ�

// ���� ��� �������� ������ ��� ���� 1�� �ٲپ��� ��� ���� ���� ������ �ĺ��� �ȴ� 
// �̰��� ����صξ�� �Ѵ� ���� ��� 1�� ��忡�� ������ ��尡 2���� 6���̸� 
// 1�� �ٲپ��� ��� 2����忡 ���� �������̹Ƿ� DP[2][1] �� 2����忡 1���ٲپ��µ� ���� �ִٷ� üũ���ش� 
// ���������� 6����忡�� ���� ���� ���̹Ƿ� DP[6][1]�� üũ���ش� 
// �� ������ �ι�° �ٲܶ� DP[2][1] �� true�̹Ƿ� �� 2����忡 �ٽ� ������ ������ �湮�Ͽ�
// 2�� �ٲپ��� ��� ������ ��� 1���� 3�� ��忡�� üũ���ش� �� DP[1][2] �� DP[3][2] �� true�� �ȴ�
// �̷��� �������� �˰���� �ڷᱸ���� ���δ�    

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 1001

int N,M,X,Y;

bool visited[MAX][MAX]; // i�� ��忡 j�� ��ȯ�ߴ�  

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
		for(int  i = 0 ; i < graph[start].size() ; i++){ // ������ ���� 2�� 
			int next = graph[start][i];
			visited[next][cnt + 1] = true;
		}
	}
}
void Solution(){
	for(int i = 0 ; i < N ; i++){ // 100�� 
		for(int j = 0 ; j < N ; j++){
			visited[i][j] = false;
		}
	}
	if(graph[X].size() == 0){
		cout << -1 << '\n';
		
	} 
	else{ // N^2�� �ȴ�  
		visited[X][0] = true; // �������� �̹� �湮�Ѱ����� ģ��  
		for(int i = 0 ; i < Y ; i++){ // Y <= 1000 
			for(int j = 1; j <= N ; j++){ // N <= 1000
				// ���⼭ ������ ���� 2���� �ּ�Ž��  
				if(visited[j][i]){ // ���� ��尡 j�� �ٲ�ġ���ؼ� ������ �ִٸ� 
					BFS(j,i); // ���� ��带 �������� ������ ���� �� �ٲ�ġ���Ѵ�  
				}
			}
		} // 100�� x 2....�̻�  
		for(int  i = 1; i <= N ; i++){
			if(visited[i][Y]){ // Y�� ��ȯ�ߴ��� ���� �־��� ��� �ڽ��� ������ ����Ѵ�  
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

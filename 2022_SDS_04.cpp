#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define FOR(i,n,m) for (int i=(n);i<=(m);i++)
#define NN 10005
#define NM 1005
using namespace std;
typedef long long int ll;
int N, M, S, E, cntNodes[NM], dist[NM], visit_node[NN], visit_line[NM];
vector<int> nodes[NN];  // nodes[i] := i 번 정류장 속한 노선 번호들
vector<int> lines[NM];  // lines[i] := i 번 노선에 속한 정류 번호들
void input() {
    cin >> N >> M >> S >> E;
    for (int i = 1; i <= M; i++) {
        cin >> cntNodes[i];
    }
    for (int i = 1; i <= N; i++) nodes[i].clear();
    for (int i = 1; i <= M; i++) {
        lines[i].clear();
        for (int j = 1; j <= cntNodes[i]; j++) {
            int node;
            cin >> node;
            lines[i].push_back(node);
            nodes[node].push_back(i);
        }
    }
}
void bfs(int start_node) {
    queue<int> Q;
    for (int i=1;i<=M;i++) dist[i] = -1, visit_line[i] = 0;
    for (int i=1;i<=N;i++) visit_node[i] = 0;
    for (int line: nodes[start_node]){
        Q.push(line);
        dist[line] = 0;
        visit_line[line] = 1;
    }
    visit_node[start_node] = 1;
    while (!Q.empty()){
        int line = Q.front(); Q.pop();
        for (int node: lines[line]){
            if (visit_node[node]) continue;
            visit_node[node] = 1;
            for (int next_line: nodes[node]){
                if (visit_line[next_line]) continue;
                visit_line[next_line] = 1;
                dist[next_line] = dist[line] + 1;
                Q.push(next_line);
            }
        }
    }
}
void pro() {
    bfs(S);
    int ans = 0x7fffffff;
    for (int line: nodes[E]){
        ans = min(ans, dist[line]);
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


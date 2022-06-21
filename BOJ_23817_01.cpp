#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001, INF = 1e9;
int n, m, b[MAX][MAX], dist[MAX][MAX], adj[22][22], dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }, ans = INF;
bool visited[MAX][MAX], check[22];
vector<pair<int, int>> v;

void bfs(int idx)
{
	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INF;

	queue<pair<int, int>> q;
	q.push(v[idx]);
	visited[v[idx].first][v[idx].second] = true;
	dist[v[idx].first][v[idx].second] = 0;

	while (!q.empty())
	{
		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = now.first + dir[i][0], nc = now.second + dir[i][1];

			if (nr >= 1 && nr <= n && nc >= 1 && nc <= m && b[nr][nc] != -1 && !visited[nr][nc])
			{
				visited[nr][nc] = true;
				q.push({ nr, nc });
				dist[nr][nc] = dist[now.first][now.second] + 1;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (i == idx)
			continue;
		adj[idx][i] = dist[v[i].first][v[i].second];
	}
}

void func(int cnt, int prev, int sum)
{
	if (cnt == 5)
	{
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (adj[prev][i] == INF || check[i])
			continue;

		check[i] = true;
		func(cnt + 1, i, sum + adj[prev][i]);
		check[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	v.push_back({ 0, 0 });
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char c;
			cin >> c;

			if (c == 'X')
				b[i][j] = -1;
			if (c == 'S')
			{
				b[i][j] = 1;
				v[0] = { i, j };
			}
			if (c == 'K')
			{
				b[i][j] = 1;
				v.push_back({ i, j });
			}
		}
	}

	for (int i = 0; i < 22; i++)
		for (int j = 0; j < 22; j++)
			adj[i][j] = INF;

	for (int i = 0; i < v.size(); i++)
		bfs(i);

	check[0] = true;
	func(0, 0, 0);
	cout << (ans == INF ? -1 : ans);
	return 0;
}

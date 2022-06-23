#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<int> num, tree;

int init(int node, int start, int end) {

	if (start == end) return tree[node] = num[end];
	
	int mid = (start + end) / 2;
	
	return tree[node] = min(init(2 * node, start, mid), init(2 * node + 1, mid + 1, end));
	
}

int query(int node, int start, int end, int left, int right) {
	if (left > end || start > right) return 2e9; // 범위에 포함되지 않는다면 대상에서 제외한다는 의미인 무한의 값을 넣으면 제외된다. 최소가 될 수 없다 . 
	if (left <= start && end <= right) return tree[node]; // 범위에 포함되는 것은 그 값을 포함한 최소값을 리턴할것이다  
	int mid = (start + end) / 2;
	return min(query(2 * node, start, mid, left, right), query(2 * node + 1, mid + 1, end, left, right));// 두 가지로부터 최소값을 구한다  
}

void update(int node, int start, int end, int idx, int value) {
	if (idx < start || idx > end) return; // 이 코드가 가지치기의 일종이다 인덱스의 범위를 벗어나면 더이상 구하지 않겠다는 뜻이다. 
	if (start == end) {
		tree[node] = value;
		return;
	}
	int mid = (start + end) / 2;
	update(2 * node, start, mid, idx, value);
	update(2 * node + 1, mid + 1, end, idx, value);
	tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int main() {
  	ios_base::sync_with_stdio(0);
  	cin.tie(0);
  	cin >> n; 
  	num.resize(n + 1);
	tree.resize(4 * (n + 1));
  	for (int i = 1; i <= n; i++)

  		cin >> num[i];

  	init(1, 1, n);
    cin >> m;    
    while (m--) { 
        int c, i, j;  
        cin >> c >> i >> j; 
        if (c == 1) {
          	update(1, 1, n, i, j);
          	num[i] = j;
        }
        else {
			cout << query(1, 1, n, i, j) << '\n';
        }
 
    }    
    return 0;
}


// 해시맵을 사용해서 단어들을 기록해두고 사전식으로 찾아버리면 복잡도 O(1)로 된다  
#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

int main(){
	
	ios::sync_with_stdio(false);
	
	cin.tie(0);
	cout.tie(0);
	int N,M;
	int answer;
	unordered_map<string,bool> registered;
	
	cin >> N  >> M;
	
	for(int i = 0 ; i < N ; i++){
		string str;
		cin >> str;
		registered[str] = true;
	}
	for(int i = 0 ; i < M ; i++){
		string str;
		cin >> str;
		if(registered[str]){
			answer += 1;
		}
	}
	cout << answer << '\n';
	
	return 0 ;
} 

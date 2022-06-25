#include <iostream>
#include <unordered_map>

using namespace std;

long long N,P,Q;

unordered_map<long long , long long> dp;


void Input(){
	
	cin >> N >> P >> Q;	
		
}
long long recursion(long long N){
	if(dp.count(N)){
		return dp[N];
	}	
	else{
		return dp[N] = recursion(N/P) + recursion(N/Q);
	}
	
}
void Solve(){
	
	dp[0] = 1;
	cout << recursion(N) << '\n';
}

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	
	Input();
	Solve();
	
	
	return 0 ;
}

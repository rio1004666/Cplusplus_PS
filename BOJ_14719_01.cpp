#include <iostream>
using namespace std;

#define MAX 510
int H,W,Answer;
int Height[MAX];


int Max(int A, int B){return A>B ? A:B;}
int Min(int A, int B){return A<B ? A:B;}
void Input(){
	cin >> H >> W;
	for(int  i = 1; i <= W;i++)cin >> Height[i];
}
void Solution()
{
	for(int i = 2; i < W; i++)
	{
		int Left, Right;
		Left = Right = 0;
		for(int j =  1; j < i ; j++) Left = Max(Left,Height[j]);
		for(int j = i + 1 ; j <= W; j++) Right =  Max(Right,Height[j]);
		int Result = Min(Left,Right) - Height[i];
		if(Result >= 0) Answer += Result; // 최종적으로 정답에 추가함  
	}
	cout << Answer << '\n';
}



void solve()
{
	Input();
	Solution();	
}
int main(){
	
	
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();
	return 0;
}

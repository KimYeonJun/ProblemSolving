/*
백준 9663번: N-Queen
문제 유형: 백트랙킹

문제 풀이:
1. 열(Col)을 기준으로 퀸을 놓는다.
2. 1열에 각 행에 퀸을 놓아본다
3. 재귀를 타고 들어가서 다음 열에서도 각 행에 퀸을 놓아본다.
	-> 이때, 전에 놓은 퀸들에 의해 공격할 수 없는 행에 놓은 경우에는 다음 열로 진행.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 1000001
#define MOD 10007
using namespace std;
int N;
int board[20][20];
int col[20];
int answer = 0;
bool isPossible(int idx) {
	for (int i = 1; i < idx; i++) {
		if (col[i] == col[idx])
			return false;
		if (abs(i - idx) == abs(col[i] - col[idx]))
			return false;
	}
	return true;
}
void DFS(int idx) {
	if (idx == N+1) {
		answer++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		col[idx] = i;
		if (isPossible(idx)) {
			//cout << idx<<" "<<i << endl;
			DFS(idx + 1);
		}
		else {
			col[idx] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		col[1] = i;
		//cout << "시작: " << i << endl;
		DFS(2);
	}
	cout << answer << endl;
}
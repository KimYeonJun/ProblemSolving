/*
BOJ 1520번: 내리막 길
문제 유형 : DFS + dp

BFS, DFS로 완전탐색하면 4^(500*500)으로 시간초과 발생하므로 dp를 섞어서
이미 탐색한 길은 탐색을 하지 않고 목적지 까지 갈 수 있는 경우의 수만 받아온다.
DP[a][b]=c 는 (a,b)에서 (N-1,M-1)까지의 경로는 c개라는 뜻.
DP배열을 -1로 초기화 하지 않으면, 이미 탐색했는데 경로가 없는 0과 탐색 하지 않은 0을
구분할 수 없어서 시간초과가 발생한다. 그래서 꼭 -1로 초기화를 해줘야한다.

dp[x][y] == -1이면 탐색하지 않은 경로,
dp[x][y] != -1 이면 이미 탐색한 경로.
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
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int N, M;
int board[501][501];
int dp[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int answer = 0;
int DFS(int x, int y) {
	//cout<<"시작: " << x << " " << y << endl;
	if (x == N - 1 && y == M - 1) {
		return 1;
	}
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		//cout << nx << " " << ny << endl;
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;
		if(board[x][y]>board[nx][ny])
			dp[x][y] += DFS(nx, ny);
	}
	return dp[x][y];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	DFS(0, 0);
	cout << dp[0][0] << endl;
	return 0;
}
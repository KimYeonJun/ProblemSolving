/*
BOJ 1520��: ������ ��
���� ���� : DFS + dp

BFS, DFS�� ����Ž���ϸ� 4^(500*500)���� �ð��ʰ� �߻��ϹǷ� dp�� ���
�̹� Ž���� ���� Ž���� ���� �ʰ� ������ ���� �� �� �ִ� ����� ���� �޾ƿ´�.
DP[a][b]=c �� (a,b)���� (N-1,M-1)������ ��δ� c����� ��.
DP�迭�� -1�� �ʱ�ȭ ���� ������, �̹� Ž���ߴµ� ��ΰ� ���� 0�� Ž�� ���� ���� 0��
������ �� ��� �ð��ʰ��� �߻��Ѵ�. �׷��� �� -1�� �ʱ�ȭ�� ������Ѵ�.

dp[x][y] == -1�̸� Ž������ ���� ���,
dp[x][y] != -1 �̸� �̹� Ž���� ���.
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
	//cout<<"����: " << x << " " << y << endl;
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
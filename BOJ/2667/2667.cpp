/*
BOJ problem 2667
문제 유형 : BFS
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int board[512][512];
bool vis[512][512];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int main() {
	vector<int> result;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < N; j++) {
			board[i][j] = tmp[j] - '0';
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if ((board[i][j] == 0) || vis[i][j])
				continue;
			queue<pair<int, int>> que;
			que.push(make_pair(i, j));
			vis[i][j] = true;
			int res = 0;
			while (!que.empty()) {
				res++;
				auto cur = que.front();
				que.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cur.first + dx[k];
					int ny = cur.second + dy[k];

					if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
						continue;
					}
					if (!vis[nx][ny] && board[nx][ny] == 1) {
						que.push(make_pair(nx, ny));
						vis[nx][ny] = true;
					}
				}
			}
			result.push_back(res);

		}
	}

	sort(result.begin(), result.end());

	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}


}
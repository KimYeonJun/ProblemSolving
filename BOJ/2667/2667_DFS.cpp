#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int board[26][26];
bool vis[26][26];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> result;
int cnt;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < input.size(); j++) {
			board[i][j] = input[j]-'0';
		}
	}

}
void print() {
	cout << "-------------" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	cout << "-------------" << endl;
}
void DFS(int x,int y) {
	cnt++;
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
			continue;
		}
		if (board[nx][ny] == 1 && vis[nx][ny] == false) {
			DFS(nx, ny);
		}
	}
}
void solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == 1 && vis[i][j]==false) {
				cnt = 0;
				DFS(i,j);
				result.push_back(cnt);
			}
		}
	}
	sort(result.begin(), result.end());
	cout <<"ฟฌมุ" <<result.size() << endl;
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}
}
void solve() {
	input();
	print();
	solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	solve();

	return 0;
}
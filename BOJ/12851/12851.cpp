/*
BOJ 1697번: 숨바꼭질
문제 유형 : BFS
*/
#include <iostream>
#include <queue>
using namespace std;
bool visit[100001];
int N, K;

void Input() {
	cin >> N >> K;
}
void Solution() {
	queue<pair<int, int>> que;
	que.push(make_pair(N, 0));
	//int timeLimit = 987654321;
	int timeLimit = 0;
	int cnt = 0;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		visit[cur.first] = true;
		//if (timeLimit < cur.second)
			//break;
		if (cnt != 0 && timeLimit < cur.second)
			break;
		if (cur.first == K) {
			cnt++;
			timeLimit = cur.second;
		}
		int nx[3];
		nx[0] = cur.first + -1;
		nx[1] = cur.first + 1;
		nx[2] = cur.first * 2;
		for (int i = 0; i < 3; i++) {
			if (nx[i] < 0 || nx[i]>100000)
				continue;
			if (visit[nx[i]])
				continue;
			que.push(make_pair(nx[i], cur.second + 1));
		}
	}
	cout << timeLimit << endl;
	cout << cnt << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}
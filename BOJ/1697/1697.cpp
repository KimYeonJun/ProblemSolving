/*
BOJ 1697번: 숨바꼭질
문제 유형 : BFS
*/
#include <iostream>
#include <queue>
using namespace std;
int N, K;
bool visit[100001];
void Input() {
	cin >> N >> K;
}
void Solution() {
	queue<pair<int, int>> que;
	que.push(make_pair(N, 0));
	visit[N] = true;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		if (cur.first == K) {
			cout << cur.second << endl;
			return;
		}
		for (int i = 0; i < 3; i++) {
			int nSubin;
			if (i == 0) {
				nSubin = cur.first - 1;
			}
			else if (i == 1) {
				nSubin = cur.first + 1;
			}
			else
				nSubin = cur.first * 2;

			if (nSubin < 0 || nSubin>100000)
				continue;
			if (visit[nSubin])
				continue;
			visit[nSubin]=true;
			que.push(make_pair(nSubin, cur.second+1));
		}
	}
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}
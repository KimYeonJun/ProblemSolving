/*
BOJ 13549번: 숨바꼭질 3
문제 유형 :BFS

어려운점 : queue를 이용해 BFS를 하면 무조건 *2,  -1,  +1 순으로 반복해야 정답이 된다.
		   이것은 운이 좋아서 통과한것, BFS를 하려면 모든 간선의 가중치가 동일해야한다는 전제 조건이 필요한데 이 문제는
		   가중치가 0인 간선이 있기 때문에 일반적인 BFS를 하면 안된다.

		   이를 해결하기 위해 queue대신 deque를 사용하고, 0인 간선은 push_front를, 0이 아닌 간선은 push_back을 해준다.
		   혹은 다익스트라 알고리즘을 사용해도 되지만 잘 몰라서 일단은 pass.
*/
#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
using namespace std;
bool visit[100001];
int N, K;
//int answer = 987654321;
void Input() {
	cin >> N >> K;
}
void Solution() {
	//queue<pair<int, int>> que;
	deque<pair<int, int>> deq;
	deq.push_back(make_pair(N, 0));
	//que.push(make_pair(N, 0));
	//memset(visit,-1,sizeof(visit));
	visit[N] = true;
	while (!deq.empty()) {
		auto cur = deq.front();
		//que.pop();
		deq.pop_front();
		if (cur.first == K) {
			cout << cur.second << endl;
			return;
		}
		int nx[3];
		nx[0] = cur.first * 2;
		nx[1] = cur.first + 1;
		nx[2] = cur.first - 1;
		for (int i = 0; i < 3; i++) {
			if (nx[i] < 0 || nx[i]>100000)
				continue;
			if (visit[nx[i]])
				continue;
			visit[nx[i]] = true;
			if (i == 2) {
				//que.push(make_pair(nx[i], cur.second));
				deq.push_front(make_pair(nx[i], cur.second));
			}
			else {
				//que.push(make_pair(nx[i], cur.second + 1));
				deq.push_back(make_pair(nx[i], cur.second + 1));
			}
		}

	}
	//cout << answer << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}
/*
BOJ 13549��: ���ٲ��� 3
���� ���� :BFS

������� : queue�� �̿��� BFS�� �ϸ� ������ *2,  -1,  +1 ������ �ݺ��ؾ� ������ �ȴ�.
		   �̰��� ���� ���Ƽ� ����Ѱ�, BFS�� �Ϸ��� ��� ������ ����ġ�� �����ؾ��Ѵٴ� ���� ������ �ʿ��ѵ� �� ������
		   ����ġ�� 0�� ������ �ֱ� ������ �Ϲ����� BFS�� �ϸ� �ȵȴ�.

		   �̸� �ذ��ϱ� ���� queue��� deque�� ����ϰ�, 0�� ������ push_front��, 0�� �ƴ� ������ push_back�� ���ش�.
		   Ȥ�� ���ͽ�Ʈ�� �˰����� ����ص� ������ �� ���� �ϴ��� pass.
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
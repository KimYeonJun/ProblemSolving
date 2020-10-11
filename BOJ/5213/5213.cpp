/*
[BOJ] 5213��: ���ܸ�
���� �ð� : 10�� 50��
���� �ð� : 12�� 20��
�ҿ� �ð� : 1�ð� 30��

���� Ǯ��
1. Input
	1.1) ���� value�� (����, Ÿ�Ϲ�ȣ)�� ����
	1.2) Ȧ�� ���� ���, 0<=y<2*N ���� �Է¹޴´�
	1.3) ¦�� ���� ���, 1<=y<2*N-1 ���� �Է¹޴´�
	1.4) �Է� ���� ��, �� ���� Ÿ���� ���ÿ� �Է¹ޱ� ���Ͽ� 2���� �Է¹޴´�.
2. BFS
	2.1) ù��° Ÿ���� ����(0,0)�� ������(0,1)�� ť�� �ְ�, �湮 üũ
	2.2) �����¿� �� ���� Ÿ���� ���ڿ� ���� �����ϴ� Ÿ���� ���ڰ� ������ ť�� �ִ´�.
		-> �̶�, ���� ���� Ÿ�� �� ��(2���� ��ǥ)�� ���� �־����
	2.3) ���� ������ �ݺ��ϸ鼭, ��ȣ�� ū Ÿ���� ��θ� ��� �����Ѵ�.

	
	*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct loc {
	int x;
	int y;
	vector<int> vec;
};
int N;
pair<int, int> board[501][1010];
bool visit[501][1010];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int idx = 1;
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int l, r;
		if (i % 2 == 0) {
			l = 0;
			r = N * 2;
		}
		else {
			l = 1;
			r = N * 2 - 1;
		}
		for (int j = l; j < r; j+=2) {
			cin >> board[i][j].first;
			cin >> board[i][j + 1].first;
			board[i][j].second = idx;
			board[i][j + 1].second = idx++;
		}
	}
}
vector<int> BFS() {
	queue<loc> que;
	que.push(loc{ 0,0,{1} });
	que.push(loc{ 0,1,{1} });
	visit[0][0] = true;
	visit[0][1] = true;
	vector<int> answer;
	int answer_idx = 0;
	while (!que.empty()) {
		loc cur = que.front();
		que.pop();
		int x = cur.x; int y = cur.y;
		vector<int> vec = cur.vec;
		if (board[x][y].second == idx - 1) {
			return vec;
		}
		if (answer_idx < board[x][y].second) {
			answer_idx = board[x][y].second;
			answer = vec;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N*2 || visit[nx][ny] || board[nx][ny].first == 0)
				continue;
			if (board[nx][ny].first == board[x][y].first) {
				vec.push_back(board[nx][ny].second);
				que.push({ nx,ny,vec });
				visit[nx][ny] = true;
				if (board[nx][ny].second == board[nx][ny + 1].second) {
					visit[nx][ny + 1] = true;
					que.push({ nx,ny + 1,vec });
				}
				else if(board[nx][ny].second == board[nx][ny-1].second) {
					visit[nx][ny - 1] = true;
					que.push({ nx,ny - 1,vec });
				}
				vec.pop_back();
			}
		}
	}
	return answer;
}
void Solution() {
	vector<int> answer = BFS();
	cout << answer.size() << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
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
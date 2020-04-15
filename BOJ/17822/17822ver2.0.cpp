/*
BOJ 17822: 원판 돌리기

번호가 xi의 배수인 원판을 di방향(0: 시계, 1:반시계) ki칸 회전
원판에 수가 남아있으면 인접하면서 수가 같은 것들을 모두 찾는다.
	1. 그러한 수가 있으면 인접하면서 같은 수를 모두 지움
	2. 없으면 원판에 적힌 수의 평균을 구하고 평균보다 큰 수는 1을 빼고, 작은 수는 1을 더함

*/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct rot {
	int x;
	int d;
	int k;
};
struct point {
	int x;
	int y;
	int v;
};
int N, M, T; //원판의 갯수, 원판에 있는 정수의 갯수, 회전 수
vector<rot> rot_list;
int board[52][52];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void Input() {
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < T; i++) {
		rot input;
		cin >> input.x >> input.d >> input.k;
		rot_list.push_back(input);
	}
}
void rotate(rot r) {
	for (int i = r.x; i <= N; i += r.x) {
		for (int j = 0; j < r.k; j++) {
			if (r.d == 0) { //시계
				int tmp = board[i][M - 1];
				for (int k = M - 1; k > 0; k--) {
					board[i][k] = board[i][k - 1];
				}
				board[i][0] = tmp;
			}
			else { //반시계
				int tmp = board[i][0];
				for (int k = 0; k < M-1; k++) {
					board[i][k] = board[i][k + 1];
				}
				board[i][M - 1] = tmp;
			}
		}
	}
}
void print() {
	cout << "--------------" << endl;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------" << endl;
}
bool BFS(queue<point> que) {
	int qsize = que.size();
	bool flag = false;
	while (qsize--) {
		auto cur = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx<1 || nx>N)
				continue;
			if (ny == -1)
				ny = M - 1;
			else if (ny == M)
				ny = 0;
			if (board[nx][ny] == cur.v) {
				flag = true;
				board[cur.x][cur.y] = 0;
				board[nx][ny] = 0;
			}
		}
	}
	return flag;
}
void update(float avg) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)
				continue;
			if (avg > board[i][j])
				board[i][j] += 1;
			else if (avg < board[i][j])
				board[i][j] -= 1;
		}
	}
}
void Solution() {
	for (int i = 0; i < T; i++) {
		//회전
		rotate(rot_list[i]);
		queue<point> que;
		int sum = 0, cnt = 0;
		for (int j = 1; j <= N; j++) { //같은 수 찾기
			for (int k = 0; k < M; k++) {
				if (board[j][k] == 0)
					continue;
				que.push({ j,k,board[j][k]});
				sum += board[j][k];
				cnt++;
			}
		}
		if (!BFS(que)) {
			float avg = sum * 1.0 / cnt;
			update(avg);
		}

	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			answer += board[i][j];
		}
	}
	cout << answer << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
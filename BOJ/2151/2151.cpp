/*
BOJ 2151��: �ſ� ��ġ
���� ���� : BFS, �޸������̼�

���� Ǯ��
1. visit �迭�� int�� 3���� �迭�� ����.
	-> ��������� -> �϶� (x,y)�� �湮�ϴ� �Ͱ�, ��������� <- �϶� (x,y)�� �湮�ϴ� ���� �ٸ��� ������.
	-> �� ��ǥ���� 4���⿡ ���� ��ġ�� �ſ��� ������ üũ�������.

2. ���� ��ǥ�� �ſ��� ��ġ�� �� ���� ��ġ���, �������� �������θ� ���ư���.

3. ���� ��ǥ�� �ſ��� ��ġ�� �� �ִ� ��ġ�̰� �ſ��� ��ġ�Ѵٸ� 
	-> ������ �������� ���⿡ ���� ������������ ����( ������ -> ���, �� �Ʒ�)
*/
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
struct Pos {
	int x;
	int y;
	int dir;
};
const int INF = 987654321;
const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
int N;
char board[51][51];
int visit[51][51][4];
int s_x, s_y, e_x, e_y;
void Input() {
	cin >> N;
	bool flag = false;
	for (int i = 0; i < N; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < N; j++) {
			board[i][j] = input[j];
			if (board[i][j] == '#') {
				if (!flag) {
					s_x = i;
					s_y = j;
					flag = true;
				}
				else {
					e_x = i;
					e_y = j;
				}
			}
		}
	}
}
vector<int> Change_Direction(int dir) {
	vector<int> ndirs;
	if (dir == 0 || dir == 2) {
		ndirs.push_back(1);
		ndirs.push_back(3);
	}
	else {
		ndirs.push_back(0);
		ndirs.push_back(2);
	}
	return ndirs;
}
void BFS() {
	queue<Pos> que;
	for (int i = 0; i < 4; i++) {
		que.push({ s_x,s_y,i });
		visit[s_x][s_y][i] = 0;
	}
	while (!que.empty()) {
		Pos cur = que.front();
		que.pop();
		int x = cur.x;
		int y = cur.y;
		//cout << x << " " << y << endl;
		int dir = cur.dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[nx][ny]=='*')
			continue;
		if (board[nx][ny] == '!') { //�ſ� ��ġ�ϴ� ���
			vector<int> ndirs = Change_Direction(dir);
			for (int i = 0; i < 2; i++) {
				int ndir = ndirs[i];
				if (visit[nx][ny][ndir] > visit[x][y][dir]+1) {
					visit[nx][ny][ndir] = visit[x][y][dir] + 1;
					que.push({ nx,ny,ndir });
				}
			}
		}
		if (visit[nx][ny][dir] > visit[x][y][dir]) {
			visit[nx][ny][dir] = visit[x][y][dir];
			que.push({ nx,ny,dir });
		}
	}
}
void Solution() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 4; k++) {
				visit[i][j][k] = INF;
			}
		}
	}
	BFS();
	int result = INF;
	for (int i = 0; i < 4; i++) {
		result = min(result, visit[e_x][e_y][i]);
	}
	cout << result << endl;
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
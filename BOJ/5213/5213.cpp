/*
[BOJ] 5213번: 과외맨
시작 시간 : 10시 50분
종료 시간 : 12시 20분
소요 시간 : 1시간 30분

문제 풀이
1. Input
	1.1) 맵의 value는 (숫자, 타일번호)로 구성
	1.2) 홀수 줄의 경우, 0<=y<2*N 까지 입력받는다
	1.3) 짝수 줄의 경우, 1<=y<2*N-1 까지 입력받는다
	1.4) 입력 받을 때, 한 개의 타일을 동시에 입력받기 위하여 2개씩 입력받는다.
2. BFS
	2.1) 첫번째 타일의 왼쪽(0,0)과 오른쪽(0,1)을 큐에 넣고, 방문 체크
	2.2) 상하좌우 중 현재 타일의 숫자와 변을 공유하는 타일의 숫자가 같으면 큐에 넣는다.
		-> 이때, 새로 넣을 타일 한 쌍(2개의 좌표)을 같이 넣어야함
	2.3) 위의 과정을 반복하면서, 번호가 큰 타일의 경로를 계속 갱신한다.

	
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
/*
[BOJ] 20056��: ������ ���� ���̾
2020 �Ϲݱ� �Ｚ sw �׽�Ʈ ���� 2�� ����
���躻 �ڵ� ����!

�����忡�� ���� ȯ�濡���� �׽�Ʈ���̽��� ���� �۵�������,
���� ȯ�濡���� ���� 7������ �������� ����Ǵ� �̽��� �־���.
�׷��� �ڵ带 �����ؼ� ���ؿ��� Ǯ��ôµ�, �ϴ� �������� �����.. ��

���̾�� �����̴� ���� ��쿡�� 
�����忡���� s�� ������ 1<=s<=10���� �۾Ƽ� O(s)�� �����ߴ�.
���� ������ 1<=s<=1000�̶� ��ⷯ ������ ����Ͽ� O(1)�� �����ؾ��ҵ���.
*/
#include <iostream>
#include <vector>
using namespace std;
struct Node {
	int x;
	int y;
	int m;
	int s;
	int d;
	bool die=false;
};
int N, M, K;
int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<int> board[51][51];
vector<Node> node_list;
vector<Node> tmp_list;
void Input() {
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		Node input;
		cin >> input.x >> input.y >> input.m >> input.s >> input.d;
		node_list.push_back(input);
		//board[input.x][input.y].push_back(i);
	}
}
void Print_Map() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j].size() >= 1) {
				cout<<"��ǥ : " << i << " " << j << endl;
				for (int k = 0; k < board[i][j].size(); k++) {
					cout << board[i][j][k] << " ";
				}
				cout << endl;
			}
		}
	}
}
void Print_Ball() {
	cout << "���̾ ����Ʈ" << endl;
	for (int i = 0; i < node_list.size(); i++) {
		cout << node_list[i].x << " " << node_list[i].y << " " << node_list[i].m << endl;
	}
}
void Move_Ball() {
	for (int i = 0; i < node_list.size(); i++) {
		if (node_list[i].die)
			continue;
		int x = node_list[i].x;
		int y = node_list[i].y;
		board[x][y].clear();
	}
	for (int i = 0; i < node_list.size(); i++) {
		if (node_list[i].die)
			continue;
		int x = node_list[i].x;
		int y = node_list[i].y;
		int m = node_list[i].m;
		int s = node_list[i].s;
		int d = node_list[i].d;
		for (int i = 0; i < s; i++) {
			x += dx[d];
			y += dy[d];
			if (x == N + 1)
				x = 1;
			else if (x == 0)
				x = N;
			if (y == N + 1)
				y = 1;
			else if (y == 0)
				y = N;
		}
		node_list[i].x = x;
		node_list[i].y = y;
		board[x][y].push_back(i);
	}
}
void Collision(int x, int y) {
	int sm = 0;
	int ss = 0;
	bool dirs[2];
	dirs[0] = false;
	dirs[1] = false;
	for (int i = 0; i < board[x][y].size(); i++) {
		int idx = board[x][y][i];
		node_list[idx].die = true;
		sm += node_list[idx].m;
		ss += node_list[idx].s;
		if (node_list[idx].d % 2 == 0) {
			dirs[0] = true;
		}
		else {
			dirs[1] = true;
		}
	}
	int nm = sm / 5;
	int ns = ss / board[x][y].size();
	if (nm == 0)
		return;
	if (dirs[0] == true && dirs[1] == true) { // 1 3 5 7 
		tmp_list.push_back({ x,y,nm,ns,1 });
		tmp_list.push_back({ x,y,nm,ns,3 });
		tmp_list.push_back({ x,y,nm,ns,5 });
		tmp_list.push_back({ x,y,nm,ns,7 });
	}
	else{
		tmp_list.push_back({ x,y,nm,ns,0 });
		tmp_list.push_back({ x,y,nm,ns,2 });
		tmp_list.push_back({ x,y,nm,ns,4 });
		tmp_list.push_back({ x,y,nm,ns,6 });
	}
}
void Check_Collision() {
	tmp_list.clear();
	for (int i = 0; i < node_list.size(); i++) {
		if (node_list[i].die)
			continue;
		Node node = node_list[i];
		int x = node.x;
		int y = node.y;
		if (board[x][y].size() >= 2) {
		//	cout << "hi";
			Collision(x, y);
		}
		if (!node_list[i].die)
			tmp_list.push_back(node_list[i]);
		board[x][y].clear();
	}
	node_list.clear();
	for (int i = 0; i < tmp_list.size(); i++) {
		node_list.push_back(tmp_list[i]);
	}
}
void Solution() {
	for (int i = 1; i <= K; i++) {
		Move_Ball();
		Check_Collision();
		//Print_Ball();
	}
	int sum = 0;
	for (int i = 0; i < node_list.size(); i++) {
		sum += node_list[i].m;
	}
	cout << sum << endl;
}
void Solve() {
	Input();
	Solution();
}
int main() {
	Solve();
	return 0;
}
/*
BOJ 3190��: ��
���� ���� :
���� Ǯ�� :
*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
bool board[101][101];
bool visit[101][101];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int N, K, L;
vector<pair<int, char>> dirInfo;
void Input() {
    cin >> N; //������ ũ�� 
    cin >> K;
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        board[x][y] = true;
    }
    cin >> L;
    int X;
    char C;
    for (int i = 0; i < L; i++) {
        cin >> X >> C;
        dirInfo.push_back(make_pair(X, C));
    }

}
int Change_Dir(int dir, char C) {
    if (C == 'L') {
        dir = (dir + 3) % 4;
    }
    else {
        dir = (dir + 1) % 4;
    }
    return dir;
}
void Solution() {
    visit[0][0] = true;
    deque<pair<int, int>> snake;
    snake.push_back({ 0,0 });
    int time = 0;
    int dir = 0;
    int cnt = 0;
    while (true) {
        time++;

        pair<int, int> tail = snake.back();
        pair<int, int> head;

           // if (nx < 0 || nx >= N || ny < 0 || ny >= N) {  //nx ny��   ������ üũ
             //   break;
           // }

       // if (board[nx][ny] = true) { //����ĭ�� ����� �ִ� ���

        //}
        //else { //����� ���� ���

       // }




        //���� ��ȯ
        if (time == dirInfo[cnt].first) {
            dir = Change_Dir(dir, dirInfo[cnt].second);
            cnt++;

        }
    }
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
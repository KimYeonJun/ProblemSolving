#include <iostream>

using namespace std;
struct robot {
	int r;
	int c;
	int d;
};
int map[52][52];
bool vis[52][52];
int dx[4] = { -1, 0, 1, 0 }; //0 북,1 동, 2 남, 3서
int dy[4] = { 0, 1,0,-1 };
int main() {
	int N, M;
	int result = 0;
	cin >> N >> M;
	robot now_robot;
	cin >> now_robot.r >> now_robot.c >> now_robot.d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	vis[now_robot.r][now_robot.c] = 1;
	result++;
	while (true) {
		//cout << result << endl;
		int nd = now_robot.d;
		bool do_clean = false;
		for (int i = 0; i < 4; i++) {
			nd = (nd + 3) % 4;
			int nx = now_robot.r + dx[nd];
			int ny = now_robot.c + dy[nd];
			if (map[nx][ny] == 0 && !vis[nx][ny]) { // 2.a.조건
				vis[nx][ny] = 1;
				result++;
				now_robot.r = nx;
				now_robot.c = ny;
				now_robot.d = nd;
				do_clean = true;
				break;
			}
		}
		if (!do_clean) {//2.c. 방향 유지 후 한칸 후진
			//cout << "Hell " << now_robot.r << " " << now_robot.c <<" " <<now_robot.d<<endl;
			if (now_robot.d == 0 || now_robot.d == 1) {
				now_robot.r = now_robot.r + dx[now_robot.d + 2];
				now_robot.c = now_robot.c + dy[now_robot.d + 2];
			}
			else {
				now_robot.r = now_robot.r + dx[now_robot.d - 2];
				now_robot.c = now_robot.c + dy[now_robot.d - 2];
			}
			if (map[now_robot.r][now_robot.c] == 1)
				break;
		}
	}
	cout << result << endl;


	return 0;
}
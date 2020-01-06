#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int board[102][102];
bool vis[102][102][5];
int dx[5] = {0, 0, 0, 1, -1 };
int dy[5] = {0, 1, -1, 0, 0 };
int main() {

	int M, N;
	int s_point[3];
	int e_point[3];

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < 3; i++) {
		cin >> s_point[i];
	}
	for (int i = 0; i < 3; i++) {
		cin >> e_point[i];
	}
	
	queue<pair<pair<int, int>, pair<int, int>>> que;
	que.push(make_pair(make_pair(s_point[0], s_point[1]), make_pair(s_point[2], 0)));
	vis[s_point[0]][s_point[1]][s_point[2]] = true;
	while (!que.empty()) { //BFS Ω√¿€
		int x = que.front().first.first;
		int y = que.front().first.second;
		int dir = que.front().second.first;
		int dep = que.front().second.second;
		que.pop();
		if (x == e_point[0] && y == e_point[1] && dir == e_point[2]) {
			cout << dep << endl;
			break;
			
		}
		for (int i = 1; i <= 3; i++) { //¡˜¡¯ 1ƒ≠ ~ 3ƒ≠
			int nx = x + dx[dir] * i;
			int ny = y + dy[dir] * i;
			
			/*if (vis[nx][ny][dir])
				continue;
			if (1 <= nx && nx <= M && 1 <= ny && ny <= N && !board[nx][ny]) {
				vis[nx][ny][dir] = true;
				que.push({ {nx,ny},{dir,dep + 1} });
			}
			else {
				break;
			}*/

			/*if (nx<1 || nx>M || ny<1 || ny>N)
				continue;
			if (!vis[nx][ny][dir] && !board[nx][ny]) {
				vis[nx][ny][dir] = true;
				que.push({ { nx,ny }, { dir,dep + 1 } });
			}
			else
				break;	*/
			if (nx<1 || nx>M || ny<1 || ny>N)
				break;
			if (vis[nx][ny][dir])
				continue;
			if (board[nx][ny])
				break;
			vis[nx][ny][dir] = true;
			que.push({ { nx,ny }, { dir,dep + 1 } });
		}
		
		for (int i = 1; i <= 4; i++) {

			if((dir !=i) && !vis[x][y][i]){
				vis[x][y][i] = true;
				if ((i == 1 && dir == 2) || (i == 2 && dir == 1) || (i == 3 && dir == 4) || (i == 4 && dir == 3))
					que.push({ {x,y},{i,dep + 2} });
				else
					que.push({ {x,y},{i,dep + 1} });
			}

			
		}


	}


	return 0;
}
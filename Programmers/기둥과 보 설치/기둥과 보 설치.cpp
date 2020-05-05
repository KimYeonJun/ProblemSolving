/*
���α׷��ӽ� ��հ� �� ��ġ


*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int board[110][110][2];
int N;
bool cmp(vector<int>& a, vector<int>& b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

bool insert(int x, int y, int type) {
    if (type == 0) { //��� ��ġ
        if (y == 0) //�ٴ� ���� �ֳ�?
            return true;
        else if ((x-1>=0&&board[x-1][y][1] == 1) || board[x][y][1] == 1)
            return true;
        else if (y-1 >= 0 && board[x][y-1][0] == 1) // �ٸ� ��� ���� �ֳ�?
            return true;
        return false;
    }
    else {//�� ��ġ
        if ((y-1>=0&&board[x][y-1][0] == 1) ||(x+1<=N&&y-1>=0&& board[x + 1][y - 1][0] == 1))
            return true;
        else if (x-1>=0&&x+1<=N&&board[x-1][y][1] == 1 && board[x+1][y][1] == 1)
            return true;
        return false;
    }
    return false;
}
bool erase() {
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k] == 1) {
                    board[i][j][k] = 0;
                    if (!insert(i, j, k)) {
                        board[i][j][k] = 1;
                        return false;
                    }
                    board[i][j][k] = 1;
                }
            }
        }
    }
    return true;
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    N = n;
    vector<vector<int>> answer;
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (b == 0) { //����
            board[x][y][a] = 0;
            if (!erase()) {
                board[x][y][a] = 1;
            }
        }
        else { //��ġ
            //insert(x, y, a);
            if (insert(x, y, a)) {
                board[x][y][a] = 1;
            }


            
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k < 2; k++) {
                if (board[i][j][k] == 1) {
                    answer.push_back({ i,j,k });
                }
            }
        }
    }
   // sort(answer.begin(), answer.end(), cmp);
    return answer;
}

int main() {
    int n;
    vector<vector<int>> build_frame{ {1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {5, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };
    vector<vector<int>> answer = solution(n, build_frame);
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size(); j++) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
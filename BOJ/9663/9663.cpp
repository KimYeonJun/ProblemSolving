/*
���� 9663��: N-Queen
���� ����: ��Ʈ��ŷ

���� Ǯ��:
1. ��(Col)�� �������� ���� ���´�.
2. 1���� �� �࿡ ���� ���ƺ���
3. ��͸� Ÿ�� ���� ���� �������� �� �࿡ ���� ���ƺ���.
	-> �̶�, ���� ���� ���鿡 ���� ������ �� ���� �࿡ ���� ��쿡�� ���� ���� ����.
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <math.h>
#include <sstream>
#include <unordered_map>
#define endl '\n'
#define INF 987654321
#define MAX 1000001
#define MOD 10007
using namespace std;
int N;
int board[20][20];
int col[20];
int answer = 0;
bool isPossible(int idx) {
	for (int i = 1; i < idx; i++) {
		if (col[i] == col[idx])
			return false;
		if (abs(i - idx) == abs(col[i] - col[idx]))
			return false;
	}
	return true;
}
void DFS(int idx) {
	if (idx == N+1) {
		answer++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		col[idx] = i;
		if (isPossible(idx)) {
			//cout << idx<<" "<<i << endl;
			DFS(idx + 1);
		}
		else {
			col[idx] = 0;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		col[1] = i;
		//cout << "����: " << i << endl;
		DFS(2);
	}
	cout << answer << endl;
}
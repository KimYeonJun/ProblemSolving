/*
[BOJ] 16637�� : ��ȣ �߰��ϱ�
���� ���� : ���Ʈ���� , ���

��͸� ����Ͽ� ��� ��츦 Ž���Ѵ�.
DFS�� �б� ������ �� ���� �̴�.
	1. ��ȣ�� ġ�� �ʰ� ����ϰ� ���� ����.
	2. ���� ���ڿ� �� ���� ���ڸ� ��ȣ�� ���� ����Ѵ�.
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
#define MAX 100000000
#define MOD 1000000000
using namespace std;
int N;
string s;
int answer = 0;
int Calc(int a, char op, int b) {
	if (op == '+')
		return a + b;
	else if (op == '*')
		return a * b;
	else if (op == '-')
		return a - b;
}
void DFS(int idx,int sum) {
	if (idx >= N) {
		answer = max(answer, sum);
		return;
	}
	char op = idx == 0 ? '+' : s[idx - 1];
	int tmp = Calc(sum, op, s[idx] - '0');
	DFS(idx + 2, tmp);
	if (idx < N - 2) {
		int nxt = Calc(s[idx] - '0', s[idx + 1], s[idx + 2] - '0');
		nxt = Calc(sum, op, nxt);
		DFS(idx + 4, nxt);
	}
}
void Solve() {
	cin >> N;
	cin >> s;
	DFS(0, 0);
	cout << answer << endl;

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
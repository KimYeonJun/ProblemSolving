/*
[BOJ] 16637번 : 괄호 추가하기
문제 유형 : 브루트포스 , 재귀

재귀를 사용하여 모든 경우를 탐색한다.
DFS의 분기 조건은 두 가지 이다.
	1. 괄호를 치지 않고 계산하고 다음 진행.
	2. 다음 숫자와 그 다음 숫자를 괄호로 묶고 계산한다.
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
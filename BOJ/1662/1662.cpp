/*
[BOJ] 1662번: 압축
문제 유형 : 스택, 재귀

1. 스택을 사용하여 열린 괄호에 대한 닫힌 괄호의 인덱스를 저장한다.
2. 재귀를 사용하여 열린 괄호 ~ 닫힌 괄호 사이의 문자 길이를 구한다.
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
string s;
int visit[51];
int DFS(int l, int r) {
	int result = 0;
	for (int i = l; i < r; i++) {
		if (s[i] == '(') {
			result += (s[i - 1] - '0') * DFS(i + 1, visit[i])-1;
			i = visit[i];
		}
		else
			result++;
	}
	return result;
}
void Solve() {
	stack<int> stk;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') {
			stk.push(i);
		}
		else if (s[i] == ')') {
			int idx = stk.top();
			stk.pop();
			visit[idx] = i;
		}
	}
	cout << DFS(0, s.size()) << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> s;
	Solve();
	return 0;
}
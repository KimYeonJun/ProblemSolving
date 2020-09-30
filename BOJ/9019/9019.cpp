/*
BOJ 9019번 : DSLR
문제 유형 : BFS

--시간초과문제--
L연산, R연산 할 때 string으로 변환 후 연산하면 시간초과로 문제를 풀 수 없다.
이를 해결하기 위해 L연산, R연산을 O(1)에 해결해야한다.
L 연산은 val = (val % 1000) * 10 + val / 1000 식 으로 도출.
R 연산은 val = (val % 10) * 1000 + val / 10 식 으로 도출.
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
#define MOD 1000000000
using namespace std;
bool visit[10001];
char dcmd[4] = { 'D','S','L','R' };
int change(int val, int t) {
	if (t == 0) {
		val *= 2;
		if (val > 9999)
			val %= 10000;
	}
	else if (t == 1) {
		val -= 1;
		if (val < 0)
			val = 9999;
	}
	else if (t == 2) {
		val = (val % 1000) * 10 + val / 1000;

	}
	else if (t == 3) {
		val = (val % 10) * 1000 + val / 10;
	}
	return val;
}
void BFS(int A, int B) {
	queue<pair<int, string>> que;
	visit[A] = true;
	que.push({ A,"" });
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		int val = cur.first;
		string cmd = cur.second;
		if (val == B) {
			cout << cmd<< endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nval = change(val,i);
			if (visit[nval])
				continue;

			visit[nval] = true;
			que.push({ nval,cmd + dcmd[i] });
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		memset(visit, 0, sizeof(visit));
		BFS(A, B);
	}

}
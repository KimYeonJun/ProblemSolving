/*
BOJ 1963번 : 소수 경로
문제 유형 : 에라토스테네스의 체 , BFS

문제 풀이
1. 에라토스테네스의 체를 사용하여 소수를 미리 구함
2. BFS로 탐색하여 입력받은 두 소수의 변환이 가능한지 확인
3. 입력받은 소수 A로부터, 각 자리수를 모두 변환해본 후, 소수이고 방문하지 않은 수라면 큐에 push.
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
bool sosu[10001];
bool visit[10001];
void initSosu() {
	for (int i = 2; i <= 100; i++) {
		if (sosu[i])
			continue;
		for (int j = i + i; j <= 10000; j += i) {
			sosu[j] = true;
		}
	}
}
int change(int& num, int& index, int& digit) {
	if (index == 0 && digit == 0)
		return -1;
	string tmp = to_string(num);
	tmp[index] = digit+'0';
	return stoi(tmp);
}
int BFS(int A, int B) {
	queue<pair<int,int>> que;
	que.push({ A,0 });
	visit[A] = true;
	while (!que.empty()) {
		auto cur = que.front();
		que.pop();
		int val = cur.first;
		int cnt = cur.second;
		if (val == B)
			return cnt;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 10; j++) {
				int nxt = change(val, i, j);
				if (nxt == -1)
					continue;
				if (sosu[nxt] || visit[nxt])
					continue;
				visit[nxt] = true;
				que.push({ nxt,cnt + 1 });
			}
		}
	}
	return -1;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	initSosu();
	int T;
	int A, B;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		memset(visit, 0, sizeof(visit));
		int answer = BFS(A, B);
		if (answer == -1)
			cout << "Impossible" << endl;
		else
			cout << answer << endl;
	}
	

}
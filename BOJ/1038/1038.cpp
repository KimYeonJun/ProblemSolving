/*
BOJ 1038��: �����ϴ� ��

queue�� 0~10���� ����.
front�� 10�� ���ϰ�, 0<=x<front%10�� �����ϴ� x���� ��, ť�� �ٽ� push�Ѵ�.
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	queue<long long> que;
	for (int i = 0; i <= 9; i++) {
		que.push(i);
	}
	long long answer = -1;
	while (!que.empty()) {
		long long cur = que.front();
		que.pop();
		if (N-- == 0) {
			answer = cur;
			break;
		}
		int remainder = cur % 10;
		for (int i = 0; i < remainder; i++) {
			long long nxt = (cur * 10) + i;
			que.push(nxt);
		}
	}
	cout << answer << endl;
}
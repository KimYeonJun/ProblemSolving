/*
BOJ 2668번: 숫자 고르기
문제 유형 : 완전탐색, DFS, 사이클

문제 풀이
사이클 존재 유무 확인하는 문제로, N제한이 100이라서 완전탐색 가능.
DFS 인자로 시작 지점과 방문해야 할 지점을 가지고 탐색한다.
방문해야할 지점이, 이미 방문한 곳이고, 그 지점이 시작지점과 같다면 cycle 발생.
이미 방문한 곳이 아니라면, 방문 체크 하고, 다음 지점 방문.
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
int N;
int arr[101];
bool visit[101];
vector<int> answer_list;
void DFS(int start, int cur) {
	if (visit[cur]) {
		if (start == cur) {
			answer_list.push_back(start);
		}
	}
	else {
		visit[cur] = true;
		DFS(start, arr[cur]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		if (i == arr[i]) {
			answer++;
		}
	}
	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		visit[i] = true;
		DFS(i,arr[i]);
	}
	sort(answer_list.begin(), answer_list.end());
	cout << answer_list.size() << endl;
	for (int i = 0; i < answer_list.size(); i++) {
		cout << answer_list[i] << endl;
	}
	return 0;
}
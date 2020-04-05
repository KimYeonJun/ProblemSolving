/*
BOJ 1931번: 회의실배정
문제 유형 :그리디 알고리즘

*/
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (b.second == a.second)
		return a.first < b.first;
	return a.second < b.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	pair<int, int> arr[100001];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, cmp);
	int answer = 0;
	int time = 0;
	for (int i = 0; i < N; i++) {
		if (time <= arr[i].first) {
			time = arr[i].second;
			answer++;
		}
	}
	cout << answer << endl;


	return 0;
}
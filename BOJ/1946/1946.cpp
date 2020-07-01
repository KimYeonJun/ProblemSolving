/*
BOJ 1946번: 신입 사원
문제 유형 : 그리디 알고리즘

서류 순위로 정렬하면, 서류 1등은 무조건 신입사원으로 뽑힘.
서류 1등의 면접 성적을 기준으로 서류 2등부터 나머지 사람들의 채용 우무를 결정한다.
채용이 결정된 사람이 생기면 기준을 갱신한다.

=> 남은 사람들 중 1등만 채용하므로 탐욕적 방법이다.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

vector<pair<int, int>> people;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T, N,answer;
	cin >> T;
	while (T--) {
		cin >> N;
		people.clear();
		for (int i = 0; i < N; i++) {
			pair<int, int> input;
			cin >> input.first >> input.second;
			people.push_back(input);
		}
		sort(people.begin(), people.end(), cmp);
		answer = 1;
		int maxVal = people[0].second;
		for (int i = 1; i < N; i++) {
			if (people[i].second < maxVal) {
				answer++;
				maxVal = people[i].second;
			}

		}
		cout<< answer << endl;

	}
}
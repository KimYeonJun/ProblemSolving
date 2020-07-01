/*
BOJ 1946��: ���� ���
���� ���� : �׸��� �˰���

���� ������ �����ϸ�, ���� 1���� ������ ���Ի������ ����.
���� 1���� ���� ������ �������� ���� 2����� ������ ������� ä�� �칫�� �����Ѵ�.
ä���� ������ ����� ����� ������ �����Ѵ�.

=> ���� ����� �� 1� ä���ϹǷ� Ž���� ����̴�.
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
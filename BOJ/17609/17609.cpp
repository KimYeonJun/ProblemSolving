/*
[BOJ] 17609번: 회문
문제 유형 : 문자열, 

문제 풀이
유사 회문 판별을 O(N^2)에 수행하여 시간초과발생.
회문 조건을 만족하지 않는 left, right를 기준으로
left+1 ~ right, left ~ right-1이 회문인지 확인.
회문이라면 유사회문, 아니라면 아예 회문이 아님.
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
bool isPal(string s) {
	int l = 0, r = s.size() - 1;
	while (l < r) {
		if (s[l] != s[r])
			return false;
		l++;
		r--;
	}
	return true;
}
void Solve() {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		int left = 0, right = s.size() - 1;
		int answer = 0;
		while (left <= right) {
			if (s[left] == s[right]) {
				left++;
				right--;
			}
			else {
				int l = left + 1;
				int r = right;
				while (l < r) {
					if (s[l] != s[r]) {
						answer++;
						break;
					}
					l++; r--;
				}
				l = left;
				r = right - 1;
				while (l < r) {
					if (s[l] != s[r]) {
						answer++;
						break;
					}
					l++; r--;
				}
				break;
			}
		}
		cout << answer << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
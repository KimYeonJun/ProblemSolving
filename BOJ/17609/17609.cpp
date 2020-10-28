/*
[BOJ] 17609��: ȸ��
���� ���� : ���ڿ�, 

���� Ǯ��
���� ȸ�� �Ǻ��� O(N^2)�� �����Ͽ� �ð��ʰ��߻�.
ȸ�� ������ �������� �ʴ� left, right�� ��������
left+1 ~ right, left ~ right-1�� ȸ������ Ȯ��.
ȸ���̶�� ����ȸ��, �ƴ϶�� �ƿ� ȸ���� �ƴ�.
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
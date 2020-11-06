/*
[BOJ] 9935��: ���ڿ� ����
���� ���� : ���ڿ� , ����

���� Ǯ��
1. ���ÿ� ���ڿ��� ��´�.
2. ������ top�� ���� ���ڿ��� �������� ���ٸ� ���� ���ɼ��� �����Ƿ� Ȯ���غ���.
	-> ���� ���ڿ��� ���̸�ŭ ������ top���� ���ʷ� Ȯ���ϸ鼭 pop��Ų��.
3. ���� ���� ���ڿ��� �ƴϿ��ٸ�, pop��Ų string�� �ٽ� stack�� Ǫ���Ѵ�.

*/
#include <stdio.h>
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
string str, sub;
void Input() {
	cin >> str >> sub;
}
void Solution() {
	stack<char> stk;
	for (int i = 0; i < str.size(); i++) {
		stk.push(str[i]);
		if (stk.top() == sub[sub.size() - 1] && stk.size() > sub.size() - 1) {
			string tmp = "";
			bool flag = true;
			for (int j= sub.size() - 1; j >= 0; j--) {
				if (stk.top() == sub[j]) {
					tmp += stk.top();
					stk.pop();
				}
				else {
					flag = false;
					break;
				}
			}
			if (!flag) {
				for (int j = tmp.size() - 1; j >= 0; j--)
					stk.push(tmp[j]);
			}
		}
	}
	str = "";
	while (!stk.empty()) {
		str += stk.top();
		stk.pop();
	}
	reverse(str.begin(), str.end());
	if (str.size() == 0)
		cout << "FRULA" << endl;
	else
		cout << str << endl;
}
void Solve() {
	Input();
	if (sub.size() > str.size()) {
		cout << str << endl;
		return;
	}
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
}
/*
[BOJ] 9935번: 문자열 폭발
문제 유형 : 문자열 , 스택

문제 풀이
1. 스택에 문자열을 담는다.
2. 스택의 top이 폭발 문자열의 마지막과 같다면 폭발 가능성이 있으므로 확인해본다.
	-> 폭발 문자열의 길이만큼 스택의 top부터 차례로 확인하면서 pop시킨다.
3. 만약 폭발 문자열이 아니였다면, pop시킨 string을 다시 stack에 푸시한다.

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
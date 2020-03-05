/*
BOJ 9012: 괄호
문제 유형 :Stack

문제 풀이: 1. 여는 괄호('(') -> stack에 push
		   2. 닫힌 괄호(')') 
		       ->2.1 스택에 여는 괄호가 있으면 PoP
			   ->2.2 스택이 비어있다면 false
		   3. 문자열 확인 후 스택에 empty가 아니면  false
*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int T;
vector<string> ps;

void Input() {
	cin >> T;
	string input;
	for (int i = 0; i < T; i++) {
		cin >> input;
		ps.push_back(input);
	}
}
void Solution() {
	for (int i = 0; i < ps.size(); i++) {
		stack<char> stk;
		bool flag = false;
		for (int j = 0; j < ps[i].size(); j++) {
			if (ps[i][j] == '(') {
				stk.push(ps[i][j]);
			}
			else {
				if (stk.size() != 0) {
					stk.pop();
				}
				else {
					flag = true;
					break;
				}
			}
		}
		if (flag == true) {
			cout << "NO" << endl;
		}
		else {
			if (stk.size() != 0) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
	}

}
void Solve() {
	Input();
	Solution();
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();



	return 0;
}
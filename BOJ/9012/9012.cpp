/*
BOJ 9012: ��ȣ
���� ���� :Stack

���� Ǯ��: 1. ���� ��ȣ('(') -> stack�� push
		   2. ���� ��ȣ(')') 
		       ->2.1 ���ÿ� ���� ��ȣ�� ������ PoP
			   ->2.2 ������ ����ִٸ� false
		   3. ���ڿ� Ȯ�� �� ���ÿ� empty�� �ƴϸ�  false
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
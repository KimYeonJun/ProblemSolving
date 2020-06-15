/*
BOJ 1991번: 트리 순회
문제 유형 : 트리

전위 순회 후위 순회 중위 순회 구현
*/
#include <iostream>

using namespace std;

int N;
int lc[27];
int rc[27];
void Input() {
	cin >> N;
	while (N--) {
		char c, l, r;
		cin >> c >> l >> r;
		if (l != '.') {
			lc[c - 'A' + 1] = l - 'A' + 1;
		}
		if (r != '.') {
			rc[c - 'A' + 1] = r - 'A' + 1;
		}
	}
}
void Preorder(int cur) {
	cout << char(cur - 1 + 'A');
	if(lc[cur]!=0) Preorder(lc[cur]);
	if(rc[cur]!=0) Preorder(rc[cur]);
}
void Inorder(int cur) {
	if(lc[cur]!=0) Inorder(lc[cur]);
	cout << char(cur - 1 + 'A');
	if(rc[cur]!=0) Inorder(rc[cur]);
}
void Postorder(int cur) {
	if(lc[cur]!=0) Postorder(lc[cur]);
	if(rc[cur]!=0) Postorder(rc[cur]);
	cout << char(cur - 1 + 'A');
}
void Solution() {
	Preorder(1);
	cout << endl;
	Inorder(1);
	cout << endl;
	Postorder(1);
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
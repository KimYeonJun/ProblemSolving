#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int result, n, k;
int diamonds[1001];
void Initialize() {
	result = 0;
	memset(diamonds, 0, sizeof(diamonds));
}
void Input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> diamonds[i];
	}
}
void Solution() {
	sort(diamonds, diamonds + n);
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = i + 1; j < n; j++) {
			if (diamonds[j] - diamonds[i] <= k)
				cnt++;
			else
				break;
		}
		if (result < cnt)
			result = cnt;
	}
}
void Solve() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		Initialize();
		Input();
		Solution();
		cout << "#" << i << " " << result << endl;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	Solve();
	return 0;
}
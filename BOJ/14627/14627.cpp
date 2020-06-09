/*
BOJ 14627¹ø: ÆÄ´ßÆÄ´ß
¹®Á¦ À¯Çü : ÀÌºÐ Å½»ö
*/

#include <iostream>
#include <algorithm>
using namespace std;

int S, C;
int pars[1000001];
void Input() {
	cin >> S >> C;
	for (int i = 0; i < S; i++) {
		cin >> pars[i];
	}
}
void Solution() {
	sort(pars, pars + S);
	int l = 1, r = pars[S-1];
	long mid;
	long result=0;
	while (l <= r) {
		mid = (l + r) / 2;
		int cnt = 0;
		long sum = 0;
		for (int i = 0; i < S; i++) {
			cnt += pars[i] / mid;
			sum += pars[i] % mid;
		}
		if (cnt >= C) {
			l = mid + 1;
			result = sum + (cnt-C) * mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout<<result<<endl;

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
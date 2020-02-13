#include <iostream>
#include <cstring>
using namespace std;
int price[1000000];
int N;
void Initialize() {
	memset(price, 0, sizeof(price));
}
void Input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> price[i];
	}
}
long long  Solution() {
	int max_price = price[N - 1];
	long long benefit = 0;
	for (int i = N - 2; i >= 0; i--) {
		if (price[i] > max_price)
			max_price = price[i];
		else {
			benefit += max_price - price[i];
		}
	}
	return benefit;

}
void Solve() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		Initialize();
		Input();
		long long result = Solution();
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
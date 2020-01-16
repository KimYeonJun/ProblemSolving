#include <iostream>

#define endl "\n"
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= 4 * N - 3; i++) {
		if (i <= 2 * N - 1) {
			if (i % 2 == 0) {
				for (int j = 1; j < i; j++) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
				for (int j = i; j <= 4 * N - 3 - i + 1; j++) {
					cout << " ";
				}
				for (int j = 4 * N - 3 - i + 2; j <= 4 * N - 3; j++) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
			}
			else {
				for (int j = 1; j < i; j++) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
				for (int j = i; j <= 4 * N - 3 - (i - 1); j++) {
					cout << "*";
				}
				for (int j = 4 * N - 3 - (i - 1) + 1; j <= 4 * N - 3; j++) {
					if (j % 2 == 0) {
						cout << " ";
					}
					else
						cout << "*";
				}
			}
		}
		else {
			if (i % 2 == 0) {
				for (int j = 4*N-3; j >= i+1; j--) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
				for (int j = i; j >= 4 * N - 3 - i + 1; j--) {
					cout << " ";
				}
				for (int j = 4 * N - 3 - i; j >= 1; j--) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
			}
			else {
				for (int j = 4*N-3; j >= i; j--) {
					if (j % 2 == 1)
						cout << "*";
					else
						cout << " ";
				}
				for (int j = i-1; j >= 4 * N - 3 - i + 2; j--) {
					cout << "*";
				}
				for (int j = 4 * N - 3 - i + 1; j >= 1; j--) {
					if (j % 2 == 0) {
						cout << " ";
					}
					else
						cout << "*";
				}
			}
		}
		cout << endl;
	}

	return 0;
}
#include <iostream>

using namespace std;
int N;
int T[16];
int P[16];
int result = 0;
void Input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		cin >> P[i];
	}

}

void DFS(int idx, int sum) {
	if (idx == N + 1) {
		if (result < sum)
			result = sum;
		return;
	}
	DFS(idx + 1, sum);
	if (idx + T[idx] <= N + 1) {
		DFS(idx + T[idx], sum + P[idx]);
	}
}
void Solution() {

	DFS(1, 0);
	cout << result << endl;
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
//실패작들
/*void DFS(int idx,int sum) { 
	if (result < sum)
		result = sum;
	if (idx + T[idx] > N) {
		return;
	}
	for (int i = idx + T[idx]; i < N; i++) {
		cout << "Hi: " << i << " " << sum << " "<<P[i]<<" " << sum + P[i] << endl;
		if (i + T[i] <= N) {
			DFS(i, sum + P[i]);
		}
		cout << "Bye: " << i << " " << sum << " " << P[i] << " " << sum + P[i] << endl;
	}
}*/
/*void DFS(int idx, int sum) {
	if (idx >= N + 1) {
		if (result < sum)
			result = sum;
		return;
	}

	if(idx+T[idx]<=N+1){
		DFS(idx + T[idx], sum + P[idx]);
	}
	if (idx + 1 <= N + 1) {
		DFS(idx + 1, sum);
	}


}*/
/*void DFS(int idx, int sum) {

	if (idx >= N + 1) {
		if (result < sum)
			result = sum;
		return;
	}
	if (idx + T[idx] <= N + 1) { //상담 하는 경우
		cout<<"ok" << idx << endl;
		DFS(idx + T[idx], sum + P[idx]);
	}
	if (idx + 1 <= N+1) { //상담안하고 다음날 상담하는 경우
		cout << "no" << idx << endl;
		DFS(idx + 1, sum);
	}




}*/
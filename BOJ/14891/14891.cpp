#include <iostream>
#include <string>
#include <cmath>
using namespace std;
string clockRot(string gear) { //시계방향

	char tmp = gear[7];
	for (int i = 7; i >= 1; i--) {
		gear[i] = gear[i - 1];
	}
	gear[0] = tmp;

	return gear;
}
string RclockRot(string gear) {//반시계방향

	char tmp = gear[0];
	for (int i = 0; i < 8; i++) {
		gear[i] = gear[i + 1];
	}
	gear[7] = tmp;

	return gear;
}
int main() {

	string gear[5];
	for (int i = 1; i < 5; i++) {
		cin >> gear[i];
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int num, dir;
		int dirList[5] = { 0, };
		cin >> num >> dir;

		dirList[num] = dir;
		for (int j = num; j >= 1; j--) { //num기준 왼쪽 톱니들
			if ((j == 1) || (gear[j][6] == gear[j - 1][2])) {
				break;
			}
			else {
				if (dir == 1) {
					
					dirList[j - 1] = -1;
					dir = -1;
				}
				else {
					
					dirList[j - 1] = 1;
					dir = 1;
				}
			}
		}
		dir = dirList[num];
		for (int j = num; j <= 4; j++) { //오른쪽
			if ((j == 4) || (gear[j][2] == gear[j + 1][6])) {
				
				break;
			}
			else {
				if (dir == 1) {
					dirList[j + 1] = -1;
					dir = -1;
				}
				else {
					dirList[j + 1] = 1;
					dir = 1;
				}
			}
		}

		for (int i = 1; i <= 4; i++) {
			if (dirList[i] == 1) {
				gear[i] = clockRot(gear[i]);
			}
			else if (dirList[i] == -1){
				gear[i] = RclockRot(gear[i]);
			}
		}

	}
	int result = 0;
	for (int i = 0; i < 4; i++) {
		//cout << gear[i + 1] << endl;
		if (gear[i + 1][0] == '1') {
			result += (pow(2, i));
		}
	}
	cout << result << '\n';


	return 0;
}
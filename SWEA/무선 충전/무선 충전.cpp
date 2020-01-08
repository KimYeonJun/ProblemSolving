#include <iostream>
#include <vector>
#include <cstdlib>
/*
A의 시작 지점 : 1,1
B의 시작 지점 : 10,10
*/
using namespace std;

struct BC {
	int x;
	int y;
	int c; //충전 범위
	int p; //처리량
};
struct point {
	int x;
	int y;

};
int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A_move[102];
		int B_move[102];
		int M, A; //M : 총 이동시간, A : BC의 개수
		int A_sum = 0;
		int B_sum = 0;
		cin >> M >> A;
		A_move[0] = 0;
		B_move[0] = 0;
		for (int j = 1; j <= M; j++) //A 이동
			cin >> A_move[j];
		for (int j = 1; j <= M; j++) //B 이동
			cin >> B_move[j];
		vector<BC> BC_list;
		for (int j = 0; j < A; j++) { //BC정보 입력
			BC tmp;
			cin >> tmp.x;
			cin >> tmp.y;
			cin >> tmp.c;
			cin >> tmp.p;
			BC_list.push_back(tmp);
		}
		
		point A_point,B_point;
		A_point.x = 1;
		A_point.y = 1;
		B_point.x = 10;
		B_point.y = 10;
		for (int j = 0; j <= M; j++) { //움직이기
			if (A_move[j] == 1)
				A_point.y = A_point.y - 1;
			else if (A_move[j] == 2)
				A_point.x = A_point.x + 1;
			else if (A_move[j] == 3)
				A_point.y = A_point.y + 1;
			else if (A_move[j] == 4)
				A_point.x = A_point.x - 1;

			if (B_move[j] == 1)
				B_point.y = B_point.y - 1;
			else if (B_move[j] == 2)
				B_point.x = B_point.x + 1;
			else if (B_move[j] == 3)
				B_point.y = B_point.y + 1;
			else if (B_move[j] == 4)
				B_point.x = B_point.x - 1;

			
			int A_p = 0;
			int B_p = 0;

			//std::cout << "A의 좌표 : " << A_point.x << " " << A_point.y << endl;
			//std::cout << "B의 좌표 : " << B_point.x << " " << B_point.y << endl;
			for (int k = 0; k < BC_list.size(); k++) {
				/*if (abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) {
					tmp_A_p = BC_list[k].p;
				}*/
				for (int l = 0; l < BC_list.size(); l++) {
					int tmp_A_p = 0;
					int tmp_B_p = 0;
					if ((abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) && (abs(B_point.x - BC_list[l].x) + abs(B_point.y - BC_list[l].y) <= BC_list[l].c)) {
						//A,B둘다 포함된 경우
						if (k == l) {
							tmp_A_p = BC_list[l].p / 2;
							tmp_B_p = BC_list[l].p / 2;
						}
						else {
							tmp_A_p = BC_list[k].p;
							tmp_B_p = BC_list[l].p;
						}
						//원래의 B가 더 큰경우.
						//둘 다 아닌경우.
					}
					else {
						if (abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) { //A만 포함
							tmp_A_p = BC_list[k].p;
						}
						else if (abs(B_point.x - BC_list[l].x) + abs(B_point.y - BC_list[l].y) <= BC_list[l].c) { //B만 포함
							
							tmp_B_p = BC_list[l].p;
						}
					}
					if (A_p + B_p < tmp_B_p + tmp_A_p) {
						A_p = tmp_A_p;
						B_p = tmp_B_p;
					}

				}
				
			}
			//std::cout << j << ": " << A_p << " " << B_p << endl;
			A_sum += A_p;
			B_sum += B_p;
			/*for (int k = 0; k < BC_list.size(); k++) {
				if ((abs(A_point.x - BC_list[i].x) + abs(A_point.y - BC_list[i].y) <= BC_list[i].c) && (abs(B_point.x - BC_list[i].x) + abs(B_point.y - BC_list[i].y) <= BC_list[i].c)) {
					//A,B둘다 포함된 경우

					//원래의 A가 더 큰경우
					if (A_p > BC_list[i].p / 2) {

					}
					//원래의 B가 더 큰경우.
					//둘 다 아닌경우.
				}
				else {
					if (abs(A_point.x - BC_list[i].x) + abs(A_point.y - BC_list[i].y) <= BC_list[i].c) { //A만 포함
						if (A_p < BC_list[i].p)
							A_p = BC_list[i].p;
					}
					else if (abs(B_point.x - BC_list[i].x) + abs(B_point.y - BC_list[i].y) <= BC_list[i].c) { //B만 포함
						if (B_p < BC_list[i].p)
							B_p = BC_list[i].p;
					}
				}*/

			
		}
		
		//std::cout << "A의 p : " << A_sum << endl;
		//std::cout << "B의 p : " << B_sum << endl;
		std::cout << "#" << i + 1 << " " << A_sum + B_sum << endl;
	}
	std::cout << "what" << endl;

	return 0;
}
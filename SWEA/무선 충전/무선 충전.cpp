#include <iostream>
#include <vector>
#include <cstdlib>
/*
A�� ���� ���� : 1,1
B�� ���� ���� : 10,10
*/
using namespace std;

struct BC {
	int x;
	int y;
	int c; //���� ����
	int p; //ó����
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
		int M, A; //M : �� �̵��ð�, A : BC�� ����
		int A_sum = 0;
		int B_sum = 0;
		cin >> M >> A;
		A_move[0] = 0;
		B_move[0] = 0;
		for (int j = 1; j <= M; j++) //A �̵�
			cin >> A_move[j];
		for (int j = 1; j <= M; j++) //B �̵�
			cin >> B_move[j];
		vector<BC> BC_list;
		for (int j = 0; j < A; j++) { //BC���� �Է�
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
		for (int j = 0; j <= M; j++) { //�����̱�
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

			//std::cout << "A�� ��ǥ : " << A_point.x << " " << A_point.y << endl;
			//std::cout << "B�� ��ǥ : " << B_point.x << " " << B_point.y << endl;
			for (int k = 0; k < BC_list.size(); k++) {
				/*if (abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) {
					tmp_A_p = BC_list[k].p;
				}*/
				for (int l = 0; l < BC_list.size(); l++) {
					int tmp_A_p = 0;
					int tmp_B_p = 0;
					if ((abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) && (abs(B_point.x - BC_list[l].x) + abs(B_point.y - BC_list[l].y) <= BC_list[l].c)) {
						//A,B�Ѵ� ���Ե� ���
						if (k == l) {
							tmp_A_p = BC_list[l].p / 2;
							tmp_B_p = BC_list[l].p / 2;
						}
						else {
							tmp_A_p = BC_list[k].p;
							tmp_B_p = BC_list[l].p;
						}
						//������ B�� �� ū���.
						//�� �� �ƴѰ��.
					}
					else {
						if (abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) { //A�� ����
							tmp_A_p = BC_list[k].p;
						}
						else if (abs(B_point.x - BC_list[l].x) + abs(B_point.y - BC_list[l].y) <= BC_list[l].c) { //B�� ����
							
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
					//A,B�Ѵ� ���Ե� ���

					//������ A�� �� ū���
					if (A_p > BC_list[i].p / 2) {

					}
					//������ B�� �� ū���.
					//�� �� �ƴѰ��.
				}
				else {
					if (abs(A_point.x - BC_list[i].x) + abs(A_point.y - BC_list[i].y) <= BC_list[i].c) { //A�� ����
						if (A_p < BC_list[i].p)
							A_p = BC_list[i].p;
					}
					else if (abs(B_point.x - BC_list[i].x) + abs(B_point.y - BC_list[i].y) <= BC_list[i].c) { //B�� ����
						if (B_p < BC_list[i].p)
							B_p = BC_list[i].p;
					}
				}*/

			
		}
		
		//std::cout << "A�� p : " << A_sum << endl;
		//std::cout << "B�� p : " << B_sum << endl;
		std::cout << "#" << i + 1 << " " << A_sum + B_sum << endl;
	}
	std::cout << "what" << endl;

	return 0;
}
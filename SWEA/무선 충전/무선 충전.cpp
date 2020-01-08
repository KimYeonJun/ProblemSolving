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
	int dx[5] = { 0,0,1,0,-1 };
	int dy[5] = { 0,-1,0,1,0 };
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

			A_point.x += dx[A_move[j]];
			A_point.y += dy[A_move[j]];
			B_point.x += dx[B_move[j]];
			B_point.y += dy[B_move[j]];
			
			int A_p = 0;
			int B_p = 0;

			for (int k = 0; k < BC_list.size(); k++) {
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
					else { //���߿� �ϳ��� ���Ե� ���
						if (abs(A_point.x - BC_list[k].x) + abs(A_point.y - BC_list[k].y) <= BC_list[k].c) { //A�� ����
							tmp_A_p = BC_list[k].p;
						}
						else if (abs(B_point.x - BC_list[l].x) + abs(B_point.y - BC_list[l].y) <= BC_list[l].c) { //B�� ����
							
							tmp_B_p = BC_list[l].p;
						}
					}
					if (A_p + B_p < tmp_B_p + tmp_A_p) { //max�� ã��
						A_p = tmp_A_p;
						B_p = tmp_B_p;
					}

				}
				
			}
			A_sum += A_p;
			B_sum += B_p;
		}
		std::cout << "#" << i + 1 << " " << A_sum + B_sum << endl;
	}

	return 0;
}
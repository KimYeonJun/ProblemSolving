/*
���α׷��ӽ� : ū �� �����
���� ���� : �׸��� �˰���

���� Ǯ��
1. ������ �ڸ����� ���Ѵ�. (ex) number�� 1924�� k�� 2�� ������ 2�ڸ�
2. �� �ڸ����� �ִ�� �����. (���� �ڸ��� 1,9,2�� �� 9�� �ִ��̹Ƿ� ���� �ڸ��� 2,4 �� �ִ� ��)
*/
#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int idx = 0;
    for (int i = number.size() - k; i > 0; i--) {
        int max = number[idx] - '0';
        for (int j = idx + 1; j <= number.size() - i; j++) {
            if (number[j] - '0' > max) {
                max = number[j] - '0';
                idx = j;
            }
        }
        idx++;
        answer += (max + '0');
    }
    return answer;
}
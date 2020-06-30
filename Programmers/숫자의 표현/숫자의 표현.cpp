/*
���α׷��ӽ�: ������ ǥ��
���� ���� : �������� �˰���

�ð����⵵ : O(N)
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0;
    int l = 1, r = 1;
    while (true) {
        if (sum >= n)
            sum -= l++;
        else if (r == n) {
            answer++;
            break;
        }
        else
            sum += r++;
        if (sum == n)
            answer++;
    }
    return answer;
}
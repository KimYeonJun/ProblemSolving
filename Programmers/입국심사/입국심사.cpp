/*
[Programmers] �Ա��ɻ�
���� ���� : �̺�Ž��

�Ա��ɻ縦 ��ٸ��� n ������ 1,000,000,000(10��)�̴�.
�ɻ���� 100,000��.
�̺�Ž������ Ǯ�� 100,000 * log(10��) ���� Ǯ�� ����.
*/
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    long long l = 1, r = (long long)times[times.size() - 1] * n;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (int i = 0; i < times.size(); i++) {
            sum += mid / times[i];
        }
        if (sum < n) {
            l = mid + 1;
        }
        else {
            answer = mid;
            r = mid - 1;
        }
    }

    return answer;
}
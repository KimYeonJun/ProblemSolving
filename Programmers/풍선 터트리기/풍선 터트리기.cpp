/*
���α׷��ӽ� : ǳ�� ��Ʈ����

ǳ���� ���ı��� ����� ���� ������ ���� ������ ����.
1. �� ���� ǳ��
2. �� ������ ǳ��
3. ��Ʈ������ ǳ���� �������� ��,���� �ּҰ� ���� ũ�� ���� ���
(��,���� �ּҰ� �� 1���� ū ���� ����������, �� �� ���� ũ�ٸ� �ȵ�)

=> left_min �迭�� �ش� �ε����� ���� ���� ���� ���� �ּҰ��� ����
   right_min �迭�� �ش� �ε����� ���� ������ ���� ���� �ּҰ��� ����
   ��Ʈ������ ǳ���� �������� ��,�� �ּҰ��� ���Ͽ� ����� ���� �������� Ȯ��
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int left_min[1000001];
int right_min[1000001];
int solution(vector<int> a) {
    int answer = 0;
    left_min[0] = a[0];
    right_min[a.size() - 1] = a[a.size() - 1];
    for (int i = 1; i < a.size(); i++) {
        left_min[i] = min(left_min[i - 1], a[i]);
        right_min[a.size() - i - 1] = min(right_min[a.size() - i], a[a.size() - i - 1]);
    }
    for (int i = 0; i < a.size(); i++) {
        if (i == 0 || i == a.size() - 1) {
            answer++;
        }
        else {
            if (a[i] >= left_min[i - 1] && a[i] >= right_min[i + 1])
                continue;
            answer++;
        }
    }
    return answer;
}
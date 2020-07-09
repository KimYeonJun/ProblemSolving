/*
���α׷��ӽ� : ������ ��ġ


���� Ǯ��
1. N�� 2�� �̱� ������ Ž���ϴ� ����� �Ұ���, ����ȭ ���Ѽ� Ǯ�����
2. 1�� ����Ʈ ���� ~ ó�� ������ ������ ���� ���� ���̿� ������ �ּ� ��ġ Ƚ���� ����
    2.1) left-start(���İ� ���޵��� �ʴ� ����Ʈ ��) / range(�������� ���� ����) = ������ ��ġ ��
    2.2) (left-start) % range > 0 ���� ũ�� 1�� �� ��ġ
3. 2���� �ݺ�
4. ��ġ�� �������� ���� �����ʰ� ���� ������ ����Ʈ ������ ������ ��ġ ���� ���ϱ� ���� 2�� ����
*/
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int start = 1;
    int range = w * 2 + 1;
    for (int i = 0; i < stations.size(); i++) {
        int left = stations[i] - w;
        int right = stations[i] + w;
        if (start >= left && start <= right) {
            start = right + 1;
            continue;
        }
        int new_station = (left - start) / range;
        if ((left - start) % range > 0)
            new_station++;
        answer += new_station;
        start = right + 1;
    }
    if (start < n + 1) {
        int new_station = (n + 1 - start) / range;
        if ((n + 1 - start) % range > 0)
            new_station++;
        answer += new_station;
    }

    return answer;
}
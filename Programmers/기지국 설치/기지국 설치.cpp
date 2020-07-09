/*
프로그래머스 : 기지국 설치


문제 풀이
1. N이 2억 이기 때문에 탐색하는 방법은 불가능, 최적화 시켜서 풀어야함
2. 1번 아파트 부터 ~ 처음 기지국 범위의 가장 왼쪽 사이에 기지국 최소 설치 횟수를 구함
    2.1) left-start(전파가 전달되지 않는 아파트 수) / range(기지국의 전파 범위) = 기지국 설치 수
    2.2) (left-start) % range > 0 보다 크면 1개 더 설치
3. 2번을 반복
4. 설치된 기지국의 가장 오른쪽과 가장 마지막 아파트 사이의 기지국 설치 수를 구하기 위해 2번 적용
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
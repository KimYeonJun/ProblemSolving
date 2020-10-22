/*
프로그래머스 : 풍선 터트리기

풍선을 최후까지 남기는 것이 가능한 경우는 다음과 같다.
1. 맨 왼쪽 풍선
2. 맨 오른쪽 풍선
3. 터트리려는 풍선을 기준으로 좌,우의 최소값 보다 크지 않은 경우
(좌,우의 최소값 중 1개만 큰 것은 가능하지만, 두 값 보다 크다면 안됨)

=> left_min 배열에 해당 인덱스를 기준 왼쪽 값중 가장 최소값을 저장
   right_min 배열에 해당 인덱스를 기준 오른쪽 갑중 가장 최소값을 저장
   터트리려는 풍선을 기준으로 좌,우 최소값을 비교하여 남기는 것이 가능한지 확인
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
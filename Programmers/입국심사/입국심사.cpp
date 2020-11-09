/*
[Programmers] 입국심사
문제 유형 : 이분탐색

입국심사를 기다리는 n 제한이 1,000,000,000(10억)이다.
심사관은 100,000명.
이분탐색으로 풀면 100,000 * log(10억) 으로 풀이 가능.
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
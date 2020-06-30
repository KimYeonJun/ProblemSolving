/*
프로그래머스: 숫자의 표현
문제 유형 : 투포인터 알고리즘

시간복잡도 : O(N)
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
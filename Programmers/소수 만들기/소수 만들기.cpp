#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
bool visit[51];
int answer = 0;
bool isPrime(int num) {
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
void DFS(vector<int>& nums, int idx, int cnt, int sum) {
    if (cnt == 3) {
        if (isPrime(sum))
            answer++;
        return;
    }
    for (int i = idx; i < nums.size(); i++) {
        if (visit[i])
            continue;
        visit[i] = true;
        sum += nums[i];
        DFS(nums, i, cnt + 1, sum);
        sum -= nums[i];
        visit[i] = false;
    }
}
int solution(vector<int> nums) {
    DFS(nums, 0, 0, 0);
    return answer;
}
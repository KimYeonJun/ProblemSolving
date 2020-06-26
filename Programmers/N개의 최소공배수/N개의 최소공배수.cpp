/*
프로그래머스 : N개의 최소공배수

lcd(최대공배수) : x * y / gcd(x,y)
gcd(최대공약수) : x%y==0? y : gcd(y,x%y) 
*/
#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y) {
    return x % y == 0 ? y : gcd(y, x % y);
}
int lcm(int x, int y) {
    return x * y / gcd(x, y);
}
int solution(vector<int> arr) {
    int answer = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    return answer;
}
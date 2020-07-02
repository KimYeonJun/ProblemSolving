/*
2020 카카오 인턴십 1번
프로그래머스: 키패드 누르기
문제 유형 : 구현
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> loc{ {3,1},{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2} };
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_x = 3, left_y = 0;
    int right_x = 3, right_y = 2;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += "L";
            left_x = loc[numbers[i]].first;
            left_y = loc[numbers[i]].second;
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += "R";
            right_x = loc[numbers[i]].first;
            right_y = loc[numbers[i]].second;
        }
        else {
            int x = loc[numbers[i]].first;
            int y = loc[numbers[i]].second;
            int left_dis = abs(left_x - x) + abs(left_y - y);
            int right_dis = abs(right_x - x) + abs(right_y - y);
            if (left_dis > right_dis || ((left_dis == right_dis) && hand == "right")) {
                right_x = x;
                right_y = y;
                answer += "R";
            }
            else {
                left_x = x;
                left_y = y;
                answer += "L";
            }
        }

    }
    return answer;
}
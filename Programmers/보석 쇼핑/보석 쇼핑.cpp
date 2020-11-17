/*
[Programmers] 보석 쇼핑
문제 유형 : 투포인터 알고리즘, 자료구조(map,set)

문제 풀이
gems 배열의 길이가 100,000이므로 O(N^2)의 풀이는 시간초과 발생.
-> 투포인터 알고리즘을 사용하여 O(N)에 풀이

배열의 l과 r 구간은 모든 종류의 보석을 포함하는 구간이 된다.

구간 중 가장 짧은 구간을 구해야하기 때문에 l 인덱스를 증가시키며,
구간의 길이를 줄인다.
*/

#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second - a.first == b.second - b.first)
        return a.first < b.first;
    return a.second - a.first < b.second - b.first;
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    vector<pair<int, int>> answer_list;
    set<string> s;
    for (string gem : gems)
        s.insert(gem);
    int l = 0, r = 0;
    map<string, int> m;
    while (1) {
        if (m.size() == s.size()) {
            if (m[gems[l]] == 1) {
                m.erase(gems[l]);
            }
            else {
                m[gems[l]]--;
            }
            l++;
        }
        else if (r == gems.size())
            break;
        else {
            m[gems[r]]++;
            r++;
        }
        if (m.size() == s.size()) {
            answer_list.push_back({ l,r - 1 });
        }
    }
    sort(answer_list.begin(), answer_list.end(), cmp);
    answer.push_back(answer_list[0].first + 1);
    answer.push_back(answer_list[0].second + 1);
    return answer;
}
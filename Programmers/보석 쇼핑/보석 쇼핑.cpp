/*
[Programmers] ���� ����
���� ���� : �������� �˰���, �ڷᱸ��(map,set)

���� Ǯ��
gems �迭�� ���̰� 100,000�̹Ƿ� O(N^2)�� Ǯ�̴� �ð��ʰ� �߻�.
-> �������� �˰����� ����Ͽ� O(N)�� Ǯ��

�迭�� l�� r ������ ��� ������ ������ �����ϴ� ������ �ȴ�.

���� �� ���� ª�� ������ ���ؾ��ϱ� ������ l �ε����� ������Ű��,
������ ���̸� ���δ�.
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
/*
Programmers ĳ��
���� ���� : �ù�

c++ String ��ҹ��� ���о��� �񱳽�, transform�Լ��� ����� �ҹ��ڷ� ��ȯ �� ���ϴ°� ����.
ó����, queue�� �����ߴµ� vector�� Ǫ�°� �ξ� ����ϴ�(ť�� pop,push�� ���������ϴµ� vector�� erase�� �ѹ��� ���� �� ����)
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    if (cacheSize == 0)
        return cities.size() * 5;
    vector<string> cacheList;
    for (int i = 0; i < cities.size(); i++) {
        string now = cities[i];
        transform(now.begin(), now.end(), now.begin(), ::tolower);
        bool flag = false;
        for (int j = 0; j < cacheList.size(); j++) {
            string cur = cacheList[j];
            if (cur == now) {
                cacheList.erase(cacheList.begin() + j);
                cacheList.push_back(cur);
                flag = true;
                answer += 1;
                break;
            }
        }
        if (!flag) {
            answer += 5;
            if (cacheList.size() >= cacheSize) {
                cacheList.erase(cacheList.begin());
            }
            cacheList.push_back(now);
        }

    }
    return answer;
}
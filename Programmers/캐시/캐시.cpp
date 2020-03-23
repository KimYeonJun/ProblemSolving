/*
Programmers 캐시
문제 유형 : 시뮬

c++ String 대소문자 구분없이 비교시, transform함수를 사용해 소문자로 변환 후 비교하는게 편함.
처음에, queue로 접근했는데 vector로 푸는게 훨씬 깔끔하다(큐는 pop,push를 계속해줘야하는데 vector는 erase로 한번에 지울 수 있음)
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
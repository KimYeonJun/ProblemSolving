/*
2019 카카오 개발자 겨울 인터십 : 호텔 방 배정
문제 유형 : 유니온 파인드(disjoint-set)

입력 k 의 범위가 1 ~ 10^12이므로
map을 사용한 유니온 파인드로 풀어야함.
(k개 만큼의 배열 선언을 못하므로)

또한, union의 과정이 무조건m[val]=val+1이 되어야 하므로
따로 union함수가 없어도 된다.
*/
#include <string>
#include <vector>
#include <unordered_map>
typedef long long ll;
using namespace std;
unordered_map<ll, ll> m;
ll find(ll u) {
    if (0 == m[u])
        return u;
    return m[u] = find(m[u]);
}
void uni(ll u, ll v) {
    u = find(u);
    v = find(v);
    m[u] = v;
}
vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer;
    for (int i = 0; i < room_number.size(); i++) {
        long long val = find(room_number[i]);
        answer.push_back(val);
        m[val] = val + 1;
    }
    return answer;
}
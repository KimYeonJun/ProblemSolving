/*
2019 īī�� ������ �ܿ� ���ͽ� : ȣ�� �� ����
���� ���� : ���Ͽ� ���ε�(disjoint-set)

�Է� k �� ������ 1 ~ 10^12�̹Ƿ�
map�� ����� ���Ͽ� ���ε�� Ǯ�����.
(k�� ��ŭ�� �迭 ������ ���ϹǷ�)

����, union�� ������ ������m[val]=val+1�� �Ǿ�� �ϹǷ�
���� union�Լ��� ��� �ȴ�.
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
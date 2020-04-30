///*
//SWEA 5648��: ���� �Ҹ� �ùķ��̼�
//
//���ڵ��� �� N�� 1000�� ����.
//�������� 1<=K<=100
//ó�� ��ġ x,y �� -1000<= x,y <=1000
//���ڵ��� ������ �� �ִ� ��ǥ�� ������ ������ ����.
//0,1,2,3 �� �� �� �� 
//���� �ٲ��� �Ⱦ���
//
// 0 < = x,y <= 2000
// -1�Ǹ� ��Ż?
//*/
//#include <iostream>
//#include <vector>
//#include <cstring>
//using namespace std;
//struct atom {
//    int x;
//    int y;
//    int dir;
//    int k;
//};
//vector<atom> atom_list;
//bool visit[1000];
//int dx[4] = { 0,0,-1,1 };
//int dy[4] = { 1,-1,0,0 };
//int N,result,cnt;
//void Input() {
//    cin >> N;
//    int x, y, dir, k;
//    for (int i = 0; i < N; i++) {
//        cin >> x >> y >> dir >> k;
//        atom_list.push_back({ x + 1000,y + 1000,dir,k });
//    }//(y,x)�� ����.
//}
//void Initialize() {
//    atom_list.clear();
//    memset(visit, 0, sizeof(visit));
//    result = 0;
//    cnt = 0;
//}
//bool OpDir(int& d, int& d2) {
//    if (d == 0) {
//        if (d2 == 1)
//            return true;
//    }
//    else if (d == 1) {
//        if (d2 == 0)
//            return true;
//    }
//    else if (d == 2) {
//        if (d2 == 3)
//            return true;
//    }
//    else {
//        if (d2 == 2)
//            return true;
//    }
//    return false;
//}
//void Move() {
//    for (int i = 0; i < atom_list.size(); i++) {
//        if (visit[i])
//            continue;
//        atom cur = atom_list[i];
//        int nx = cur.x + dx[cur.dir];
//        int ny = cur.y + dy[cur.dir];
//        
//        if (nx < 0 || ny < 0 || nx>2000 || ny>2000) {
//            visit[i] = true;
//            cnt++;
//            continue;
//        }
//        //cout << i << " " << nx << " " << ny << endl;
//        atom_list[i].x = nx;
//        atom_list[i].y = ny;
//    }
//}
//void CheckMeet() {
//    for (int i = 0; i < atom_list.size(); i++) {
//        if (visit[i])
//            continue;
//        int x = atom_list[i].x;
//        int y = atom_list[i].y;
//        int d = atom_list[i].dir;
//        bool flag = false;
//        for (int j = 0; j < atom_list.size(); j++) {//���� ���߿� ������?
//            if (visit[j] || i == j)
//                continue;
//            if (x - dx[d] == atom_list[j].x && y - dy[d] == atom_list[j].y) {
//                if (OpDir(d, atom_list[j].dir)) {
//                    flag = true;
//                    cnt += 2;
//                    visit[i] = true;
//                    visit[j] = true;
//                    result += atom_list[i].k + atom_list[j].k;
//                    
//                    break;
//                }
//            }
//        }
//        if (flag)
//            continue;
//        for (int j = 0; j < atom_list.size(); j++) { //���� ������?
//            if (visit[j] || i == j)
//                continue;
//            if (x == atom_list[j].x && y == atom_list[j].y) {
//                visit[j] = true;
//                flag = true;
//                cnt++;
//                result += atom_list[j].k;
//               // cout << "Hi: " << i <<" "<<j<< endl;
//            }
//        }
//        if (flag) {
//            visit[i] = true;
//            result += atom_list[i].k;
//            cnt++;
//        }
//    }
//}
//void Solution() {
//    while (cnt<atom_list.size()) {
//        //cout << cnt << endl;
//        //�����δ�
//        Move();
//        //���� ��ġ�� �ְ� �ְų�
//        //�� �� ��ġ�� ���Ұ� �ְ�&�� ������ ������ ���� �ݴ��� ������.
//        CheckMeet();
//    }
//}
//void Solve() {
//    int T;
//    cin >> T;
//    for (int i = 1; i <= T; i++) {
//        Initialize();
//        Input();
//        Solution();
//        cout << "#" << i << " " << result << endl;
//    }
//}
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    Solve();
//    return 0;
//}
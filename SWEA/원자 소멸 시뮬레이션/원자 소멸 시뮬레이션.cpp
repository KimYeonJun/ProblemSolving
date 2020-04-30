///*
//SWEA 5648번: 원자 소멸 시뮬레이션
//
//원자들의 수 N은 1000개 이하.
//에너지는 1<=K<=100
//처음 위치 x,y 는 -1000<= x,y <=1000
//원자들이 움직일 수 있는 좌표의 범위에 제한은 없다.
//0,1,2,3 상 하 좌 우 
//방향 바뀌지 안않음
//
// 0 < = x,y <= 2000
// -1되면 이탈?
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
//    }//(y,x)로 접근.
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
//        for (int j = 0; j < atom_list.size(); j++) {//가는 도중에 만났나?
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
//        for (int j = 0; j < atom_list.size(); j++) { //가서 만났나?
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
//        //움직인다
//        Move();
//        //같은 위치인 애가 있거나
//        //그 전 위치에 원소가 있고&그 원소의 방향이 나와 반대라면 만난것.
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
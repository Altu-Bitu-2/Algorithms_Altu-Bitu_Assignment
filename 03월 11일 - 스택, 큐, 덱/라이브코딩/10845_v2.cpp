//
// Created by BaeSuA on 2022-03-11.
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다.  
//

// STL queue 이용해서 문제 풀기 
// + 추가내용 : 큐의 순회 

#include <iostream>
#include <vector>
#include <queue> // 헤더 선언해주기  

using namespace std;
const int SIZE = 1e4 + 1; //큐는 0번을 비우고 1번 인덱스부터 값이 들어감

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0; //0번 위치가 비어있으므로 시작은 둘다 0 

//STL queue 자체에 v1에서 작성했던 함수들이 정의되어 있기 때문에 작성할 필요X 

int main() {
    int n, x;
    string cmd; //명령 
    queue<int> q; //큐 선언 

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //if (!full()) { //라이브러리 사용 시 필요 x
            q.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (q.empty()) { //큐가 비어있다면
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
                q.pop(); //앞에 원소 삭제
            }
            continue;
        }
        if (cmd == "size") {
            cout << q.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << q.empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.front() << '\n';
            }
            continue;
        }
        if (cmd == "back") {
            if (q.empty()) {
                cout << "-1\n";
            } else {
                cout << q.back() << '\n';
            }
        }
    }

    // 추가 내용 : 큐의 순회
//    while (!q.empty()) { //큐가 비어있지 않을 동안 
//        cout << q.front() << ' '; //front에서 원소를 가져오고 
//        q.pop(); //다음 원소를 출력하기 위해 앞의 원소 삭제 
//    }

    return 0;
}

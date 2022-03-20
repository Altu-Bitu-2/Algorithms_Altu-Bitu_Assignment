//
// Created by BaeSuA on 2022-03-11.
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다.  
//

// 직접 queue를 구현하는 문제! 가볍게 읽자 

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e4 + 1; //큐는 0번을 비우고 1번 인덱스부터 값이 들어감

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0; //0번 위치가 비어있으므로 시작은 둘다 0 

//큐가 꽉 찼는지 검사 -> 직접 구현 시, 런타임에러 방지
bool full() {
    return (rear_pointer + 1) % SIZE == front_pointer;
}

//push: 삽입
void push(int x) {
    rear_pointer = (rear_pointer + 1) % SIZE; //원형 큐이기 때문에 SIZE보다 커지지 않도록 % 연산 
    queue_vec[rear_pointer] = x;
}

//pop: 왼쪽 값 삭제
void pop() {
    front_pointer = (front_pointer + 1) % SIZE; //마찬가지로 % 연산 
}

//size: 큐 사이즈
int size() {
    int tmp = rear_pointer - front_pointer;
    // 원형 큐이기 때문에 항상 rear > front 라는 보장이 없음! 
    if (tmp < 0) { // rear < front일 경우 조건문 걸어주기 
        tmp += SIZE; //SIZE를 더해주어서 양수로 만들어줌 
    }
    return tmp;
}

//empty: 비어있는지 확인
bool empty() {
    return rear_pointer == front_pointer;
}

//front: 앞 원소 반환
int front() {
    return queue_vec[(front_pointer + 1) % SIZE];  
}

//back: 뒤 원소 반환
int back() {
    return queue_vec[rear_pointer];
}

int main() {
    int n, x;
    string cmd; //명령 
    queue<int> q;

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            if (!full()) { //라이브러리 사용 시 필요 x
            	push(x);
            }
            continue;
        }
        if (cmd == "pop") {
            if (empty()) { //큐가 비어있다면
                cout << "-1\n";
            } else {
                cout << front() << '\n';
                pop(); //앞에 원소 삭제
            }
            continue;
        }
        if (cmd == "size") {
            cout << size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << empty() << '\n';
            continue;
        }
        if (cmd == "front") {
            if (empty()) {
                cout << "-1\n";
            } else {
                cout << front() << '\n';
            }
            continue;
        }
        if (cmd == "back") {
            if (empty()) {
                cout << "-1\n";
            } else {
                cout << back() << '\n';
            }
        }
    }

    return 0;
}

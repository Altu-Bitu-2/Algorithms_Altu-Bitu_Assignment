//
// Created by BaeSuA on 2022-03-11.
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

//직접 stack을  구현하는  문제! 가볍게 읽자 

#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4; //스택 사이즈

vector<int> stack_vec(SIZE);
int top_pointer = -1; //스택의 현재 위치 가리키는 포인터

//full: 스택이 꽉 찼는지 확인 (직접 구현 시, 런타임 에러 방지용)
bool full() {
    return top_pointer == (SIZE - 1);
}

//push: 삽입
void push(int x) {
    stack_vec[++top_pointer] = x;
}

//pop: 가장 위의 값 삭제
void pop() {
    top_pointer--;
}

//size: 스택 사이즈 반환
int size() {
    return top_pointer + 1;
}

//empty: 비어있으면 1, 아니면 0
bool empty() {
    return top_pointer == -1;
}

//top: 가장 위에 있는 원소 반환 (삭제 x)
int top() {
    return stack_vec[top_pointer]; //top을 "인덱스"라고 생각하면 편하다. 
}

int main() {
    int n, x;
    string cmd; //명령

    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //런타임 에러 방지하기 위해, 스택이 꽉 찼는지 검사
            if (!full()) { //라이브러리 사용시엔 필요 x
            	push(x);
            }
            continue;
        }
        if (cmd == "pop") {
            if (empty()) { //스택이 비어있다면
                cout << "-1\n";
            } else {
                cout << top() << '\n';
                pop();
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
        if (cmd == "top") {
            if (empty()) {
                cout << "-1\n";
            } else {
                cout << top() << '\n';
            }
        }
    }

    return 0;
}

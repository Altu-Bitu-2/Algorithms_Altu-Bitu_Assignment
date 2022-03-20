//
// Created by BaeSuA on 2022-03-11.
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

//STL stack 이용해서 문제 풀기 
// + 추가내용 : 스택의 순회 

#include <iostream>
#include <vector>
#include <stack> //헤더 선언해주기  

using namespace std;
const int SIZE = 1e4; //스택 사이즈

vector<int> stack_vec(SIZE);
int top_pointer = -1; //스택의 현재 위치 가리키는 포인터

//STL stack 자체에 v1에서 작성했던 함수들이 정의되어 있기 때문에 작성할 필요X 

int main() {
    int n, x;
    string cmd; //명령
	stack<int> st; //스택 선언 
	
    //입력
    cin >> n;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> x;
            //런타임 에러 방지하기 위해, 스택이 꽉 찼는지 검사
            //if (!full()) { //라이브러리 사용시엔 필요 x
            st.push(x);
            //}
            continue;
        }
        if (cmd == "pop") {
            if (st.empty()) { //스택이 비어있다면
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
                st.pop();
            }
            continue;
        }
        if (cmd == "size") {
            cout << st.size() << '\n';
            continue;
        }
        if (cmd == "empty") {
            cout << st.empty() << '\n';
            continue;
        }
        if (cmd == "top") {
            if (st.empty()) {
                cout << "-1\n";
            } else {
                cout << st.top() << '\n';
            }
        }
    }

    // 추가 내용 : 스택의 순회
//    while (!st.empty()) { //스택이 비어있지 않을 동안 
//        cout << st.top() << ' '; //top에서 원소를 꺼내오고 
//        st.pop(); // 다음 원소를 출력하기 위해 pop 해주기 
//    }
    return 0;
}

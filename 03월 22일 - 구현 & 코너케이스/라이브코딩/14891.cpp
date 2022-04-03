//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
// 

#include <iostream>
#include <deque>
#include <vector>
#include <cmath>

/*
 * 톱니바퀴 문제
 *
 * 문제에 나와있는대로 구현
 * -> 맞닿은 극이 "다를 경우" 우선 해당 톱니 회전 후, 맞닿은 톱니 반대 방향으로 회전
 * -> 이때 맞닿은 극을 확인하는 경우는 회전 후가 아닌 회전 전!!
 *
 * 톱니바퀴의 상태를 저장할 컨테이너 -> 덱
 *
 * 1. 각 톱니바퀴가 회전할 방향을 결정
 *      - 방향을 저장하는 벡터
 * 2. 결정된 방향으로 회전!
 * */

using namespace std;

const int R = 2;    // 맞닿는 오른쪽 톱니 인덱스
const int L = 6;    // 맞닿는 왼쪽 톱니 인덱스

deque<int> wheel[5];    // 톱니바퀴의 상태를 저장 - deque 5개 선언 (index 1~4까지 사용)
vector<int> rotation(5, 0); // 방향 저장 1: 시계, -1: 반시계, 0: 회전 없음

void decideRotation(int num, int rot) {
    // 재귀함수의 탈출 조건 : 이미 회전한 경우
    if (rotation[num] != 0) { // 이미 1이나 -1로 회전 정보가 있다면 
        return;
    }
    // num 톱니바퀴를 rot 방향으로 회전
    rotation[num] = rot;

    // 오른쪽 바퀴가 회전하는 경우
    if (num < 4 && wheel[num][R] != wheel[num + 1][L]) { // 극이 다르면
	// 주의! && 앞뒤를 바꾸면 num < 4 를 확인하지 않아 에러가 날 수 있음 
        decideRotation(num + 1, -rot); // 오른쪽 바퀴를 현재바퀴의 반대방향으로 회전 
    }
    // 왼쪽 바퀴가 회전하는 경우
    if (num > 1 && wheel[num][L] != wheel[num-1][R]){ // 극이 다르면 
        decideRotation(num-1, -rot); // 왼쪽 바퀴를 현재바퀴의 반대방향으로 회전 
    }
}

void rotate(){
    // rotation의 회전정보를 확인하고 톱니바퀴를 회전시킴
    for (int i=1; i<=4; i++){ // 모든 톱니바퀴에 대해서 회전 
      
        if (rotation[i] == 1) { // 시계방향으로 회전하는 경우 : ex) 10101111 -> 11010111
            int temp = wheel[i].back(); // 뒤에 있는 값 미리 저장 
            wheel[i].pop_back(); // 뒤에 있는 값 pop 
            wheel[i].push_front(temp); // 앞에 temp값 넣기 
        } else if (rotation[i] == -1) { // 반시계 방향으로 회전하는 경우
            int temp = wheel[i].front(); // 앞에 있는 값 미리 저장  
            wheel[i].pop_front(); // 앞에 있는 값 pop 
            wheel[i].push_back(temp); // 뒤에 temp값 넣기 
        }
    }
    return;
}

int calcScore(){
    int answer = 0;
    for (int i=1; i<=4; i++) { // 톱니바퀴 1~4번 
        answer += pow(2, i-1) * wheel[i][0]; // N극은 0이므로 곱하면 answer에 영향X 
    }
    return answer;
}

int main() {
    string temp;
    for (int i = 1; i <= 4; i++) { // 톱니바퀴 4개 
        cin >> temp;
        // 톱니바퀴 상태를 저장
        for (int j = 0; j < 8; j++) { // 톱니는 각각 8개 
            wheel[i].push_back(temp[j] - '0'); // 문자형을 정수형으로 바꿔서 넣기  
        }
    }

    int n, num, rot;
    cin >> n; // 회전 수 

    while (n--) {
        cin >> num >> rot; // 몇번 톱니바퀴를 어떤 방향으로 돌릴지 
        // rotation이 전역변수이기 때문에 회전 정보를 초기화
        rotation.assign(5, 0); 
        // 회전 방향 결정
        decideRotation(num, rot);
        // 회전하기
        rotate();
    }

    // 점수 계산하기 + 출력
    cout << calcScore();
    return 0;
}

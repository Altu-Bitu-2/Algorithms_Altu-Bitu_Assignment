#include <iostream>
#include <queue>

using namespace std;

/**
 * [크리스마스 선물] - 단순 구현 문제
 *
 * - 0이 나올 때마다, 가지고 있는 선물 중 가장 가치가 큰 것을 삭제 & 출력 -> 최대 힙 필요
 */

int main() {
    int n, a, input;
    priority_queue<int> pq; //최대 힙

    //입력
    cin >> n; // 아이들과 거점지를 방문한 횟수 
    while (n--) {
        cin >> a; // a개의 선물 충전 
        if (!a) { //아이들을 만난 경우
            if (pq.empty()) { // 줄 선물이 없을 경우 
                cout << "-1\n"; // -1 출력 
            } else { // 줄 선물이 있다면  
                cout << pq.top() << '\n'; // 선물 가치 출력 
                pq.pop(); // 준 선물 없애기 
            }
        } else { //선물을 충전하는 경우
            while (a--) {
                cin >> input; // 선물 가치 입력 
                pq.push(input); // 선물(가치) 넣어주기
            }
        }
    }
    return 0;
}

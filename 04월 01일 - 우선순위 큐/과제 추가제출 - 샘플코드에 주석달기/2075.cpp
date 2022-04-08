#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/**
 * [N번째 큰 수]
 *
 * 메모리 제한이 있으므로, 입력값을 모두 저장하면 안된다.
 * 상위 n개만 저장하는 "최소" 힙을 만들어서 heap[0]을 현재까지의 N번째 큰수로 유지하는 풀이
 */

int main() {
	// 입출력 속도 향상 코드 
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input; 
    priority_queue<int, vector<int>, greater<>> pq; //최소 힙, 정렬이랑 반대

    cin >> n; // 표 길이 
    int size = n * n; // 표 사이즈 
    while (size--) {
        //입력
        cin >> input; // 표에 들어갈 수 

        //연산
        pq.push(input); // 표에 값 넣어주기 
        if (pq.size() > n) { //최소 힙의 크기가 n 이상이라면 가장 작은 값 삭제
            pq.pop(); // 삭제 
        }
    }

    //출력
    cout << pq.top(); // 제일 위가 N번째 큰수 
    return 0;
}

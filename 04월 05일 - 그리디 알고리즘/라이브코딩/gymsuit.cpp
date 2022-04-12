#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
1. 각 학생의 체육복의 수를 계산
2. 왼쪽 학생부터 양 옆의 학생에게 체육복을 빌릴 수 있는지 확인
왼쪽과 오른쪽 학생 모두에게서 빌릴 수 있다면, 왼쪽 학생을 선택(그리디) 
3. 마지막으로 체육복이 1개 이상인 학생 수를 카운트
*/

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> clothes(n+2, 1); // 인덱스 0번은 비움. 인덱스 에러가 나지 않도록 예외처리
     
	// 체육복을 잃어버린 학생
	for (auto i: lost){ // lost의 인덱스는 중요하지 않기 때문에 이렇게 작성.   
        clothes[i]--; // lost에 들어있는 값에 대해서만, 즉 잃어버린 학생에 대해서만 옷 개수 줄여주기 
    }
    for (auto i: reserve){  // 여분 옷을 가져온 학생
        clothes[i]++; // 옷 개수 늘려주기 
    }
	
	// 체육복 없는 학생 빌리기 
    for (int i=1; i<=n; i++){ 
        if (clothes[i]) {   // 체육복 있으면
            continue;
        }
        if (clothes[i-1] == 2) {    // 왼쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i-1]--; // 왼쪽 학생 옷 줄이기  
            clothes[i]++; // 없는 학생 체육복 생김 
        } else if(clothes[i+1] ==2) {   // 오른쪽 학생에게 체육복 빌릴 수 있으면
            clothes[i+1]--; // 오른쪽 학생 옷 줄이기 
            clothes[i]++; // 없는 학생 체육복 생김 
        }
    }
	
	// 옷이 있는 학생 count 
    for (int i=1; i<=n; i++){
        if (clothes[i]) {
            answer++;
        }
    }
    return answer;
}

//프로그래머스 예제 테스트할 수 있는 메인함수

int main() {
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};
    int n = 5;

    cout << solution(n, lost, reserve);
    return 0;
}

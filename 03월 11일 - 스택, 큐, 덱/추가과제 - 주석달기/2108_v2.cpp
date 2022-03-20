#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //양수의 최댓값

int findMode(vector<int> &frequency) {
    int max_value = 0;  
    for (int i = 0; i <= SIZE * 2; i++) { //빈도수가 가장 높은 입력 수 찾기 
        if (frequency[i] > max_value)
            max_value = frequency[i];
    }
    //최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= SIZE * 2; i++) {
        if (frequency[i] == max_value) { //최빈값이 여러개라면 
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++;
            if (cnt == 2) //두 번째로 작은 최빈값 
                break;
        }
    }

    return mode;
}

/**
 * [통계학]
 * 1. 산술 평균 계산 시 실수 자료형 사용, 반올림에 주의
 * 2. n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값
 * 4. 최빈값이 유일한 경우 고려
 */

int main() {
    int n; //n은 홀수

    //입력
    cin >> n; //수의 개수 입력받기 

    vector<int> num(n); //int형 vector 생성 
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장

    int sum = 0; //평균 구하기 위한 합 변수
    //합 구하기  
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
        //빈도수 업데이트 
        frequency[num[i] + SIZE]++; // 입력 수 + SIZE(4000)을 해주어서 해당 수의 빈도수를 업데이트 해준다. 
    }

    //연산이 쉬워지도록 오름차순으로 정렬 
    sort(num.begin(), num.end());

    //출력 
    //산술평균
    if (round((double)sum / n) == -0) //-0이 나오면 0으로 취급하라는 문제의 조건 
        cout << "0\n"; 
    else
        cout << round((double)sum / n) << '\n'; //평균 구한 후 반올림하여 출력 
     //중앙값
	cout << num[n / 2] << '\n'; //n은 홀수 이므로 중앙값은 항상 (n/2)번째 인덱스
    //최빈값 
	cout << findMode(frequency) << '\n'; // findMode 함수. 인자는 입력 수의 빈도수를 담고 있는 배열인 frequency 
	//범위 
    cout << num[n - 1] - num[0] << '\n'; //오름차순 정렬이므로 맨 뒤에서 맨 앞 값을 빼주면 됨 

    return 0;
}

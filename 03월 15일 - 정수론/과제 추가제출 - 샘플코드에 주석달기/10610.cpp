#include <iostream>
#include <algorithm>

using namespace std;

string findNumber(string s) {
    bool isTen = false; //0이 존재하는지 확인
    int sum = 0; //3의 배수인지 확인하기 위해 수 더함

    //돌면서 3의 배수와 10의 배수인지 확인
    for (int i = 0; i < s.length(); i++) {
        //1. 3의 배수 조건 확인 : 각 자리 숫자의 총합이 3의 배수이면 됨
        sum += (s[i] - '0'); //문자를 정수형으로 바꿔주면서 각 자릿수의 합 구하기

        //2. 10의 배수 조건 확인 : 숫자의 맨 끝자리가 무조건 0
        if (s[i] == '0') { //0이 적어도 1개는 존재하는지 확인 
            isTen = true; //만족하면 flag 업데이트
        }
    }

    if (sum % 3 != 0 || !isTen) { //3의 배수가 아니거나, 10의 배수가 아니라면
        return "-1"; //여기서는 s가 문자열이기 때문에 문자 -1 return
    }

    //가장 큰 수 만들기 위해 내림차순 정렬
    sort(s.begin(), s.end(), greater<>());
    return s;
}

/**
 * [30]
 * 30의 배수 = 10의 배수 && 3의 배수
 * 1. 10의 배수 -> 입력된 수에 0이 포함되어 있는지 확인
 * 2. 3의 배수 -> 모든 자리수의 합이 3의 배수인지 확인
 *
 * 30의 배수임이 확인 되었으면,
 * 가장 큰 수를 만들기 위해 9부터 0까지 역순으로 나열한다.
 */

int main() {
    string s;

    //입력
    cin >> s;

    //연산 & 출력
    cout << findNumber(s);
    return 0;
}
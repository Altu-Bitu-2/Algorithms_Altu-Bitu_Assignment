//
// Created by ZERO-black 
// 튜터분이 작성하신 라이브 코드를 일부 수정했습니다. 
//

// version 1. 두 수 중 작은 수 기준으로 돌리면서 최대공약수 구하기 (비추천)

#include <iostream>

using namespace std;

// 최대공약수를 구하는 함수
int gcdBad(int a, int b) {
    // a, b중 더 작은 수를 기준으로 반복문을 돌려서 최대공약수 리턴
    for (int i = min(a, b); i > 0; i--) { // i=1부터 하지 않고 min(a,b)부터 해야 '최대'공약수 
        // 공약수인지 확인
        if (a % i == 0 && b % i == 0) {  
            return i; 
        }
    }
    return 1; // 이 코드를 작성하지 않으면, if문에 안 들어갔을 때 gcdBad가 어떤 값을 return할지 몰라서 에러가 남 
}

int main() {
    // 입력
    int a, b;
    cin >> a >> b;
    
    //최대공약수
	int g = gcdBad(a, b);
	
    // 최소공배수
    int l = a * b / g; // [두수의 곱 = 최대공약수 * 최소공배수] 식을 이용 

    // 출력
    cout << g << '\n' << l << '\n';
    
    return 0;
}

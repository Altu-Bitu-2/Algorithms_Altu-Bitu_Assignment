#include <iostream>

using namespace std;

// 총 타일의 개수(R+B)의 약수 쌍 구하기
int findDivisor(int r, int b){
	int sum = r+b;
	
	// 약수 쌍 구하기  
	for (int i=3; i<=sum/2; i++) { // 타일의 행이 3보다 작으면 B가 존재할 수 X. 따라서 i=3부터, 중복을 피하기 위해 sum/2 까지 
		
	}
} 
 
int main() {
	// 입력
	int r,b; 
	cin >> r >> b;
	
	int divisor = findDivisor(r,b);
	
	return 0;
} 

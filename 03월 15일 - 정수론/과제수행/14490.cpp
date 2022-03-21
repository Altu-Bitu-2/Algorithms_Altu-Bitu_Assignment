#include <iostream>

using namespace std;

const int LENGTH = 18; //:를 뺀 a와 b의 총 길이. a, b 각각 9자리가 최대이므로 최대 18자리 
 
int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}

int main(){
	//입력
	string s;
	cin >> s; //문자열로 입력받기 
	
	// : 건너 뛰고 a, b 저장하기 
	int a, b; //형 변환한 a, b를 저장할 변수
	int cnt=0; //이후에 a, b를 나누기 위해 a의 길이를 세주는 변수
	int a_length=0; //cnt를 통해 구한 a의 최종 길이 
	string only_num(LENGTH,'0'); // :를 빼서 숫자만 저장해줄 문자열 
	int index = 0; //only_num의 현재 index를 저장할 변수 
	for (int i=0;i<s.length();i++){
		if (s[i] != ':'){ // :가 아니라 숫자가 들어오면  
			only_num[index++] = s[i]; //숫자 하나 넣ㅇ준 후 index +1 업데이트 
/*			only_num[index] = s[i];
			cout << only_num[index];
			index++;
			cnt++; //a 길이 +1 업데이트 
		} 디버깅용 */  
		else { //a의 길이를 세다가 :를 만났을 경우가 최종 a의 길이 
			a_length = cnt;
		}
	
	} 
	
	//a, b 나누고 정수로 형 변환  
	
	//최대공약수 찾아서 나눠주기 

	return 0;
}


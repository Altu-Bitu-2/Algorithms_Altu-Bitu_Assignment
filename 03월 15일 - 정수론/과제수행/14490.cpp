#include <iostream>

using namespace std;

const int LENGTH = 18; //:를 뺀 a와 b의 총 길이. a, b 각각 9자리가 최대이므로 최대 18자리 

//GCD 재귀함수 : 최대공약수를 return 
int gcdRecursion(int a, int b) {
	if (b == 0) return a;
	return gcdRecursion(b, a % b);
}

//a, b를 구분해서 형 변환해주는 함수 
int divideAndStoi(string& only_num, int only_num_length, int& a_length, int& b_length) {
	string string_a(a_length, '0'), string_b(b_length, '0'); // a, b를 나눠서 각각 저장 

	//a, b 나누기 
	for (int i = 0; i < a_length; i++) { //a만 저장 
		string_a[i] = only_num[i];
		cout << string_a[i];
	}
	cout << "\n";
	for (int i = a_length; i < only_num_length; i++) { //b만 저장 
		int temp = 0; //string_b의 현재 인덱스를 저장할 변수 
		string_b[temp] = only_num[i];
		cout << string_b[temp]; //!b를 하나하나 출력해보자 
		temp++;	//string_b의 인덱스 +1 업데이트 
	}
	cout << "\n";

	//string_a, string_b를 각각 정수로 형 변환 해주기 
	cout << "b의 길이는 " << b_length << "\n"; //!string에서는 분명 b의 길이가 정상출력됨 
	int a = stoi(string_a);
	cout << "stoi한  a는 " << a << "\n"; //!a는 stoi가 정상적으로 됨 
	int b = stoi(string_b);
	cout << "stoi한 b는 " << b; //!하지만 b가 이상하게 나옴.. 

	return gcdRecursion(a, b); //!a, b의 최대공약수를 return해준다 
}

int main() {
	//입력
	string s;
	cin >> s; //문자열로 입력받기 

	// : 건너 뛰고 a, b 저장하기 
	int cnt = 0; //이후에 a, b를 나누기 위해 a의 길이를 세주는 변수 
	int a_length = 0; //cnt를 통해 구한 a의 최종 길이 
	string only_num(LENGTH, '0'); // :를 빼서 숫자만 저장해줄 문자열 
	int index = 0; //only_num의 현재 index를 저장할 변수 
	for (int i = 0; i < s.length(); i++) {
		if (s[i] != ':') { // :가 아니라 숫자가 들어오면  
			only_num[index++] = s[i]; //숫자 하나 넣어준 후 index +1 업데이트 
			cnt++; //a의 길이를 세주기 위해 cnt +1 업데이트. 
/*
			only_num[index] = s[i];
			cout << only_num[index];
			index++;
			cnt++;  */ // 디버깅용 
		}
		else { //a의 길이를 세다가 :를 만났을 경우가 최종 a의 길이 
			a_length = cnt;
		}
	}

	//b의 길이 구하기
	int b_length = cnt - a_length; //cnt는 반복문을 모두 돌면 a의 길이 + b의 길이가 되므로 cnt에서 a의 길이만큼을 빼줌 
	//실제 a와 b의 길이의 합으로 업데이트 해주기
	int only_num_length = a_length + b_length;

	int gcd = divideAndStoi(only_num, only_num_length, a_length, b_length);
	//cout << a << ':' << b;

	return 0;
}

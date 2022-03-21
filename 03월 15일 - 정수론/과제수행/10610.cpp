#include <iostream>
#include <vector>

using namespace std;

//내림차순 cmp 함수 
bool cmp(string s1, string s2){
	return s1 > s2;	//string 사전 역순 
}

//30의 배수인 경우 가장 큰 30의 배수를 찾아서 return하는 함수 
int findGreat30(string n,vector<int> &v) { //각 자릿수에 접근해야 하므로 n을 인자로 받기 
	int great_num; 
	vector<int> temp;
	
	//맨 마지막 숫자는 제외하고 내림차순 정렬 
	//맨 끝자리는 무조건 0 

	return great_num; 
}

//30의 배수인지 확인해주는 함수 
int is30(string n, vector<int> &v){
	//30의 배수X -> return -1
	int sum=0;
	for (int i=0;i<v.size();i++){
		//1. 각 자릿수의 합이 3의 배수가 아닌 경우(3의 배수 조건) 
		sum += v[i]; //각 자릿수의 합
		if (sum % 3 != 0) return -1; //합이 3의 배수가 아닐 경우
		//2. 각 자릿수의 숫자들 중 적어도 1개가 0이면(10의 배수 조건) 30의 배수 존재 
		if (v[i]==0) return findGreat30(n,v); //만들 수 있는 가장 큰 30의 배수 return 
	}
	return -1; //0이 하나도 없으면 반복문 빠져나와서 return -1
}

int main(){
	string n; //각 자릿수를 나누기 위해 문자열로 받기 
	cin >> n; 
	
	vector<int> v; //문자열을 각 자릿수로 나누고 정수형으로 변환하여 저장할 vector
	for (int i=0;i<n.length();i++){
		int temp = n[i] - '0'; //각 자릿수로 나누고 정수형으로 형 변환 
		v.push_back(temp); 	// v에 각자리수 저장
		
	} 
	
	//출력 
	cout << is30(n,v); 
	 
} 	       

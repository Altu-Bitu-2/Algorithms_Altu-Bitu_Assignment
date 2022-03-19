#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

const int SIZE = 26;    // 알파벳의 수

vector<int> countAlphabet(string text) {
    // text에 있는 각 알파벳의 개수를 세어 리턴하는 함수
    vector<int> count(SIZE, 0); // A-Z까지 문자의 개수를 저장할 리스트. 인덱스 0은  A 개수, 인덱스 1은  B 개수... 저장 
    for (int i = 0; i < text.size(); i++) {
        // 각 문자를 인덱스로 바꿔주기 위해 'A'의 인덱스를 빼줌. 사전순이 우선이므로 A부터 순서대로 저장 
        count[text[i] - 'A']++; //해당 알파벳 개수 늘려주기 
    }
    return count;
}

string makePalindrome(vector<int> &count) {
    // 팰린드롬을 만들어 리턴하는 함수.
    string part1 = "", part2 = "", part3 = "";

    for (int i = 0; i < SIZE; i++) {  
        // 만약 알파벳의 수가 홀수라면 
        if (count[i] % 2 == 1) { 
            // 이미 가운데 글자가 찼다면 더 이상 불가능
            if (part2.size() == 1) {
                return "I'm Sorry Hansoo";
            }
            // 가운데 글자가 비어있다면 part2 할당
            part2 = (char) (i + 'A'); //int형으로 저장되어 있으므로 char로 형 변환 
        }
        // 남은 수의 절반을 나누어 part1과 part3에 이어 붙인다 or 알파벳 수가 처음부터 짝수인 경우 
        for (int j = 0; j < count[i] / 2; j++) { 
            part1 += (char) (i + 'A');  
            part3 = (char) (i + 'A') + part3;
        }
    }

    return part1 + part2 + part3;
}

/*
 * [팰린드롬 만들기] - 단순 구현 문제
 * 팰린드롬 문자열은 part1(part3의 대칭) + part2(최대 1글자) + part3(part1의 대칭)으로 이루어진다.
 * 1. 팰린드롬 문자열을 만들기 위해, 각 알파벳이 몇 개씩 존재하는지 벡터에 저장한다.
 * 2. 사전순으로 앞선 팰린드롬 수를 만들어야 하므로, 'A'부터 시작해서 part1과 part3를 문자의 개수에 맞춰 더해나간다.
 * 3. 만약 알파벳의 개수가 홀수인 경우, part2에 할당하고, 이미 part2에 문자가 있는 경우엔 팰린드롬을 만들 수 없다.
 */


int main() {
    // 입력
    string input; 
    cin >> input; //영어이름 입력받기 

    // 연산 + 출력
    vector<int> count = countAlphabet(input); 
    cout << makePalindrome(count); 

    return 0;
}

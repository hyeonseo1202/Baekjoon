//4659
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
#define SIZE 20;
bool gather(string str) {// 모음을 포함하고 있는지 확인
	if (str.find('a') != string::npos ||
		str.find('i') != string::npos ||
		str.find('e') != string::npos ||
		str.find('o') != string::npos ||
		str.find('u') != string::npos) {
		return true;
	}
	else { return false; }
}
bool three(string str) {//모음 또는 자음이 연속으로 3개 오는지 확인
	int NUM = str.length();
	int arr[20];
	for (int n = 0; n < NUM; n++)
	{
		if (str[n] == 'a' ||
			str[n] == 'i' ||
			str[n] == 'e' ||
			str[n] == 'o' ||
			str[n] == 'u')
		{
			arr[n] = 1;
		}
		else {
			arr[n] = 2;
		}
		//cout << arr[n];
	}
	for (int n = 0; n < NUM; n++)
	{
		if (arr[n] == arr[n + 1]&& arr[n + 1] == arr[n + 2])
		{
			//cout << 3;
			return false;
		}
	}
	return true;
}
bool same(string str) { //'ee','oo'제외 같은 문자 2개 연속으로 오는지 확인
	int NUM = str.length();
	for (int i = 0; i < NUM - 1; i++) {
		if (str[i] == str[i + 1]) {
			if (str[i] == 'e' || str[i] == 'o'){}
			
			else { //cout << 1;
				return false; }
		}
	}
	return true;
}

int main()
{
	string str;
	int n = 0;
	do {
		cin >> str;
		if (str == "end") { break; }
		if (gather(str) && three(str) && same(str)) {//전부 다 트루이면 accept
			cout << "<" << str << ">" << " is acceptable." << endl;
		}
		else {
			cout << "<" << str << ">" << " is not acceptable." << endl;
		}
	} while (1);//문자열 입력받기
	return 0;
}

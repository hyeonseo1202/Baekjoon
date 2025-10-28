#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;
    int column = 1;

    //x가 위치한 열 찾기
    //이 for문이 끝나면, x변수는 행을 가리킴
    for(; x - column > 0;column++){
        x -= column;
    }

    //열이 홀수일 때
    if(column % 2){
        cout << column+1-x << '/'<< x;
    }
    else{ //열이 짝수일 때
        cout << x << '/' << column+1-x;
    }



}
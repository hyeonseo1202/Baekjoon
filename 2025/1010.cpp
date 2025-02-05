//조합 - 주어진 집합의 원소들 가운데 몇 개를 순서에 상관없이 선택하는 모든 경우의 수
//조합을 수학적으로 표현할 땐 "이항계수"라는 표현을 사용한다.

#include<iostream>
using namespace std;

int main(){
    int T,N,M;
    cin>>T;
    while(T--){
        cin>>N>>M;
        long result = 1;
        for(int i = M,j=1; i > M-N;i--,j++){
            result = result * i;
            result = result / j;
        }
        cout<<result<<endl;

    }
    return 0;
}
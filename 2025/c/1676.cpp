#include<iostream>
using namespace std;
//팩토리얼과 0의 개수를 직접 세는 것은 비효율
// 0은 10의 배수가 얼마나 많은지를 나타내므로, 2와 5의 쌍의 개수를 찾으면 됨.
//모든 경우에서 5의 개수가 2보다 적으므로 5의 개수만 세어주면 됨.
// 5의 배수의 개수, 25의 배수의 개수, 125의 배수의 개수 ... 등을 모두 합쳐주면 된다.
int countZeros(int N){
    int count = 0;
    for(int i = 5; N/i >= 1; i*=5){
        count += N / i;
    }
    return count;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;

    cout<<countZeros(N)<<endl;

    return 0;
}
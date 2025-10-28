#include<iostream>
#include<vector>

using namespace std;

void sieve(int M, int N) {
    vector<bool> isPrime(N+1, true);
    isPrime[0] = isPrime[1] = false;

    //에라토스테네스의 체 알고리즘
    for(int i = 2; i*i <=N; i++){
        if(isPrime[i]){
            for(int j = i * i; j<= N; j+=i){
                isPrime[j] = false;
            }
        }
    }

    //결과 출력
    for(int i = M; i<=N; i++){
        if(isPrime[i]){
            cout<<i<<'\n';
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int M, N;
    cin >> M >> N;
    sieve(M, N);

    return 0;
}

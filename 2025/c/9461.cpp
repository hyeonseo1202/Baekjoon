#include <iostream>
using namespace std;
//수열을 한 번만 계산하도록 코드를 작성해야 함.
//피보나치 수열은 수가 급격하게 증가하므로  long long형으로 해줘야 함.
long long Parray[101] = {0,1,1,};
long long P(int N)
{
    if(N < 3)
        return Parray[N];
    else if(Parray[N] == 0)
        Parray[N] = P(N-2) + P(N-3);
    return Parray[N];
}
int main() {
    int T;
    int N;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> N;
        cout << P(N) << '\n';
    }
}
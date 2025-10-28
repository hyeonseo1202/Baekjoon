#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num = 0;
    cin>>num;

    vector<int> A(num);
    vector<int> B(num);

    for(int i = 0; i<num;i++){
        cin>>A[i];
    }
    for(int j = 0;j<num;j++){
        cin>>B[j];
    }
    sort(A.begin(),A.end());
    sort(B.rbegin(),B.rend());

    int result = 0;
    for(int k = 0; k<num;k++){
        result += A[k] * B[k];
    }

    cout<<result; 
    return 0;
}
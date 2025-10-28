#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N;
    vector<int> arr(N);
    map<int,int> frequency;
    for(int i = 0; i < N; i++){
        cin>>arr[i];
        frequency[arr[i]]++;
    }

    // 산술평균
    double sum = 0;
    for(auto num : arr){
        sum += num;
    }
    int arithmetic_mean = round(sum/N);


    // 정렬하여 중앙값과 범위 구하기
    sort(arr.begin(), arr.end());
    int median = arr[N/2];
    int range = arr.back() - arr.front();

    
    // 최빈값 구하기
    vector<pair<int, int>> freq;
    for (auto& p : frequency) {
        freq.push_back({p.second, p.first});  // 빈도, 값
    }
    sort(freq.begin(), freq.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) return a.second < b.second;  // 빈도수가 같으면 숫자가 작은 순
        return a.first > b.first;  // 빈도수가 높은 순
    });

    int mode = freq[0].second;
    // 최빈값이 여러 개 있는지 확인
    if (freq.size() > 1 && freq[0].first == freq[1].first) {
        mode = freq[1].second;  // 두 번째로 작은 최빈값
    }

    // 결과 출력
    cout << arithmetic_mean << '\n';
    cout << median << '\n';
    cout << mode << '\n';
    cout << range << '\n';

    return 0;


}
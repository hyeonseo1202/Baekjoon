#include <iostream>
using namespace std;

int main() {
    int num, lim, kim;
    cin >> num >> lim >> kim;

    int round = 0;  // 현재 라운드 번호

    while (lim != kim) {
        lim = (lim + 1) / 2;
        kim = (kim + 1) / 2;
        round++;
    }

    cout << round << endl;

    return 0;
}

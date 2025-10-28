#include <iostream>
#include <string>
using namespace std;
 
// stoi : string to integar
 
int main() {
    string input;
    cin >> input;
 
    int result = 0;
    string num;
    bool isMinus = false;
 
    for (int i = 0; i <= input.size(); i++) {
        
        if (input[i] == '-' || input[i] == '+' || i==input.size()) {
            if (isMinus) {
                result -= stoi(num);
                num = "";
            }
            else {
                result += stoi(num);
                num = "";
            }
        }
        else {
            num += input[i];
        }
 
        if (input[i] == '-') { // 한 번 -가 나오면 그 후론 전부 빼줘야 하므로!!
            isMinus = true;
        }    
    }
    
    cout << result;
}

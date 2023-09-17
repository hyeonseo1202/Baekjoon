#include<iostream>
using namespace std;

int Kx, Ky, Sx, Sy;

// 이동 방향에 따라 킹과 돌의 위치를 업데이트하는 함수
void move(string dir) {
    int dx = 0, dy = 0; // 이동량 초기화

    if (dir == "R") dx = 1;
    else if (dir == "L") dx = -1;
    else if (dir == "B") dy = -1;
    else if (dir == "T") dy = 1;
    else if (dir == "RT") { dx = 1; dy = 1; }
    else if (dir == "LT") { dx = -1; dy = 1; }
    else if (dir == "RB") { dx = 1; dy = -1; }
    else if (dir == "LB") { dx = -1; dy = -1; }

    int newKx = Kx + dx;
    int newKy = Ky + dy;

    if (newKx >= 1 && newKx <= 8 && newKy >= 1 && newKy <= 8) {
        if (newKx == Sx && newKy == Sy) { // 킹이 돌과 같은 위치로 이동할 경우
            int newSx = Sx + dx;
            int newSy = Sy + dy;
            if (newSx >= 1 && newSx <= 8 && newSy >= 1 && newSy <= 8) {
                Sx = newSx;
                Sy = newSy;
            }
            else {
                return;
            }
        }
        Kx = newKx;
        Ky = newKy;
    }
}

int main() {
    char Kx_char, Sx_char;
    cin >> Kx_char >> Ky >> Sx_char >> Sy;

    // 입력으로 받은 문자를 정수로 변환 (A -> 1, B -> 2, ..., H -> 8)
    Kx = Kx_char - 'A' + 1;
    Sx = Sx_char - 'A' + 1;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string dir;
        cin >> dir;
        move(dir);
    }

    // 최종 위치를 출력할 때 다시 문자로 변환하여 출력
    char Kx_result = Kx + 'A' - 1;
    char Sx_result = Sx + 'A' - 1;

    cout << Kx_result << Ky << endl;
    cout << Sx_result << Sy << endl;

    return 0;
}

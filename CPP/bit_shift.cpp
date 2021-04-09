#include <iostream>

using namespace std;

int main()
{
    // 상수: 변하지 않는 수. 값을 한번 지정해놓으면 바꿀 수 없다.
    // 상수는 선언과 동시에 값을 지정해두어야 한다.
    const int iAttack = 0x00000001; // 1.
    const int iArmor = 0x00000002; //  10.
    const int iHP = 0x00000004; // 100.
    const int iMP = 0x00000008; // 1000.
    const int iCritical = 0x00000010; // 10000.

    // 001 | 100 = 00101 | 10000 = 10101 << 버프를 추가할 때는 |를 쓴다.
    int iBuf = iAttack | iHP | iCritical;

    // 연산자 축약형 : 연산자를 줄여서 사용할 수 있다.
    // 10101 ^ 00100 = 10001
    iBuf ^= iHP;

    // 10001 ^ 00100 = 10101
    // 스위치처럼 끄고 켤 수 있다.
    iBuf ^= iHP;

    // 활성화를 확인 할 때는 &를 쓴다.
    // 10101 & 00001 = 1 != 0 따라서 iAttack이 활성화중이다.
    cout << "Attack : "<< (iBuf & iAttack) << endl;
    // 10101 & 00010 = 0
    cout << "Armor : "<< (iBuf & iArmor) << endl;
    // 10101 & 00100 = 1
    cout << "HP : "<< (iBuf & iHP) << endl;
    // 10101 & 01000 = 0
    cout << "MP : "<< (iBuf & iMP) << endl;
    // 10101 & 10000 = 1
    cout << "Critical : "<< (iBuf & iCritical) << endl;

    /*
    쉬프트 연산자: <<, >> 값 대 값을 연산하여 값으로 나오게 된다.
    이 연산자 또한 이진수 단위의 연산을 하게 된다.
    20 << 2 = 80 = 20 * 2^2
    20 << 3 = 160 = 20 * 2^3
    20 << 4 = 320 = 20 * 2^4
    20을 2진수로 변환한다.
    10100
        ^ <이쪽으로 2칸 가라.
    1010000 = 80
    10100000 = 160
    101000000 = 320
    연산이 빨라서 빠른 곱셈이라고도 부른다.

    20 >> 2 = 5 = 20 / 2^2
    20 >> 3 = 2 = 20 / 2^3
    10100 >> 이쪽으로 두칸
    101 = 5
    10 = 2
    빠른 나눗셈. 2의 제곱수로 나눌 경우 쉬프트 연산자가 훨씬 빠르다.
    */
    int iHigh = 187;
    int iLow = 13560;

    int iNumber = iHigh;

    // iNumber에 187 값이 들어갔다. <- 방향으로 16비트 이동시키면, 16비트의
    // 값이 들어간다.
    iNumber <<= 16;

    // 하위 16비트를 채운다.
    iNumber |= iLow;

    // High 값을 출력한다. (상위 16비트 값만 출력)
    cout << "High : " << (iNumber >> 16) << endl;
    // Low 값을 출력한다. (하위 16비트 값만 출력)
    cout << "Low : " << (iNumber & 0x0000ffff) << endl;

    // 증감연산자: ++, -- 가 있다. 1 증가, 1 감소이다.
    iNumber = 10;

    // 전치
    ++iNumber;

    // 후치
    iNumber++;

    // 전치는 출력 전에 활성화
    cout << ++iNumber << endl;
    // 후치는 출력 후에 활성화
    cout << iNumber++ << endl;
    cout << iNumber << endl;


    return 0;
}
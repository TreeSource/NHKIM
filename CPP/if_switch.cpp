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

    /*
    분기문에는 크게 2가지 종류가 있다. if문, switch문이 그것이다.
    if문 : 조건을 체크해주는 기능이다.
    형태: if(조건식) {} (코드블럭)
    if문은 조건식이 true가 될 경우 코드블록 안의 코드가 동작된다.
    false일 경우는 동작되지 않는다.
    */

    if (false)
    {
        cout << "if문 조건이 true입니다." << endl;
    }

    /*
    else : if문과 반드시 같이 사용되어야 한다.
    if문 조건이 false 일 경우, else 구문 안의 코드가 실행된다.
    */
    else 
    {
        cout << "if문 조건이 false입니다" <<endl;
    }

    // 001 | 100 = 00101 | 10000 = 10101 << 버프를 추가할 때는 |를 쓴다.
    int iBuf = iAttack | iHP | iCritical;

    if (iBuf & iAttack != 0)
    {
        cout << "Attack 버프가 있습니다" << endl;
    }
    if (iBuf & iArmor != 0)
    {
        cout << "Armor 버프가 있습니다" << endl;
    }
    if (iBuf & iHP != 0)
    {
        cout << "HP 버프가 있습니다" << endl;
    }
    if (iBuf & iMP != 0)
    {
        cout << "MP 버프가 있습니다" << endl;
    }
    if (iBuf & iCritical != 0)
    {
        cout << "Critical 버프가 있습니다" << endl;
    }

    /*
    else if : if문과 반드시 같이 사용이 되어야 한다.
    if문 아래 와야 하고, else 보다는 위에 있어야 한다.
    else if는 몇개든 사용이 가능하다.
    */
    int iNumber = 0;
    cout << "숫자를 입력하세요 : ";
    cin >> iNumber;

    if (10 <= iNumber && iNumber <=20)
    {
        cout << "10 ~ 20 사이의 숫자입니다." << endl;
    }
    else if (21 <= iNumber && iNumber <= 30)
    {
        cout << "21 ~ 30 사이의 숫자입니다." << endl;
    }
    else if (31 <= iNumber && iNumber <= 40)
    {
        cout << "31 ~ 40 사이의 숫자입니다." << endl;
    }
    else 
    {
        cout << "10~40 이외의 숫자입니다." << endl;
    }
    

    return 0;
}


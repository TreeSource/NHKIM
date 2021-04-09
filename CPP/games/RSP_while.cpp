#include <iostream>
#include <time.h>

using namespace std;

enum RSP
{
    RSP_R = 1,
    RSP_S = 2,
    RSP_P = 3,
    RSP_END = 4
};

int main()
{
    /*
    반복문: 특정 작업을 반복해서 수행해주는 기능이다.
    종류: for, while, do while 세 종류가 존재한다.
    while (조건식) {} 의 형태로 구성된다.
    while문은 조건식을 체크해서 true일 경우 코드블록 안의 코드가 동작되고
    다시 조건식을 체크한다. 조건식이 false가 되면 while문을 빠져나오게 된다.
    반복문 안에서 break를 만나게 되면 해당 반복문을 빠져나오게 된다.
    */
    int iNumber = 1;
    int iPlayer, iAI;

    // 화면을 깨끗이 지워준다
    system("clear");

    // 난수 테이블 생성
    srand((unsigned int) time(0));

    int pWintime = 0, aWintime = 0;

    while (true)
    {
        system("clear");
        cout << "Player의 이긴 횟수: " << pWintime << endl;
        cout << "AI의 이긴 횟수: " << aWintime << endl;
        cout << "1. 바위" << endl;
        cout << "2. 가위" << endl;
        cout << "3. 보" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요: ";
        cin >> iPlayer;
        if (iPlayer < RSP_R || iPlayer > RSP_END)
        {
            cout << "잘못된 값을 입력하였습니다." << endl;
            // 일시정지
            system ("pause");
            continue;
        }

        else if (iPlayer == RSP_END)
        {
            break;
        }

        // 봇이 선택을 한다.
        iAI = rand() % 3 + RSP_R;

        switch(iAI)
        {
            case RSP_R:
                cout << "AI: 바위" << endl;
                break;
            case RSP_S:
                cout << "AI: 가위" << endl;
                break;
            case RSP_P:
                cout << "AI: 보" << endl;
                break;
            default:
                break;
        }

        int iWin = iAI - iPlayer;
        switch (iWin)
        {
        case 1:
        case -2:
            cout << "Player의 승리!" << endl;
            ++pWintime;
            break;
        case -1:
        case 2:
            cout << "AI의 승리!" << endl;
            ++aWintime;
            break;
        case 0:
            cout << "비김!" << endl;
            break;
        default:
            break;
        }
        system("sleep .7");
    }
    return 0;
}
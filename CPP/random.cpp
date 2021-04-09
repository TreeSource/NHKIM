#include <iostream>
#include <time.h>

using namespace std;

int main ()
{
    // 난수 발생
    srand((unsigned int)time(0));
    
    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;
    cout << ((rand() % 100) + 100) << endl;

    //실수 난수
    cout << (rand () % 10000 / 100.f) << endl;

    int iUpgrade = 0;
    cout << "Upgrade 기본 수치를 입력하세요 : ";
    cin >> iUpgrade;

    // 강화 확률을 구한다.
    float fPercent = rand() % 10000 / 100.f;

    // 강화 확률: 업그레이드가 0 ~ 3: 100% 성공, 4 ~ 6: 40%, 7 ~ 9 : 10%
    // 10 ~ 13 : 1%, 14 ~ 15 : 0.1%
    if (iUpgrade <= 3)
    {
        cout << "강화 성공" << endl;
        ++iUpgrade;
    }
    else if (iUpgrade >= 4 && iUpgrade <= 6)
    {
        if (fPercent < 40.f)
        {
            cout << "강화 성공" << endl;
            ++iUpgrade;
        }
        else
        {
            cout << "강화 실패" << endl;
            --iUpgrade;
        }
    }
    else if (iUpgrade >= 4 && iUpgrade <= 6)
    {
        if (fPercent < 40.f)
        {
            cout << "강화 성공" << endl;
            ++iUpgrade;
        }
        else
        {
            cout << "강화 실패" << endl;
            --iUpgrade;
        }
    }
    else if (iUpgrade >= 7 && iUpgrade <= 9)
    {
        if (fPercent <= 10.f)
        {
            cout << "강화 성공" << endl;
            ++iUpgrade;
        }
        else
        {
            cout << "강화 실패" << endl;
            --iUpgrade;
        }
    }
    else if (iUpgrade >= 10 && iUpgrade <= 13)
    {
        if (fPercent <= 1.f)
        {
            cout << "강화 성공" << endl;
            ++iUpgrade;
        }
        else
        {
            cout << "강화 실패" << endl;
            --iUpgrade;
        }
    }
    else if (iUpgrade >= 14)
    {
        if (fPercent <= 0.1f)
        {
            cout << "강화 성공" << endl;
            ++iUpgrade;
        }
        else
        {
            cout << "강화 실패" << endl;
            --iUpgrade;
        }
    }

    return 0;
}
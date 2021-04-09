#include <iostream>
#include <stdlib.h>

using namespace std;

int main ()
{
    int cur;
    /*
    for 문: 반복문의 한 종류이다.
    형태: for(초기값; 조건식; 증감값) {} 의 형태로 구성이 된다.
    조건식이 true이면 코드블록의 코드가 동작된다.
    무한루프를 돌릴때는 for (;;) {} 을 해주면 무한으로 돌아가게 된다.
    for 문에서 초기값은 처음 for문에 진입할 때 조건식을 체크하고 조건식이
    true이면 코드블록의 코드가 동작된 뒤에 증감값을 처리한다. 그 후 다시
    조건을 체크하고 true면 동작되고 증감 -> 조건 -> 증감 순서로 처리가 된다.
    조건이 false이거나 break를 만나게 되면 for문이 종료된다.
    */

    // 초기값: i = 0 조건식: i < 10 증감값: ++i
    for(int i = 0; i < 10; ++i)
    {
        cout << "2 * " << i << " = " << 2 * i << endl;
    }

    cin >> cur;

    system ("clear");

    // 1 ~ 100 사이의 숫자 중 짝수만 출력하는 for 문을 작성해보자.
    for (int j = 2; j < 100; j += 2)
    {
        cout << j << endl;
    }
    
    cin >> cur;

    system ("clear");

    // 1~100 사이의 숫자 중 3과 7의 공배수만 출력하는 if문을 만들어 보자.
    for (int i = 1; i <= 100; ++i)
    {
        if (!(i % 3 | i % 7))
        {
            cout << i << endl;
        }
    }
    
    cin >> cur;

    system ("clear");

    // 중첩 for문: for문 안에 또다른 for 문이 존재하는 형태이다.
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            cout<< "i = " << i << " j = " << j << endl;
        }
    }

    cin >> cur;

    system ("clear");

    // 중첩 for문 응용: 2단부터 9단까지
    for (int i = 2; i < 10; ++i)
    {
        for (int j = 1; j < 10; ++j)
        {
            cout << i << " X " << j << " = " << i*j << endl;
        }
    }

    cin >> cur;

    system ("clear");

    // 별찍기
    int max = 8;
    for (int i = 1; i < max; i+=2)
    {
        int s = i;
        int b = (max - s) / 2;
        for (; b > 0; --b)
        {
            cout << " ";
        }
        for (; s > 0; --s)
        {
            cout << "*";
        }
        cout << endl;
    }
    
    cin >> cur;

    system ("clear");

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3 - i; ++j)
        {
            cout << " ";
        }
        for (int k = 0; k < k * 2 + 1; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }

    cin >> cur;

    system ("clear");

    int iLine = 7;
    int iCount = 0;
    for (int i = 0; i < iLine; ++i)
    {
        // 공백: 3,2,1,0,1,2,3
        // 별: 1,3,5,7,5,3,1
        iCount = i;

        if (i > iLine / 2)
        {
            // i값이 7 줄 기준 4,5,6 즉 밑의 삼각형을 구성할 때만.
            iCount = iLine - 1 -i;
        }
        for (int j = 0; j < iLine / 2 - iCount; ++j)
        {
            cout << " ";
        }

        for (int k = 0; k < iCount * 2 + 1; ++k)
        {
            cout << "*";
        }
        cout << endl;
    }

    
    return 0;
}
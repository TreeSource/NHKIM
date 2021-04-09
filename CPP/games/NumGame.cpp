#include <iostream>
#include <time.h>

// console input output 헤더 파일이다. 콘솔창에서 입출력 하는 기능들을
// 제공해주는 헤더 파일이다.
#include <conio.h>

using namespace std;

int main ()
{
    srand((unsigned int) time(0));
    int iNumber[25] = {};
    for (int i = 0; i < 24; ++i)
    {
        iNumber[i] = i+1;
    }

    // 가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한
    // 값을 사용할 건데 INT_MAX라는 값을 사용할 것이다. INT_MAX는 이미
    // 정의되어있는 값으로 int로 표현할 수 있는 최대값이다.
    // 여기선 INT32_MAX.
    iNumber[24] = INT32_MAX;

    // 마지막 공백을 제외하고 1~24 까지의 숫자만 섞어준다. 즉 인덱스는 0~23번
    // 인덱스 까지만 섞어준다.

    int iTemp, idx1, idx2;
    for (int i = 0; i < 100; ++i)
    {
        idx1 = rand() % 24;
        idx2 = rand() % 24;

        iTemp = iNumber[idx1];
        iNumber[idx1] = iNumber[idx2];
        iNumber[idx2] = iTemp;
    }

//    for (int i = 1; i <= 25; ++i)
//    {
//        cout << iNumber[i-1] << "\t";
//        if (!(i % 5))
//        {
//            cout << endl;
//        }
//    }

    while (true)
    {
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                // i가 0일때 j는 0~4까지 반복한다. 이 경우 0 * 5 + (0~4)를 더하기 돼서
                // 인덱스는 0, 1, 2, 3, 4가 나오게 된다.
                //...
                if (iNumber[i * 5 + j] == INT32_MAX)
                {
                    cout << "*\t";
                }
                else
                {
                    cout << iNumber[i*5 + j] << "\t";    
                }
            }
            cout << endl;
        }
        cout << "W: UP S: DOWN A: LEFT D: RIGHT Q: QUIT";
        char cInput;

    }
    
    return 0;
}
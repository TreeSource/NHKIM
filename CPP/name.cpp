/*
#include: 헤더 파일을 여기에 포함시키는 기능이다.
*/
#include <iostream>


/*
using: namespace의 이름을 붙이지 않아도 돌아가게 해준다.
*/
using namespace std;

/*
C++ 의 시작점은 main 함수이다. main 함수는 반드시 있어야 한다.
*/

int main ()
{

    /* 
    C++ 표준 기능의 대부분은 std 라는 namespace 안에 존재하고 있다.
    이름이 겹치는 것을 방지해주기 위해서이다.
    cout: 콘솔창에 출력해주는 기능이다. 뒤에 있는 ""(큰따옴표) 안에 있는
    문자들을 화면에 출력해준다. 문자 여러개를 사용할 때는 반드시 "" 안에
    넣어두고 이런 것을 문자열이라고 한다.
    endl: 개행 기능이다.
    */
    cout << "Hello world" << endl;
    cout << "가나다라" << endl;

    /*
    변수: 변하는 수. 값이 바뀔 수 있다.
    용량의 최소단위: bit, 
    1byte = 8bit; 
    1kbyte = 1024byte;
    1mbyte = 1024kbyte;
    1gbyte = 1024mbyte;
    1tbyte = 1024gbyte;

    문자를 표현하는 방법: ASCII 코드 표를 가지고 있다.
    false: 0 ; true: 0이 아닌 모든 수.
    unsigned: 부호가 없다
    종류    |   용량    |   데이터  |   표현범위        |   unsigned    |
    char    |   1byte   |   문자    |   -128 ~ 127      |   0~255   |
    bool    |   1byte   |   참/거짓 |   true/false      |   true/false  |
    short   |   2byte   |   정수    |   -32768~32767    |   0~65535 |
    int     |   4byte   |   정수    |   약 -22억 ~ 21억 |   0 ~ 약 43억 |
    float   |   4byte   |   실수    |                   |
    double  |   8byte   |   실수    |
    */

   /*
   변수의 이름을 지을 때는 숫자, 특수문자 (_ "언더바") 를 맨 처음으로 
   넣을 수 없다
   */
    int Number = 10;
    Number = 20;

    cout << Number << endl;

    bool bTest = true;
    bTest = false;
 
    cout << bTest << endl;
 
    /*
    영문이나 숫자는 1byte를 차지한다. 하지만 한글이나 한문, 등의 문자들은
    2byte를 차지하기 때문에 char 변수 하나에 저장하기가 힘들다.
    */
    char cTest = 't';

    cout << cTest << endl;

    float fNumber = 3.14f;
    
    cout << fNumber << endl;
    
    double dNumber = 123.4567;

    cout << dNumber << endl;

    /*
    사칙연산자: +, -, *, /, %(나머지 연산자)
    C++에서는 괄호는 전부 괄호 한 종류로 취급을 한다.
    관계연산자: 값대 값을 연산하여 참/거짓으로 결과를 반환한다.
                >, >=, <, <=, ==, != (다르다)
    논리연산자: 참/거짓 대 참/거짓 을 연산하여 참/거짓으로 결과를 반환한다.
                AND(&&), OR(||), NOT(!)
                A   B   AND     OR  |   A   NOT
                0   0   0       0   |   0   1
                1   0   0       1   |   1   0
                0   1   0       1   |
                1   1   1       1   |

    진수: 2진수, 8진수, 10진수, 16진수
    2진수   : 0 ~ 1
    8진수   : 0 ~ 7
    10진수  : 0 ~ 9
    16진수  : 0 ~ 9, a ~ f
    87을 2진수, 16진수로 변환해보자.
    87 / 2 = 43 -- 1
    43 / 2 = 21 -- 1
    21 / 2 = 10 -- 1
    10 / 2 = 5 -- 0
    5 / 2 = 2 -- 1
    2 / 2 = 1 -- 0
    가장 마지막에 나온 몫부터 역순으로 나머지값을 읽는다.
    1010111

    53 / 2 = 26 -- 1
    26 / 2 = 13 -- 0
    13 / 2 = 6 -- 1
    6 / 2 = 3 -- 0
    3 / 2 = 1 -- 1
    110101

    16진수는 2진수에서 변환하는것이 쉽다. 16진수 1자리는 2진수의 4자리이다.
    0101 0111
    8421 8421
    4+1=5 4+2+1 = 7
    16진수: 57.

    비트단위 논리연산자 : 2진수 단위의 연산을 한다. 값대 값을 연산하여 값으로
    나온다.
    종류: AND(&), OR(|). NOT(~), XOR(^)
    A   B   XOR (둘이 다를 때 true를 반환.)
    0   0   0
    1   0   1
    0   1   1
    1   1   0

    87 & 53 =
    87  : 1010111
    53  : 0110101

    먼저 위처럼 2진수로 바꾼 후에 2진수 각 자리별로 논리연산을 실행한다.
      1010111
    & 0110101
      0010101
    10101 가 나온다.
    10진수로 변환하면:
    1 0101
    168421
    16 + 4 + 1 = 21이 나온다.
    */

    // 관계연산자:
    cout << "10 < 20 =" << (10 < 20) << endl;
    cout << "10 < 20 =" << (10 <= 20) << endl;
    cout << "10 < 20 =" << (10 > 20) << endl;
    cout << "10 < 20 =" << (10 >= 20) << endl;
    cout << "10 < 20 =" << (10 == 20) << endl;
    cout << "10 < 20 =" << (10 != 20) << endl;

    // 값을 받아 변수에 저장.

    cout << "숫자를 입력하세요 : ";
    cin >> Number;

    // 논리연산자:
    cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;

    cout << "87 & 53 = " << (87 & 53) << endl;

    return 0;
}

#include<iostream>
#include<time.h> // 난수를 받기 위해 선언
#include<stdlib.h> // exit를 사용하기 위해 선언

using namespace std;

int main()
{
 srand((unsigned int)time(0));

 int iAnswer[3] = {};

 // 내가 전에 로또 만들때 썼던 그걸 가지고 와버렸다.
 for (int i = 0; i < 3; i++)
 {
  iAnswer[i] = (rand() % 9) + 1;
  for (int j = 0; j < 3; ++j)
  {
   if (i != j)
   {
    if (iAnswer[i] == iAnswer[j])
    {
     i -= 1;
     continue;
    }
   }
  }
 }

 while (1) {

  int iUser[3] = {};
  cout << "\t야구 게임!!" << endl << "정답은 \t: \t* \t* \t*" << endl << "1 ~9 사이의 숫자를 3개 입력 하세요." << endl;
  cout << "입력(종료는 0 입력) : ";

  // iUser배열에 유저가 입력한 값을 받기 위해 만듬!
  for (int i = 0; i < 3; ++i)
  {
   cin >> iUser[i];
   if (iUser[i] == 0)
   {
    cout << "0을 입력하셨으므로 종료!" << endl;
    exit(1);
   }
  }


  // iAnswer의 값과 iUser의 값의 비교에 의한 출력
  int iStrike = 0;
  int iBall = 0;

  for (int i = 0; i < 3; ++i)
  {
   for (int j = 0; j < 3; ++j)
   {
    if (i == j)
    {
     if (iAnswer[i] == iUser[j])
      iStrike += 1;
    }
    else if (iAnswer[i] == iUser[j])
     iBall += 1;
   }
  }

  if (iStrike == 0 && iBall == 0)
   cout << "Out!!!!!!" << endl;
  else if (iStrike == 3)
  { 
   cout << "정답입니다!!!! 3개 모두 맞추셨으므로 종료합니다! " << endl;
   break;
  }

  // 정답이 맞는지 확인하자
  
  cout << "Strike : " << iStrike << endl << "Ball : " << iBall << endl << endl;
  iStrike = 0;
  iBall = 0;
  
  // iUser의 값이 어떤지 확인하기 위해 만듬
  cout << "유저가 입력한 정보" << endl;
  for (int i = 0; i < 3; ++i)
  {
   cout << "<" << iUser[i] << ">" << "\t";
  }
  cout << endl;

  // iAnswer에 값이 잘 들어왔는지 확인하기 위해 만듬
  cout << "정답" << endl;
  for (int i = 0; i < 3; ++i) 
  {
   cout << "<" << iAnswer[i] << ">" << "\t";
  }
  cout << endl << endl;
  
 }

 return 0;
}

// 1 ~ 9 랜덤 숫자
// 난수 3개를 받을 크기3의 배열 (중복 X)
// 난수를 받고 * * * 출력
// 정답을 찾을때까지 반복
// 숫자가 맞는게 없다면 Out 출력
// 숫자와 위치가 모두 맞다면 Strike
// 숫자는 맞지만 위치가 다르다면 ball 
// 정답 or 0의 값이 들어오면 종료
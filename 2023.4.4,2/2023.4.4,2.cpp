// 2023.4.4,2.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"

int main()
{
    //배열 : 순차적인 공간을 할당해서 데이터를 저장하는 방식]

    /*
    int nData = 10;

    int nData[3] = { 1, 2, 3 };
    
    aData[0] = 1;
    aData[1] = 2;
    aData[2] = 3;
    위와 똑같은 의미
    */

	srand(time(NULL));
	rand();

	/*
	셔플: 겹치지 않는 랜덤값을 가져옴, 난수 설정 필요
	int nData[9];
	for (int i = 0; i < 9; i++)
		nData[i] = i + 1;

	for(int i = 0; i < 100 ; i++) // 충분히 섞이게 섞는 숫자의 10배정도 섞는다
	{
		int nSrc = rand() % 9 // 소스 인덱스 번호
		int nDest = rand() % 9 // 데스트 인덱스 번호

		int nTemp = nData[nSrc]; // 셔플엔 temp값이 필요
		nData[nSrc] = nData[nDest];
		nData[nDest] = nTemp;
	}
	
	for (int i = 0; i < 9; i++)
		cout << nData[i] << endl;
	*/
	
	//배열의 기본 설정 방법
	/*
	int nData[10];

	for (int i = 0; i < 10; i++)
		nData[i] = i + 1;

	*/

	int nRand[9];//nRand1, nRand2, nRand3;
	int nUser[3];//nUser1, nUser2, nUser3;
	int nStrike, nBall, nOut;

	int nCount = 0;
	bool bGame = true;

	while (bGame)	// 유저의 선택에 의한 반복 (게임 반복)
	{
		// 게임 데이터 초기화

		for (int i = 0; i < 9; i++)
			nRand[i] = i + 1;

		for (int i = 0; i < 100; i++)
		{
			int nSrc = rand() % 9;
			int nDest = rand() % 9;

			int nTemp = nRand[nSrc];
			nRand[nSrc] = nRand[nDest];
			nRand[nDest] = nTemp;
		}

		//밑의 nRand 설정을 셔플로 더 쉽게 설정 가능
		/*
		nRand[0] = rand() % 9 + 1;
		
		while (true)
		{
			nRand[1] = rand() % 9 + 1;

			if (nRand[1] != nRand[0])
				break;
		}

		while (true)
		{
			nRand[2] = rand() % 9 + 1;

			if (nRand[2] != nRand[0] && nRand[2] != nRand[1])
				break;
		}
		*/

		nStrike = 0;

		// 게임 진행
		while (nStrike < 3) // 게임 클리어 조건에 의한 반복
		{
			system("cls");

			nCount++;

			//cout << nRand1 << nRand2 << nRand3 << endl;

			cout << "첫번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[0];
			cout << "두번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[1];
			cout << "세번째 숫자를 고르시오. (1 ~ 9) : ";
			cin >> nUser[2];

			nStrike = nBall = nOut = 0;

			for (int i = 0; i < 3; i++)
			{
				if (nUser[i] == nRand[i])
					nStrike++;
				else if (nUser[i] == nRand[(i + 1) % 3] || nUser[i] == nRand[(i + 2) % 3])
					nBall++;
				else
					nOut++;
			}

			//밑의 구문을 for문으로 구현

			/*
			if (nUser[0] == nRand[0])
				nStrike++;
			else if (nUser[0] == nRand[1] || nUser[0] == nRand[2])
				nBall++;
			else
				nOut++;

			if (nUser[1] == nRand[1])
				nStrike++;
			else if (nUser[1] == nRand[0] || nUser[1] == nRand[2])
				nBall++;
			else
				nOut++;

			if (nUser[2] == nRand[2])
				nStrike++;
			else if (nUser[2] == nRand[0] || nUser[2] == nRand[1])
				nBall++;
			else
				nOut++;
			*/

			cout << "스트라이크 : " << nStrike << endl;
			cout << "       볼 : " << nBall << endl;
			cout << "     아웃 : " << nOut << endl;

			system("pause");
		}
		cout << "총 도전 횟수 : " << nCount << endl;

		// 게임 클리어 후 새 게임, 게임 종료 선택
		char chYN;
		cout << "새 게임(y, n) ";
		cin >> chYN;

		if (chYN == 'n')
			bGame = false;
	}
     // ctrl + h --> 모두 바꾸기
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

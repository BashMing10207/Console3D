#include "TitleScene.h"

void StartTitle()
{
	std::cout << "A Maze In" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "By sinsanghyeon and baesunghyeon" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Press Any Key to Start" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Press WASD to Move" << std::endl;
	std::cout << "Press Shift to Dash/Slide" << std::endl;
	std::cout << "Press F to Shoot Bullets" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Have Fun!" << std::endl;

	while (true)if (_getch())break;
	Sleep(100);
	system("cls");

	std::cout << "그런 말이 있다." << std::endl;
	while (true)if (_getch())break;
	Sleep(100);
	std::cout << "새벽 2시에 버려진 공터에 가면." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "이상한 미로가 있다고." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "누군가가 말했었다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "누구였는지 기억은 나지 않는다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "하지만 하나는 확실하다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "그들은 결국 미로로 향했다는 것." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	system("cls");

	std::cout << "나는 경찰이다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "그리고 이 마을에서만 20번째 실종 신고가 나왔다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "모두들 미로로 갔다고만 한다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "5년전 우리 형처럼." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "상부에서 명령이 내려왔다." << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "결국 나도 실종된 형을 따라 미로로 갈 운명이였나보다" << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	std::cout << "2002.04.24 김경찰 녹음일지 1" << std::endl;
	while (true)if (_getch())break;
	Sleep(10);
	system("cls");
}

void GameOverTitle()
{
	SetFontSizeBig();
	int y = 0;
	RenderConsole("몸이 차갑다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("갑작스럽게 날아오는 괴물들에게 너무 많이 맞은 것 같다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("형... 보고 싶었는데...\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("2002.04.24 김경찰 녹음일지 2\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("GAMEOVER\n");
	while (true)if (_getch())break;
	Sleep(10);
	exit(404);
}

void GameClearTitle()
{
	SetFontSizeBig();
	int y = 0;
	RenderConsole("중간에 이상한 괴물들이 있긴 했지만\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("일단 다 죽인 것 같다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("총알은 거의 다 써가는데, 미로는 끝이 없어보인다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("하... 역시 살아돌아가긴 힘들겠다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("GPS도 잡히지 않지만... 구조요청이라도 시도해봐야지.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("일단 안으로 좀 더 들어가 봐야 겠다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("2002.04.24 김경찰 녹음일지 2\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("클리어 입니다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	RenderConsole("플레이해주셔서 감사합니다.\n");
	while (true)if (_getch())break;
	Sleep(10);
	exit(200);
}

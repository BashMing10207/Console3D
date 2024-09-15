#include<iostream>
#include "Windows.h"
#include"conio.h"
#include<vector>
#include<string>
#include<algorithm>

#include "DataStructure.h"
#include "Render.h"
#include "Core.h"
#include "mapinitializer.h"
#include "ConsoleDoubleBuffer.h"
#include "TitleScene.h"
#include"Textures.h"

using namespace std;



const std::string reset = "\033[0m";
const std::string bold = "\033[1m";
const std::string red = "\033[31m";
const std::string blue = "\033[34m";
const std::string yellow = "\033[33m";
const std::string purple = "\033[35m";
const std::string cyan = "\033[36m";
const std::string green = "\033[32m";
const std::string black = "\033[30m";
const std::string white = "\033[37m";
const std::string underline = "\033[4m";
const std::string g = "\033[32m";


vector<Obj> GameObjs;
vector<Billboard*>BillBoardss;
vector<Billboard*>MovingBillboards;
vector<Billboard*>EnemyBillboards;
char Pixels[8] = { '@','#','8','E','%','X','+',' ' };
//char Pixels[8] = { '■','◆','★','E','%','X','+',' ' };
char PixelsGround[15] = { '~','-',',',',','.','.',' ',' ',' ','.','.',',',',','-','~' };
string colors[9] = { bold,red,blue,yellow,purple, cyan ,green,black,white };


	//COORD GetConsoleResolution()
	//{
	//
	//	
	//	short width = info.srWindow.Right - info.srWindow.Left + 1;
	//	short height =  - + 1;
	//	return COORD{ width,height };
	//}

	void Renderer(const int fov, Vector2 player, float rot, int resol, int playerhp)
{
	float** horizontal = new float* [3];
	float* horizontal2 = new float[fov * 2] { 999, };
	float** horizontaltx = new float* [3];
	int* horizontaltxType = new int [fov * 2] {0};
	float** horizontalTextureNum = new float* [TextureNum + 1];
	ObjLayer* las = new ObjLayer[fov * 2];

	for (int i = 0; i < 3; i++) {
		horizontal[i] = new float[fov * 2] {999, };
		horizontaltx[i] = new float[fov * 2] {0, };
		//
		for (int j = 0; j < fov * 2; j++)
		{
			horizontal[i][j] = 999;
			horizontaltx[i][j] = 0 - i;
			horizontalTextureNum = 0;
		}
	}


	vector<string> output2(SCREEN_HEIGHT);
	int** outputColor = new int* [SCREEN_HEIGHT];
	for (int j = 0; j < SCREEN_HEIGHT; j++)
	{
		outputColor[j] = new int[fov * 2];
		for (int i = 0; i < fov * 2; i++)
		{
			outputColor[j][i] = 0;
			output2[j] += "  ";
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < playerhp * 10; j++) {
			output2[i + 8][j + 8] = 'H';
		}
	}


	renderObjs(FOV, GameObjs, horizontal, horizontaltx, player, las, rot);

	renderBillBoards(FOV, BillBoardss, horizontal, horizontaltx, player, las, rot, horizontaltxType);

	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < fov * 2; j++)
		{
			if (output2[i][j] == ' ')
			{
				if (i >= horizontal[1][j] / 2 && i <= SCREEN_HEIGHT - horizontal[1][j])
				{
					if (horizontaltx[1][j] < 0)
					{
						outputColor[i][j] = 0;
					}
					else if (SCREEN_HEIGHT > horizontal[1][j])
					{

						outputColor[i][j] = BillTXS[horizontaltxType[j]][(int)(horizontaltx[1][j] * 14)][14 - (int)(((i - horizontal[1][j] / 2) / (SCREEN_HEIGHT - horizontal[1][j] / 2)) * 14)];

					}


					if ((int)(horizontal[1][j] / 5 / 2) < 7) {

						output2[i][j] = Pixels[(int)(horizontal[1][j] / 2 / 10)];
					}
					else
					{
						output2[i][j] = Pixels[6];
					}
					if (outputColor[i][j] == 0)
					{
						output2[i][j] = ' ';
					}
				}
			}
		}
	}
	//여기까지 승현이가 방금짬
	for (int i = 0; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < fov * 2; j++)
		{
			if (output2[i][j] == ' ')
			{
				{
					output2[i][j] = PixelsGround[(int)(((float)i /SCREEN_HEIGHT)*15)];
				}

				if (i >= horizontal[0][j] / 2 && i <= SCREEN_HEIGHT - horizontal[0][j] / 2)
				{
					if (SCREEN_HEIGHT - horizontal[0][i] / 2 > 0)
						outputColor[i][j] = ming[(int)(horizontaltx[0][j] * 14)][14-(int)fabs((i - horizontal[0][j] / 2) / ((SCREEN_HEIGHT - horizontal[0][j])) * 14)];
					else
						outputColor[i][j] = 8;

					if ((int)(horizontal[0][j] / 10) < 7) {

						output2[i][j] = Pixels[(int)(horizontal[0][j] / 10)];
					}
					else
					{
						output2[i][j] = Pixels[6];
					}
				}

			}
		}
	}

	string output = "";
	for (int i = PLUSHEIGHT; i < SCREEN_HEIGHT; i++)
	{
		for (int j = 0; j < fov * 2; j++)
		{
			output += colors[outputColor[i][j]];
			output += output2[i][j];
			output += reset;
		}
		output += '\n';
	}
	RenderConsole(output);
	//cout << output;
	//output.clear();
	//PrintConsoleBuffer(0, 0, output);
	//FlipConsoleBuffer();
	for (int i = 0; i < 3; i++) {
		delete[] horizontal[i];
	}
	delete horizontal;
}

void Input(Vector2* poss, Vector2* Playerpos, float rot, float speed) {
	if (GetAsyncKeyState('W') & 0x8000)
	{
		poss->x += cosf(rot) * speed;
		poss->y += sinf(rot) * speed;
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		poss->x += cosf(rot) * -speed;
		poss->y += sinf(rot) * -speed;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		poss->x += cosf(rot + 1.7079) * speed;
		poss->y += sinf(rot + 1.7079) * speed;
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		poss->x += cosf(rot + 1.7079) * -speed;
		poss->y += sinf(rot + 1.7079) * -speed;
	}

	if (GetAsyncKeyState(VK_SHIFT) & 0x8000)
	{
		poss->x += cosf(rot) * speed / 2;
		poss->y += sinf(rot) * speed / 2;
		poss->x *= 4;
		poss->y *= 4;
		if (PLUSHEIGHT < 13)
			PLUSHEIGHT += 8;
	}
	else
	{
		if (PLUSHEIGHT > 0)
		{
			PLUSHEIGHT -= 2;
			if (PLUSHEIGHT <= 0) {
				PLUSHEIGHT = 0;
			}
		}

		//if (poss->Distance() > 0) {
		//	if (PLUSHEIGHT < 3)
		//		PLUSHEIGHT += 1;
		//}
	}
	if (_kbhit())
	{
		char a = _getch();
		if (a == 'f')
		{
			Vector2 v = (*Playerpos);
			Billboard* ming = new Billboard(v, 0.4f, Vector2(cosf(rot), sinf(rot)), 10.0f, 2);
			BillBoardss.push_back(ming);
			MovingBillboards.push_back(ming);

			for (int i = 0; i < EnemyBillboards.size(); i++) {
				if (Raycasting(EnemyBillboards[i]->ConvertObj(rot), Obj(Vector2(Playerpos->x, Playerpos->y), Vector2(Playerpos->x + cosf(rot) * 300, Playerpos->y + sinf(rot) * 300))).able)
				{
					BillBoardss.erase(find(BillBoardss.begin(), BillBoardss.end(), EnemyBillboards[i]));
					MovingBillboards.erase(find(MovingBillboards.begin(), MovingBillboards.end(), EnemyBillboards[i]));
					Billboard* ming = EnemyBillboards[i];
					EnemyBillboards.erase(EnemyBillboards.begin() + i);
					delete ming;
				}
			}

		}
	}
}

void Update() {

}

int main()
{
	StartTitle();

	//system("mode con: cols=960 lines=540");

	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 4;                   // Width of each character in the font
	cfi.dwFontSize.Y = 4;                  // Height
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	vector<Obj> GameObjss;
	SetMap(&GameObjss);
	for (int i = 0; i < GameObjss.size(); i++)
	{
		GameObjs.push_back(GameObjss[i]);
	}

	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	InitConsoleBuffer();


	float speedOrigin = 15;
	int fov = FOV, playerHP = 5;
	int resol = 860;
	float rot = 0, speed = 0;
	Vector2 Playerpos = Vector2(0, 0);
	POINT TMPMousePos = { 0,0 };
	float deltaTime = 0;
	LARGE_INTEGER Current, last, MING;
	QueryPerformanceCounter(&Current);
	QueryPerformanceFrequency(&MING);
	last = Current;
	InitConsoleBuffer();
	bool beforeSpawn = true;
	while (true)
	{
		if (Playerpos.y > 305 * 2) {
			GameClearTitle();
		}
		if (Playerpos.y > 150 * 2 && beforeSpawn)
		{
			beforeSpawn = false;
			srand((unsigned int)time(NULL));
			for (int i = 0; i < 20; i++)
			{
				int x = rand() % 100 - 50;
				int y = rand() % 100 - 50;
				Billboard* enemy = new Billboard(Vector2(Playerpos.x + x, Playerpos.y + y), 2, Vector2(), 0.5, 1);
				BillBoardss.push_back(enemy);
				MovingBillboards.push_back(enemy);
				EnemyBillboards.push_back(enemy);
			}
		}
		QueryPerformanceCounter(&Current);
		deltaTime = (float)(Current.QuadPart - last.QuadPart) / static_cast<float>(MING.QuadPart);
		last = Current;
		speed = speedOrigin;
		Vector2 poss = Vector2(0, 0);
		if (rot > 2 * 3.141592) {
			rot = 0;
		}
		else
			if (rot < 0)
			{
				rot = 2 * 3.141591;
			}

		Renderer(fov, Playerpos, rot, resol, playerHP);
		Input(&poss, &Playerpos, rot, speed);

		for (int i = 0; i < MovingBillboards.size(); i++) {
			MovingBillboards[i]->pos.x += MovingBillboards[i]->dir.x * MovingBillboards[i]->speed;
			MovingBillboards[i]->pos.y += MovingBillboards[i]->dir.y * MovingBillboards[i]->speed;

		}

		for (int i = 0; i < EnemyBillboards.size(); i++) {
			EnemyBillboards[i]->dir = Vector2(Playerpos.x - EnemyBillboards[i]->pos.x, Playerpos.y - EnemyBillboards[i]->pos.y).Normalized();
			if (VDistace(EnemyBillboards[i]->pos, Playerpos) < 0.8)
			{
				playerHP--;

				BillBoardss.erase(find(BillBoardss.begin(), BillBoardss.end(), EnemyBillboards[i]));
				MovingBillboards.erase(find(MovingBillboards.begin(), MovingBillboards.end(), EnemyBillboards[i]));
				Billboard* ming = EnemyBillboards[i];
				EnemyBillboards.erase(EnemyBillboards.begin() + i);
				delete ming;
			}
		}
		if (playerHP < 1) {
			GameOverTitle();
		}
		if (poss.x != 0 || poss.y != 0)
		{
			bool able = true;
			for (int i = 0; i < GameObjs.size(); i++)
			{
				if (Raycasting(GameObjs[i], Obj(Playerpos, Vector2(Playerpos.x + poss.x * deltaTime * 2, Playerpos.y + poss.y * deltaTime * 2))).able)
				{
					able = false;
					break;
				}
			}
			for (int i = 0; i < BillBoardss.size(); i++)
			{
				Obj Billbod = BillBoardss[i]->ConvertObj(rot);
				if (Raycasting(Billbod, Obj(Playerpos, Vector2(Playerpos.x + poss.x * deltaTime*2, Playerpos.y + poss.y * deltaTime*2))).able)
				{
					able = false;
					break;
				}
			}

			if (able)
			{
				Playerpos.x += poss.x*deltaTime;
				Playerpos.y += poss.y*deltaTime;
			}
			else
			{

			}
		}
		POINT p;
		if (GetCursorPos(&p))
		{
			rot += (p.x - 500.0) / 1000.0;
			TMPMousePos = p;
			SetCursorPos(500, 500);
		}
	}
	return 0;
}
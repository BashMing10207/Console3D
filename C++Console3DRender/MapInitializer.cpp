#include "MapInitializer.h"
#include <fstream>
#include <iostream>

void SetMap(std::vector<Obj>* map)//맵 초기화 처리
{
	int Startx, Starty, Endx, Endy, texture;
	std::ifstream file;
	file.open("mapData.txt");
	while (!file.eof())
	{
		file >> Startx >> Starty >> Endx >> Endy >> texture;
		map->push_back(Obj(Vector2(Startx*2, Starty*2), Vector2(Endx*2, Endy*2), texture, ObjLayer::Stru));
	}
	file.close();

}

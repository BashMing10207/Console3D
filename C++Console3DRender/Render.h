#pragma once
#include <vector>
#include "DataStructure.h"
#include "Core.h"

void renderObjs(int fov, std::vector<Obj> GameObjs,
	float** horizontal, float** HorizontalTexture,
	Vector2 player, ObjLayer* las, float playerRotation);

void renderBillBoards(int fov, std::vector<Billboard*> Billboards,
	float** horizontal, float** HorizontalTexture,
	Vector2 player, ObjLayer* las, float playerRotation, int* horizontaltxType);


#include "Core.h"
void SetColor(int _textcolor, int _bgcolor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE)
		, (_bgcolor << 4) | _textcolor);
}

void Gotoxy(int x, int y)
{
	// 콘솔 커서 위치를 딱 세팅
	COORD Cur = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
		Cur);
}

float VDistace(Vector2 a, Vector2 b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Vector2 Raycasting(Obj gm, Obj ray)
{
	float lean1, lean2, start1, start2;
	lean1 = (gm.start.y - gm.end.y) / (gm.start.x - gm.end.x);
	start1 = gm.start.y - lean1 * gm.start.x;

	lean2 = (ray.start.y - ray.end.y) / (ray.start.x - ray.end.x);
	start2 = ray.start.y - lean2 * ray.start.x;


	Vector2 ming{ 1, 1 };
	ming.able = false;
	if (lean1 == lean2)
	{
		return ming;
	}

	//ming.x = -(start1 - start2) / (lean1 - lean2);
	//ming.y = ming.x * lean1 + start1;

	ming.x = ((gm.start.x * gm.end.y - gm.start.y * gm.end.x) * (ray.start.x - ray.end.x) - (ray.start.x * ray.end.y - ray.start.y * ray.end.x) * (gm.start.x - gm.end.x))
		/ ((gm.start.x - gm.end.x) * (ray.start.y - ray.end.y) - (ray.start.x - ray.end.x) * (gm.start.y - gm.end.y));
	ming.y = ((gm.start.x * gm.end.y - gm.start.y * gm.end.x) * (ray.start.y - ray.end.y) - (ray.start.x * ray.end.y - ray.start.y * ray.end.x) * (gm.start.y - gm.end.y))
		/ ((gm.start.x - gm.end.x) * (ray.start.y - ray.end.y) - (ray.start.x - ray.end.x) * (gm.start.y - gm.end.y));

	if(VDistace(Vector2((gm.start.x + gm.end.x) / 2, (gm.start.y + gm.end.y) / 2), ming) <= VDistace(gm.start, gm.end)/2 && (ming.x <= (ray.start.x >= ray.end.x ? ray.start.x : ray.end.x) && ming.x >= (ray.start.x <= ray.end.x ? ray.start.x : ray.end.x)
		&& ming.y <= (ray.start.y >= ray.end.y ? ray.start.y : ray.end.y) && ming.y >= (ray.start.y <= ray.end.y ? ray.start.y : ray.end.y)))
		//(ming.x <= (ray.start.x >= ray.end.x ? ray.start.x : ray.end.x) && ming.x >= (ray.start.x <= ray.end.x ? ray.start.x : ray.end.x) &&
		//ming.y <= (ray.start.y >= ray.end.y ? ray.start.y : ray.end.y) && ming.y >= (ray.start.y <= ray.end.y ? ray.start.y : ray.end.y)
		//&& (ming.x-0.1 <= (gm.start.x >= gm.end.x ? gm.start.x : gm.end.x) && ming.x+0.1 >= (gm.start.x <= gm.end.x ? gm.start.x : gm.end.x) &&
		//ming.y-0.1 <= (gm.start.y >= gm.end.y ? gm.start.y : gm.end.y) && ming.y+0.1 >= (gm.start.y <= gm.end.y ? gm.start.y : gm.end.y))))
	{
		ming.able = true;
	}

	return ming;
}
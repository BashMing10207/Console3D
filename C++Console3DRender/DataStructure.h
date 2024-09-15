#pragma once
#include<vector>
using std::vector;

enum ObjLayer {
	Stru,
	Bill
};

struct Vector2 {
	float x = 0; float y = 0;
	Vector2(float x1, float y1) {
		x = x1; y = y1;
	}

	Vector2() {
		x = 0; y = 0;
	}

	float Distance()
	{
		return sqrtf(x * x + y * y);
	}
	Vector2 Normalized() 
	{
		return Vector2(x / Vector2(x, y).Distance(), y /Vector2(x, y).Distance());
	}
	bool able = true;
};

struct Obj {
public:
	Vector2 start;
	Vector2 end;
	bool able;
	ObjLayer la = ObjLayer::Stru;
	int textureNum=1;

	Obj(Vector2 start1, Vector2 end1, int textureNum = 1, ObjLayer laa = ObjLayer::Stru ) {
		start = start1;
		end = end1;
		this->textureNum = textureNum;
		la = laa;
	};



	Obj() {};
};

struct Billboard {
public:
	int textureNum;
	Vector2 pos;
	float size;
	Vector2 dir;
	float speed;
	Billboard(Vector2 po, float si, int texture = 2)
	{
		pos = po;
		size = si;
		textureNum = texture;
	};
	Billboard(Vector2 po, float si, Vector2 direction, float speed, int texture=2)
	{
		pos = po;
		size = si;
		dir = direction;
		this->speed = speed;
		textureNum = texture;
	};

	Obj ConvertObj(float rot) {
		return Obj(Vector2(pos.x + cos(rot + 1.7079) * size, pos.y + sin(rot + 1.7079) * size),
			Vector2(pos.x + cos(rot - 1.7079) * size, pos.y + sin(rot - 1.7079) * size));
	}
};


struct Obj4 {
public:
	Obj lines[4];

	Obj4(Vector2 r, Vector2 ¤¡, Vector2 L, Vector2 j) {
		lines[0] = Obj(r, ¤¡);
		lines[1] = Obj(j, ¤¡);
		lines[2] = Obj(L, j);
		lines[3] = Obj(r, L);
	}
	Obj4() {};
};

struct Objs {
public:
	int textureNum;
	vector<Obj> lines;
	Objs(vector<Vector2> points, int texture)
	{
		textureNum = texture;
		for (int i = 1; i < points.size(); i++) {
			lines.push_back(Obj(points[i], points[i - 1]));
		}
		lines.push_back(Obj(points[0], points[points.size() - 1]));
	}

	Objs(vector<Vector2> points, ObjLayer laa)
	{
		for (int i = 1; i < points.size(); i++) {
			lines.push_back(Obj(points[i], points[i - 1], laa));
		}
		lines.push_back(Obj(points[0], points[points.size() - 1], laa));
	}

	Objs() {};
};
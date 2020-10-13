#include "cube.h"

#define MOVE(a,b) \
onpos[int(a)].pcube->moveto(b);\
//onpos[(int(b)-1)].pcube->moveto(b);\

cube::cube()
{

}

cube::~cube()
{

}

angle::angle()
{

}



angle::~angle()
{

}

void angle::moveto(position pos)
{

}

edge::edge()
{

}

edge::~edge()
{

}

void edge::moveto(position pos)
{

}

magiccube::magiccube()
{
}

magiccube::~magiccube()
{
}

void magiccube::find(position pos,cube* pcube)
{
	for (int i = 0; i < 8; i++)
	{
		if (anglebox[i].pos == pos)
			pcube = anglebox + i;
	}
	{
		if ();
	}
	return nullptr;
}

void magiccube::ResetAllOnpos()
{
	for (int i = 0; i < 26; i++)
		find(position(i), onpos[i].pcube);
}

void magiccube::F()
{
	MOVE(aaa, aac);
	MOVE(aac, cac);
	MOVE(cac, caa);
	MOVE(caa, aaa);
	MOVE(baa, aab);
	MOVE(aab, bac);
	MOVE(bac, cab);
	MOVE(cab, baa);
	ResetAllOnpos();
}


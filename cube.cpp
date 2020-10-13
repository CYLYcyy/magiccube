#include "cube.h"

#define MOVE(a,b) \
pcube[int(a)]->moveto(b);\
//onpos[(int(b)-1)].pcube->moveto(b);\

angle::angle()
{

}

angle::angle(int a,int b,int c,position p)
	:color{a,b,c},pos(p)
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
	for(int i=0;i<26;i++)
		pcube[i] = nullptr;
}

magiccube::~magiccube()
{
	
}

void magiccube::find(position pos,cube* pcube)
{
	for (int i = 0; i < 8; i++)
	{
		if (anglebox[i].pos == pos)
		{
			pcube = &(anglebox[i]);
			return;
		}
	}
	for (int i = 0; i < 12; i++)
	{
		if (edgebox[i].pos == pos)
		{
			pcube = &(edgebox[i]);
			return;
		}
	}
}

void magiccube::ResetAllOnpos()
{
	for (int i = 0; i < 26; i++)
		find(position(i), pcube[i]);
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


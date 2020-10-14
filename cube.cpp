#include "cube.h"

//½»»»
#define change(x, y) \
	int t;\
	t = x;\
	x = y;\
	y = t;
//ÒÆ¶¯ÅÐ¶Ï
#define move(x,y) \
	case position::x:\
		pos = position::y;\
		break

void cube::F()
{
	change(color[0], color[2]);
	switch (pos)
	{
		//½Ç
		move(aaa, aac);
		move(aac, cac);
		move(cac, caa);
		move(caa, aaa);
		move(aca, acc);
		move(acc, ccc);
		move(ccc, caa);
		move(cca, aca);
		//±ß
		move(baa, aab);
		move(bca, acb);
		move(bac, cab);
		move(bcc, ccb);
		move(aba, abc);
		move(cba, aba);
		move(abc, cbc);
		move(cbc, cba);
		move(aab, bac);
		move(cab, baa);
		move(acb, bcc);
		move(ccb, bca);
	default:
		break;
	}
}

magiccube::magiccube()
{
	cubebox[0] = cube(2, 1, 5, 0);
	cubebox[1] = cube(4, 1, 5, 1);
	cubebox[2] = cube(2, 1, 3, 2);
	cubebox[3] = cube(4, 1, 3, 3);
	cubebox[4] = cube(2, 6, 5, 4);
	cubebox[5] = cube(4, 6, 5, 5);
	cubebox[6] = cube(2, 6, 3, 6);
	cubebox[7] = cube(4, 6, 3, 7);
	cubebox[8] = cube(0, 1, 5, 8);
	cubebox[9] = cube(0, 6, 5, 9);
	cubebox[10] = cube(0, 1, 3, 10);
	cubebox[11] = cube(0, 6, 3, 11);
	cubebox[12] = cube(2, 0, 5, 12);
	cubebox[13] = cube(4, 0, 5, 13);
	cubebox[14] = cube(2, 0, 3, 14);
	cubebox[15] = cube(4, 0, 3, 15);
	cubebox[16] = cube(2, 1, 0, 16);
	cubebox[17] = cube(4, 1, 0, 17);
	cubebox[18] = cube(2, 6, 0, 18);
	cubebox[19] = cube(4, 6, 0, 19);
	for (int i = 0; i < 20; i++)
		pcube[i] = &cubebox[i];
	for (int i = 20; i < 26; i++)
		pcube[i] = nullptr;
}

magiccube::~magiccube()
{
	for (int i = 0; i < 26; i++)
		pcube[i] = nullptr;
}

void magiccube::find(position pos,cube*& pcube)
{
	for (int i = 0; i < 20; i++)
	{
		if (cubebox[i].pos == pos)
		{
			pcube = &cubebox[i];
			return;
		}
	}
}

void magiccube::ResetAllpointers()
{
	for (int i = 0; i < 26; i++)
		find(position(i), pcube[i]);
}

void magiccube::F()
{
	pcube[int(position::aaa)]->F();
	pcube[int(position::aac)]->F();
	pcube[int(position::cac)]->F();
	pcube[int(position::caa)]->F();

	pcube[int(position::baa)]->F();
	pcube[int(position::aab)]->F();
	pcube[int(position::bac)]->F();
	pcube[int(position::cab)]->F();

	ResetAllpointers();
}

int main()
{
	return 0;
}
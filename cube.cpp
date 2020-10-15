#include "cube.h"

//Ωªªª
#define change(x, y) \
	t = x;\
	x = y;\
	y = t;

//–˝◊™
#define c1(x, y) \
	t = x;\
	x = -y;\
	y = t;


//“∆∂Ø≈–∂œ
#define move(x,y) \
	case position::x:\
		pos = position::y;\
		break

//»∆y÷·∆Ω––œﬂÀ≥ ±’Î
void cube::YS()
{
	int t;
	change(color[0], color[2]);
	c1(pos.z, pos.x);
	//switch (pos)
	//{
	//	//Ω«
	//	move(aaa, aac);
	//	move(aac, cac);
	//	move(cac, caa);
	//	move(caa, aaa);
	//	move(aca, acc);
	//	move(acc, ccc);
	//	move(ccc, caa);
	//	move(cca, aca);
	//	//±ﬂ
	//	move(baa, aab);
	//	move(bca, acb);
	//	move(bac, cab);
	//	move(bcc, ccb);
	//	move(aba, abc);
	//	move(cba, aba);
	//	move(abc, cbc);
	//	move(cbc, cba);
	//	move(aab, bac);
	//	move(cab, baa);
	//	move(acb, bcc);
	//	move(ccb, bca);
	//default:
	//	break;
	//}
}
//»∆y÷·∆Ω––œﬂƒÊ ±’Î
void cube::YN()
{
	int t;
	change(color[0], color[2]);
	c1(pos.x,pos.z)
	//switch (pos)
	//{
	//	//Ω«
	//	move(aaa, caa);
	//	move(aac, aaa);
	//	move(cac, aac);
	//	move(caa, cac);
	//	move(aca, cca);
	//	move(acc, aca);
	//	move(ccc, acc);
	//	move(cca, ccc);
	//	//±ﬂ
	//	move(baa, cab);
	//	move(bca, ccb);
	//	move(bac, aab);
	//	move(bcc, acb);
	//	move(aba, cba);
	//	move(cba, cbc);
	//	move(abc, aba);
	//	move(cbc, abc);
	//	move(aab, baa);
	//	move(cab, bac);
	//	move(acb, bca);
	//	move(ccb, bcc);
	//default:
	//	break;
	//}
}

//»∆x
void cube::XS()
{
	int t;
	change(color[1], color[2]);
	c1(pos.z, pos.y);
}

void cube::XN()
{
	int t;
	change(color[1], color[2]);
	c1(pos.y, pos.z);
}

void cube::ZS()
{
	int t;
	change(color[0], color[1]);
	c1(pos.y, pos.x);
}

void cube::ZN()
{
	int t;
	change(color[0], color[1]);
	c1(pos.x, pos.y);
}



magiccube::magiccube()
{
	cubebox[0] = cube(2, 1, 5, -1,-1,-1);
	cubebox[1] = cube(4, 1, 5, 1, -1, -1);
	cubebox[2] = cube(2, 1, 3, -1, -1, 1);
	cubebox[3] = cube(4, 1, 3, 1, -1, 1);
	cubebox[4] = cube(2, 6, 5, -1, 1, -1);
	cubebox[5] = cube(4, 6, 5, 1, 1, -1);
	cubebox[6] = cube(2, 6, 3, -1, 1, 1);
	cubebox[7] = cube(4, 6, 3, 1, 1, 1);
	cubebox[8] = cube(0, 1, 5, 0, -1, -1);
	cubebox[9] = cube(0, 6, 5, 0, 1, -1);
	cubebox[10] = cube(0, 1, 3, 0, -1, 1);
	cubebox[11] = cube(0, 6, 3, 0, 1, 1);
	cubebox[12] = cube(2, 0, 5, -1, 0, -1);
	cubebox[13] = cube(4, 0, 5, 1, 0, -1);
	cubebox[14] = cube(2, 0, 3, -1, 0, 1);
	cubebox[15] = cube(4, 0, 3, 1, 0, 1);
	cubebox[16] = cube(2, 1, 0, -1, -1, 0);
	cubebox[17] = cube(4, 1, 0, 1, -1, 0);
	cubebox[18] = cube(2, 6, 0, -1, 1, 0);
	cubebox[19] = cube(4, 6, 0, 1, 1, 0);
}

magiccube::~magiccube()
{

}

void magiccube::F()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == -1)
			cubebox[i].YS();
	}
}

void magiccube::F_()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == -1)
			cubebox[i].YN();
	}
}

void magiccube::B()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == 1)
			cubebox[i].YS();
	}
}

void magiccube::B_()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == 1)
			cubebox[i].YN();
	}
}

void magiccube::U()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.z == 1)
			cubebox[i].ZS();
	}
}

void magiccube::U_()
{

}

void magiccube::D()
{
}

void magiccube::D_()
{
}

void magiccube::L()
{
}

void magiccube::L_()
{
}

void magiccube::R()
{
}

void magiccube::R_()
{
}

int main()
{
	return 0;
}
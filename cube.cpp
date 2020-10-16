#include "cube.h"

#include<iostream>

//交换
#define change(x, y) \
	t = x;\
	x = y;\
	y = t;

//旋转时坐标变换
#define revolve(x, y) \
	t = x;\
	x = -y;\
	y = t;

//绕y轴平行线顺时针
void cube::YS()
{
	int t;
	change(color[0], color[2]);
	revolve(pos.z, pos.x);
}
//绕y轴平行线逆时针
void cube::YN()
{
	int t;
	change(color[0], color[2]);
	revolve(pos.x,pos.z)
}

//绕x
void cube::XS()
{
	int t;
	change(color[1], color[2]);
	revolve(pos.z, pos.y);
}

void cube::XN()
{
	int t;
	change(color[1], color[2]);
	revolve(pos.y, pos.z);
}

void cube::ZS()
{
	int t;
	change(color[0], color[1]);
	revolve(pos.y, pos.x);
}

void cube::ZN()
{
	int t;
	change(color[0], color[1]);
	revolve(pos.x, pos.y);
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
	cubebox[20] = cube(0, 1, 0, 0, -1, 0);
	cubebox[21] = cube(2, 0, 0, -1, 0, 0);
	cubebox[22] = cube(0, 0, 3, 0, 0, 1);
	cubebox[23] = cube(4, 0, 0, 1, 0, 0);
	cubebox[24] = cube(0, 0, 5, 0, 0, -1);
	cubebox[25] = cube(0, 6, 0, 0, 1, 0);
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
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.z == 1)
			cubebox[i].ZN();
	}
}

void magiccube::D()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.z == -1)
			cubebox[i].ZS();
	}
}

void magiccube::D_()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.z == -1)
			cubebox[i].ZN();
	}
}

void magiccube::L()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.x == -1)
			cubebox[i].XS();
	}
}

void magiccube::L_()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.x == -1)
			cubebox[i].XN();
	}
}

void magiccube::R()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.x == -1)
			cubebox[i].XS();
	}
}

void magiccube::R_()
{
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.x == -1)
			cubebox[i].ZN();
	}
}

bool magiccube::recovered() const
{
	bool re = false;
	int num = 0;
	int colorvector[6][9];
	int j[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == -1)
			colorvector[0][j[0]++] = cubebox[i].color[1];
		if (cubebox[i].pos.x == -1)
			colorvector[1][j[1]++] = cubebox[i].color[0];
		if (cubebox[i].pos.z == 1)
			colorvector[2][j[2]++] = cubebox[i].color[2];
		if (cubebox[i].pos.x == 1)
			colorvector[3][j[3]++] = cubebox[i].color[0];
		if (cubebox[i].pos.z == -1)
			colorvector[4][j[4]++] = cubebox[i].color[2];
		if (cubebox[i].pos.y == 1)
			colorvector[5][j[5]++] = cubebox[i].color[1];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (colorvector[i][j] != colorvector[i][0])
				break;
			else if (j == 8)
				num++;
		}
		if (num == 6)
			re = true;
	}
	return re;
}

void magiccube::show() const
{
	int colorvector[6][9];
	int j[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 26; i++)
	{
		if (cubebox[i].pos.y == -1)
			colorvector[0][j[0]++] = cubebox[i].color[1];
		if (cubebox[i].pos.x == -1)
			colorvector[1][j[1]++] = cubebox[i].color[0];
		if (cubebox[i].pos.z == 1)
			colorvector[2][j[2]++] = cubebox[i].color[2];
		if (cubebox[i].pos.x == 1)
			colorvector[3][j[3]++] = cubebox[i].color[0];
		if (cubebox[i].pos.z == -1)
			colorvector[4][j[4]++] = cubebox[i].color[2];
		if (cubebox[i].pos.y == 1)
			colorvector[5][j[5]++] = cubebox[i].color[1];
	}
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			std::cout << colorvector[i][j] << "  ";
			/*if (colorvector[i][j] != colorvector[i][0])
				break;
			else
				re = true;*/
		}
		std::cout << std::endl;
	}
}

int main()
{
	magiccube mycube;
	mycube.F();
	mycube.F_();
	mycube.show();
	std::cout<<mycube.recovered();
	return 0;
}
#include "cube.h"
#include<iostream>
#include<windows.h>
using namespace std;

//Ωªªª
#define change(x, y) \
	t = x;\
	x = y;\
	y = t;

//–˝◊™ ±◊¯±Í±‰ªª
#define revolve(x, y) \
	t = x;\
	x = -y;\
	y = t;


//»∆y÷·À≥ ±’Î
void cube::YS()
{
	int t;
	change(color[0], color[2]);
	revolve(pos.z, pos.x);
}
//»∆y÷·ƒÊ ±’Î
void cube::YN()
{
	int t;
	change(color[0], color[2]);
	revolve(pos.x,pos.z)
}

//»∆x÷·À≥ ±’Î
void cube::XS()
{
	int t;
	change(color[1], color[2]);
	revolve(pos.z, pos.y);
}
//»∆x÷·ƒÊ ±’Î
void cube::XN()
{
	int t;
	change(color[1], color[2]);
	revolve(pos.y, pos.z);
}

//»∆z÷·À≥ ±’Î
void cube::ZS()
{
	int t;
	change(color[0], color[1]);
	revolve(pos.y, pos.x);
}
//»∆z÷·ƒÊ ±’Î
void cube::ZN()
{
	int t;
	change(color[0], color[1]);
	revolve(pos.x, pos.y);
}

//≥ı ºªØ–°∑ΩøÈ
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

void magiccube::step(char X)
{
	system("cls");
	switch (X)
	{
	case 'F':
		F();
		break;
	case 'f':
		F_();
		break;
	case 'B':
		B();
		break;
	case 'b':
		B_();
		break;
	case 'U':
		U();
		break;
	case 'u':
		U_();
		break;
	case 'D':
		D();
		break;
	case 'd':
		D_();
		break;
	case 'L':
		L();
		break;
	case 'l':
		L_();
		break;
	case 'R':
		R();
		break;
	case 'r':
		R_();
		break;
	default:
		break;
	}
	show();
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

cube* magiccube::getcube(coordinate x)
{
	for (int i=0;i<26;i++)
	{
		if ((cubebox[i].pos.x == x.x) && (cubebox[i].pos.y == x.y) && (cubebox[i].pos.z == x.z))
		{
			cube* pcube = &cubebox[i];
			return pcube;
		}
	}
}

void magiccube::showcolor(int color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	switch (color)
	{
	case 1:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
		break;
	case 2:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
		break;
	case 3:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
		break;
	case 4:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
		break;
	case 5:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	case 6:
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	default:
		break;
	}
	std::cout << " °ˆ ";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbiInfo.wAttributes);
}

void magiccube::show()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			showcolor(getcube(coordinate(j-1, 1-i, 1))->color[1]);
		}

		for (int j = 0; j < 3; j++)
		{
			showcolor(getcube(coordinate(j - 1, 1 - i, 1))->color[1]);
		}

		for (int j = 0; j < 3; j++)
		{
			showcolor(getcube(coordinate(j - 1, 1 - i, 1))->color[1]);
		}
	}
}

int main()
{
	magiccube mycube;
	mycube.show();
	char X;
	bool flag = true;
	while (flag)
	{
		cout << "(Commands Allowed: F,f,B,b,U,u,D,d,L,l,R,r)" << endl;
		cout << "press Enter after input£∫";
		std::cin >> X;
		mycube.step(X);
	};
	return 0;
}
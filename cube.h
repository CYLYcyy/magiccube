//enum class pos {
//	aaa,
//	caa,
//	aac,
//	cac,
//	aca,
//	cca,
//	acc,
//	ccc,
//	baa,
//	bca,
//	bac,
//	bcc,
//	aba,
//	cba,
//	abc,
//	cbc,
//	aab,
//	cab,
//	acb,
//	ccb,
//};
class coordinate 
{
public:
	coordinate() {};
	coordinate(int a, int b, int c) :x(a), y(b), z(c) {};
	int x = 0;
	int y = 0;
	int z = 0;
};
class cube
{
public:
	cube() :color{ 0,0,0 }, pos(0, 0, 0){};
	cube(int a, int b, int c, int x, int y, int z) :color{ a,b,c }, pos(x, y, z){};
	void YS();
	void YN();
	void XS();
	void XN();
	void ZS();
	void ZN();
	int color[3];
	coordinate pos;
};

class magiccube
{
public:
	magiccube() /*:pcube{} {}*/;
	~magiccube();
	
	void F();
	void F_();
	void B();
	void B_();
	void U();
	void U_();
	void D();
	void D_();
	void L();
	void L_();
	void R();
	void R_();
	bool recovered() const;
	void show() const;
private:
	cube cubebox[26];
};


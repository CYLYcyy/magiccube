enum position {
	aaa = 0,
	baa,
	caa,
	aab,
	bab,
	cab,
	aac,
	bac,
	cac,
	aba,
	bba,
	cba,
	abb,
	cbb,
	abc,
	bbc,
	cbc,
	aca,
	bca,
	cca,
	acb,
	bcb,
	ccb,
	acc,
	bcc,
	ccc
};
class cube
{
public:
	virtual void moveto(position pos) = 0;
};
class angle:public cube
{
public:
	angle();
	angle(int a, int b, int c, position p) :color{ a,b,c }, pos(p){};
	~angle();
	void moveto(position pos);
	int color[3];
	position pos;
};
class edge:public cube
{
public:
	edge();
	~edge();
	void moveto(position pos);
	int color[2];
	position pos;
};
class fcenter :public cube
{
public:
	fcenter();
	~fcenter();
	int color;
	position pos;
};

class magiccube
{
public:
	magiccube() /*:pcube{} {}*/;
	~magiccube();
	
	void find(position pos,cube* );
	void ResetAllOnpos();
	
	
	void F();
	void F_();
	cube* pcube[26];
private:
	angle anglebox[8];
	edge edgebox[12];
};


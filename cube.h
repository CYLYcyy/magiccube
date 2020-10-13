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
	cube();
	~cube();
	virtual void moveto(position pos) = 0;
};
class angle:cube
{
public:
	angle();
	~angle();
	void moveto(position pos);
	int color[3];
	position pos;
};
class edge:cube
{
public:
	edge();
	~edge();
	void moveto(position pos);
	int color[2];
	position pos;
};
class fcenter :cube
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
	magiccube();
	~magiccube();
	
	class onpos
	{
	public:
		cube* pcube;
	};
	void find(position pos,cube* );
	void ResetAllOnpos();
	
	
	void F();
	void F_();
private:
	angle anglebox[8];
	edge edgebox[12];
	onpos onpos[26];
};


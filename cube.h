enum class position {
	aaa,
	caa,
	aac,
	cac,
	aca,
	cca,
	acc,
	ccc,
	baa,
	bca,
	bac,
	bcc,
	aba,
	cba,
	abc,
	cbc,
	aab,
	cab,
	acb,
	ccb,
};
class cube
{
public:
	cube();
	cube(int a, int b, int c, int p) :color{ a,b,c }, pos(position(p)){};

	void F();
	void F_();
	void U();
	void U_();
	void L();
	void L_();

	int color[3];
	position pos;
};

class magiccube
{
public:
	magiccube() /*:pcube{} {}*/;
	~magiccube();
	
	void find(position pos,cube*& );
	void ResetAllpointers();
	
	
	void F();
	void F_();
	cube* pcube[26];
private:
	cube cubebox[26];
};


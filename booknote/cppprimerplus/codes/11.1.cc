#include <iostream>

#define NEWLINE do { \
	using std::cout; \
   	using std::endl; \
	cout << endl; \
} while(0)

class my {
	private:
		long my_;
	public:
		inline my (long my = 0 );
		inline my operator + (const my & x);
		inline long dump (void) const;
};

inline long
my::dump (void) const
{
	using std::cout;
	using std::endl;
	cout << "DEBUG: " << this->my_ << endl;
	return this->my_;
}

inline 
my::my (long my)
{
	this->my_ = my;
}

inline my
my::operator + (const my & x)
{
	my ret;
	ret.my_ = x.my_ + this->my_;
	return ret;
}

int
main (void)
{
	using std::cout;
	using std::endl;

	// test 1
	NEWLINE;
	my a = my(1);
	a.dump();
	my b = my(2);
	b.dump();
	my c = a + b;

	NEWLINE;
	a.dump();
	b.dump();
	c.dump();

	// test 2
	my * x = new my (10);
	my * y = new my (11);
	my z = *x + *y;

	x->dump();
	y->dump();
	z.dump();

	delete x;
	delete y;

	return 0;
}

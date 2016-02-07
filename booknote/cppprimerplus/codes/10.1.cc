#include <iostream>
#include <string>

class point2d {
	private:
		std::string name;
		double x;
		double y;
	public:
		void set (std::string, double, double);
		void dump (void);
};

void point2d::dump (void)
{
	using std::cout;
	using std::endl;
	cout << "I: point2d [" << name
		<< "] at (x,y)=(" << x << "," << y << ")"
		<< endl;
	return;
}

void point2d::set (std::string _name, double _x, double _y)
{
	name = _name;
	x = _x;
	y = _y;
	return;
}

int
main (void)
{
	point2d p;
   	p.set ("hello", 2., 3.);
	p.dump ();
	return 0;
}

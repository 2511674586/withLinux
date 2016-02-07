#include <iostream>
#include <string>

class point2d {
	private:
		std::string name;
		double x;
		double y;
		/*
		 * from C++ primer plus :
		 *
		 * common practice for private member names
		 * 1. use prefix e.g. m_ , then m_x
		 * 2. use postfix _ , then x_
		 *
		 */
	public:
		point2d (const std::string _name = "anonymous", double _x = .0, double _y = .0);
		void set (std::string, double, double);
		void dump (void) const; // promise not to change data
};

point2d::point2d (const std::string _name, double _x, double _y) {
	set (_name, _x, _y);
}

void point2d::dump (void) const
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
	p.dump ();
   	p.set ("hello", 2., 3.);
	p.dump ();

	// C++11 list initialization
	point2d q {"target", 100., 100.};
	q.dump();
	return 0;
}

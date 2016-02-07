## Abstractions and Classes
class example
```
#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>
class Stock {
	private:
		// data hiding
		std::string company;
		long shares;
		double share_val;
		double total_val;
		void set_tot() {
			total_val = shares * share_val;
		}
	public:
		// can access private data
		void acquire (const std::string & co, long n, double pr);
		void buy (long num, double price);
		void sell (long num, double price);
		void update (double price);
		void show ();
};

#endif // STOCK00_H_
```
implement member functions
```
void Stock::update (double price) { ... }
inline void Stock::set_tot () { ... } // inline methods, often used for short member functions.
```
using this class
```
Stock sally;
Stock solly;
```

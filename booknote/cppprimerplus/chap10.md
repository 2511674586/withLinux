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

## Class Contructors and Destructors
constructor should be placed at public section, and has no return type.
```
// constructor prototype with some default arguments
Stock::Stock (const std::string & co, long n = 0, double pr = .0);
```
using constructors
```
// explicit
Stock food = Stock ("World", 100, 1.5);

// implicit
Stock garment ("Furry", 50, 2.5);

// explicit with 'new'
Stock * pstock = new Stock ("Electron", 18, 19.0);

// default constructor
Stock stock1; // won't success unless all the parameters of contructor have default value.
Stock first = Stock(); // explicitly call default constructor
```
Like contructor, destructor has no return value and no declared type, and must have no parameters.
When to call a destructor is decided by compiler, and normally one should not call a destructor explicitly,
```
// prototype
~Stock ();

// Implementation, can do nothing as a Stock destructor has no vital duties.
Stock::~Stock () {}
```
A destructor is not a must for classes, as compiler will implicitly declares
a default destructor.

## Knowing your objects: this pointer
...

## array of objects
...

## class scope
...

## Abstract Data Types
```
// e.g. Stack

typedef unsigned long Item;

class Stack {
	private:
		enum { MAX = 10 };
		Item items[MAX];
		int top;
	public:
		Stack ();
		bool isempty () const;
		bool isfull () const;
		bool push (const Item & item);
		bool pop (Item & item);
};

bool Stack::Stack () {
	top = 0;
}
bool Stack::isempty () const {
	return top == 0;
}
bool Stack::isfull () const {
	return top == MAX;
}
bool Stack::push (const Item & item)
{
	if (top < MAX) {
		items[top++] = item;
		return true;
	} else
		return false;
}
bool Stack::pop (Item & item) 
{
	if (top > 0) {
		item = items[--top];
		return true;
	} else
		return false;
}
```


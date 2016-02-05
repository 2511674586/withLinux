## creating array
Campatible array initialization.
```
int x[3] = { 5, 10, 15 };
int y[100] = {0}; // all elements set to 0. but {1} will not work in the similar way.
int z[] = { 1, 0, 0, 1, 1, 1, 0 };
```
C++11 array initialization
```
double price[4] { 1.1, 1.2, 1.3, 1.4 };
int count[10] {}; // all set to 0
```

C++ standard library (STL) provides `vector` template class.
C++11 STL introduced new `array` template class.

## strings (array)
```
char x[3] = { 'a', 'b', 'c' }; // not a string
char y[3] = { 'x', 'y', '\o' }; // is a string
```
read string
```
const int Size = 15;
char buffer [Size];
cin >> buffer;
```
read string
```
cin.getline(name, Size);
cin.get(name, Size);

cin.get(name, Size).get();
```
`cin.clear()` can be used to handle empty lines issue.

## string class
```
#include <string>
int main (void) {
string str1;
string str2 = "hello";
cin >> str1;
cout << str1;
str1[1];

string str3;
str3 = str1 + str2;
str1 += str2;
```
`#include <cstring>` is the C-style string library.

## structure
```
struct xxx
{
	char name[10];
	double mass;
};
```
C++11 structure initialization
```
xxx stone { "x", 100.0 };
```
structure arrays...

## unions

## enumerations

## pointers

```
int * pt;
// pt = 0xB8000000;      // type mismatch
pt = (int *) 0xB8000000; // type match
```

## allocate memory with new
```
int * pn = new int;

int integer;
int * pt = &integer;

delete pn;
// delete pt; // not allowed, pt is not created by new.

int * p = new int [10]; // dynamic array
delete [] p;
// delete p; // undefined.
```

## vector
```
using namespace std;
vector<int> vi;
vector<double> vd(n);
```

## array in C++11
```
array<int, 5> ai;
array<double, 4> ad = { .1, .2, .3, 4. };
```

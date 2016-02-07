## C++ inline functions
Inline functions are a C++ enhancement designed to speed up programs.
```
inline double square (double x) { return x * x; }
```

## reference variables
Act as an alias, or an alternative name.
```
int rats;
int & rodents = rats; // create a reference variable
```
references as function parameters
```
void swapv (int a, int b);     // a, b are new variables. Values are passed.
void swapp (int * p, int * q); // p, q are addresses of ints.
void swapr (int & a, int & b); // a, b are aliases for ints.
```
Tip: use `const` when you can.

## Default arguments
```
int chico (int n, int m = 6, int j);     // INVALID
int harpo (int n, int m = 4, int j = 5); // VALID

harpo (1);      // same as harpo (1, 4, 5);
harpo (3, , 8); // invalid
```

## function overloading
```
void print (const char *str);
void print (int i, int width);
```

## function templates
```
template <typename DType>
void Swap (Dtype & a, Dtype & b) {
	Dtype temp;
	temp = a; a = b; b = temp;
}
```
overloaded templates
```
template <typename T>
void Swap (T & a, T & b);

template <typename T>
void Swap (T * a, T * b, int n);
```
Explicit specialization
```
template <> void Swap<job> (job &, job &); // thrid party "job"
template <> void Swap<int> (int &, int &);
```
Explicit choise for templates
```
cout << lesser<int> (x, y) << endl;
cout << lesser<> (x, y) << endl; // telling compiler to choose a template function.
```

## decltype keyword in C++11
```
int x;
decltype (x) y;
decltype (x+y) xpy;
xpy = x + y;

// OR

decltype (x+y) xpy = x + y;
```

## operator overloading
```
district2 = sid + sara;          // plain text side
district2 = sid.operator+(sara); // compiler side
```
adding an addition operator e.g.
```
public:
	?type? operator+(const ?type? & x) const;
```
restrictions of overloading:  
1. overloaded operator must have at least one operand that is user-defined type.
2. no violating syntax
3. no new symbols
4. these operators are not being overloaded:
```
sizeof
.
.*
::
?:
typeid
const_cast
dynamic_cast
reinterpret_cast
static_cast
```
5. these operators can only be overloaded by member functions
```
=
()
[]
->
```

## introducing friends
```
A = B * 2.75; // overloaded '*', OK
A = B.operator*(2.75); // compiler side
A = 2.75 * B; // trouble
```
example prototype of a friend function
```
friend Time operator* (double m, const Time & t);
```

## conversion functions
```
public:
	operator int() const;
	operator double() const;

MYCLASS y;
double x = double (x);
```

## conversions and friends
...

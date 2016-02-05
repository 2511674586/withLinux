## integers
```
short
int
long 
long long
```

##assign value
```
int x = 1; // traditional C
int x (1); // alternative for C++
int x = {1}; // C++11
int x {1}; //C++11
int x {}; //C++11, x = 0
```

##member function of cout
```
cout << '$';    // would print the ascii code of '$'
cout.put ('$'); // would print the character as desired.
```

##wide char
```
wchar_t x = L'P'; // prefix L for wide char constants
wcout << L"tall" << endl;
```
`char16_t` and `char32_t` are new C++11 types.
```
char16_t ch1 = u'q';
char32_t ch2 = U'\U0000222B';
```

## bool type
```
bool flag = true;
```

## type conversion

* type casts
```
(long) variable; // OK, straight C
long (variable); // OK, pure C++
```

## auto declarations in C++11
e.g. C++98 code might have this
```
std::vector<double> scores;
std::vector<double>::iterator pv = scores.begin();
```
but C++11 allows one to write
```
std::vector<double> scores;
auto pv = scores.begin();
```


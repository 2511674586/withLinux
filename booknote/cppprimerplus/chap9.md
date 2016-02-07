## Separate compilation
Here are some things commonly found in header files:  

1. function prototypes  
2. symbolic constants defined using #define or const
3. structure declarations
4. class declarations
5. template declarations
6. inline functions

```
#ifdef MY_H_
#define MY_H_

#define PI 3.14

#endif
```

## storage duration, scope, and linkage
...

## Namespaces
```
namespace Jack {
	double pail;
	void fetch();
	struct Hill { ... };
}

Jack::pail = 123.456; // access variable
Jack::fetch();        // use a function
Jack::Hill mole;      // create structure
```
`using`
```
using Jill::fetch; // put fetch into local namespace
double fetch;      // already have a local fetch
cin >> fetch;      // read a value into Jill::fetch
cin >> ::fetch;    // read a value into global fetch
```

## for loops

```
int i;
for (i = 0; i < 100; i++) 

for (int i = 0; i < 100; i++)
```

Syntax tricks
```
// reverse an array, e.g. stressed -> desserts
for (j = 0, i = word.size() -1; j < i; --i, --j) {
	temp = word[i];
	word[i] = word[j];
	word[j] = word[i];
}
```

## comparing strings
```
strcmp(); // for char x[?]

string word = "asdf";
word != "adsf";
```

## while loop
...

## do-while loop
...

## range-based loop (C++11)
```
// snip 1
double price[5] = { 1., 2., 3., 4., 5. };
for (double x : price) cout << x;
for (double &x : price) cout << x; // use this if you want to modify value.

// snip 2
for (int x : { 4, 3, 6, 8, 1 }) cout << x;
```

## reading characters
```
cin.get(ch);
//while (!cin.fail()) {
while (cin) { // this is general
	...;
	cin.get(ch);
}

while (cin.get(ch)) {
	...;
}
```

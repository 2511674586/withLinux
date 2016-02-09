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

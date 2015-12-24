Convert list into string
---

```
a = 'this is a string'
b = list(a) # convert a into list

# however
print (str(b)) # result is not desirable.

# solution
c = ''.join(b) # convert list into string
print (c) # that's it
```

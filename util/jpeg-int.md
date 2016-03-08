Jpeg integrity check
===

reference: http://blog.csdn.net/mimepp/article/details/5334284

```python
with open('x.jpg', 'rb') as f:
	pic = f.read()
```

## SOI

Start Of Image is `0xFF 0xD8`
```
pic[0] == '\xff'
pic[1] == '\xd8'
```
## EOI

End Of Image is `0xFF 0xD9`
```
pic[-2] == '\xff'
pic[-1] == '\xd9'
```

## Identifier

check the `JFIF` tag or `Exif` tag.

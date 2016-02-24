#!/usr/bin/python3
import markdown as MD
with open("index.md",'r') as f:
	md = f.read()
with open("index.html", 'w+') as f:
	html = MD.markdown(md)
	f.write(html)

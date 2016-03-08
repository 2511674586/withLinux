## Insert SVG picture in latex

http://tex.stackexchange.com/questions/2099/how-to-include-svg-diagrams-in-latex  
[CTAN: How to include an SVG image in LaTeX](http://mirrors.ctan.org/info/svg-inkscape/InkscapePDFLaTeX.pdf)  

briefly
---
* draw some vectorgraphs with e.g. inkscape  
* convert file format with inkscape 
```
inkscape -D -z --file=image.svg --export-pdf=image.pdf --export-latex
```
* include figure  
```latex
\begin{figure}
	\centering
	\def\svgwidth{\columnwidth}
	\input{image.pdf_tex}
\end{figure}
```
* note: using package `graphicx`  

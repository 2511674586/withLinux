Making top bar (panel) thinner
===

```
$ sudo vim /usr/share/gnome-shell/theme/gnome-shell.css
```

And find this line:

```
/* TOP PANEL */
/* ... */
#panel {/* ... */
        height: 1.86em;
}
```

change the `height` value as you want.
such as `'s/1.86em/1.75em/g'`
  
then restart gnome-shell ( Alt+F2, r )
  
This at least works on Gnome 3.4 (wheezy) and Gnome 3.8 (jessie 2014/06).


Making top panel transparent
===

Edit `/usr/share/gnome-shell/theme/gnome-shell.css`,
find the "panel" section, 
then subtitude `black` with a `rgba()` function.

```
#panel {
/*    background-color: black; */
    background-color: rgba(0,0,0,0.382);
[...]
```

You can also change the color of the corners of top bar:
```
625 .panel-corner {
626     -panel-corner-radius: 6px;
627     -panel-corner-background-color: rgba(0,0,0,0.382);
628     -panel-corner-border-width: 2px;
```
Then restart gnome-shell.


However, one may find that there is no `gnome-shell.css` such a file
in package `gnome-shell 3.18`, and this new file appeared:
```
/usr/share/gnome-shell/gnome-shell-theme.gresource
```
according to gresource(1) from package `libglib-bin`, this is a resource ball compiled into ELF format,
and with `gresource list gnome-xxx.gresource` you can see a complete list of its contents.

Due to the ELF format, we need to ensure its displacements not being broke if think of dirty hack.
Let's edit it with `vim -b`, vim's binary mode, but without `xxd`.

Original(about line 1230):
```
1235 /* TOP BAR */
1236 #panel {
1237   background-color: black;
1238   font-weight: bold;
1239   height: 1.86em; }
```
We need to prevent the length of this embedded css file from being changed.
```
1235 /**/
1236 #panel {
1237 background-color: rgba(0,0,0,0.382);
1238  font-weight: bold;
1239   height: 1.86em; }
```
You should haave noticed that some comments and spaces are accurately striped in order to get enough
and precise palce for `rgba(0,0,0,0.382)`.

If you got the ELF offsets into a mess, gnome-shell will must crash at starting up.

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
    background-color: rgba(0,0,0,0.5);
[...]
```

Then restart gnome-shell.

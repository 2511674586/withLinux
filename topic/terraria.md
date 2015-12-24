Terraria on Linux with WINE
---

Tested on Debian Sid (Nov. 2015).  

1. download GOG version of terraria.  

2. [host] install wine32 and winetricks  

3. [wine] install msxml3 using winetricks  
```
winetricks msxml3
```

4. [wine] install .NET 4.0  
```
winetricks dotnet40
```

5. [wine] install terraria with GOG installer, install XNA as prompted.  

6. wine Terraria.exe  

#include <stdio.h>
#include <lua5.1/lua.h>
#include <lua5.1/lauxlib.h>

static int l_hello (lua_State * L)
{
	printf ("Hello, Lua!\n");
	lua_pushnumber (L, (double)0.);
	return 1;
}

static const struct luaL_Reg mylib[] = {
	{"hello", l_hello},
	{NULL, NULL}
};

int luaopen_mylib (lua_State * L)
{
	luaL_register (L, "mylib", mylib);
	return 1;
}

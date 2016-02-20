#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include <lua5.1/lua.h> /* lua_* functions, for C++ include lua.hpp instead */
#include <lua5.1/lauxlib.h> /* luaL_* functions, based on lua.h */
#include <lua5.1/lualib.h>

void onerror (lua_State * L, const char *fmt, ...); /* a simple error handler */

int
main (void)
{
	char buffer[256];
	int error;
	/* open a new lua environment. A newly opened environment has even no print()  */
	lua_State * L = luaL_newstate();
	/* open standard lib in envirionment L, so print() can be added */
	luaL_openlibs (L); 

	while (NULL != fgets(buffer, sizeof(buffer), stdin)) {
		/* luaL_loadbuffer() compiles user's input lines, pushs compiled chunk into stack,
		 * and returns 0 on success. then lua_pcall() is called, which pops program chunk
		 * from stack and execute it in a protected mode, and returns 0 on success.
		 * On error, error message will be pushed into stack, which can be fetched with
		 * lua_tostring(), then one can delete this message with lua_pop(). */
		error = luaL_loadbuffer (L, buffer, strlen(buffer), "line")
			|| lua_pcall (L, 0, 0, 0);
		if (error) {
			{ /* method 1 */
				onerror (L, "%s\n", lua_tostring(L, -1));
			}
			{ /* method 2 */	
				fprintf (stderr, "%s", lua_tostring(L, -1));
				lua_pop (L, 1); /* pop error message from stack */
			}
		}
	}

	lua_close (L);
	return 0;
}

void
onerror (lua_State * L, const char *fmt, ...)
{
	va_list argp;
	va_start (argp, fmt);
	vfprintf (stderr, fmt, argp);
	va_end (argp);
	lua_close (L);
	exit (EXIT_FAILURE);
}

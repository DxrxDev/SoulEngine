
#if !defined( _SOUL_CORE_H )
#define       _SOUL_CORE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lua/lua.h"
#include "lua/lauxlib.h"
#include "lua/lualib.h"

#define PUBLIC
#define STATIC static
#define EXTERN extern

typedef struct {
	lua_CFunction  func;
	const char    *name;
} CFuncs;

#endif     /* _SOUL_CORE_H */

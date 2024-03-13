#include "soul.h"
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

STATIC lua_State *globalState;

STATIC void *luaAlloc( void *ud, void *ptr, size_t osize, size_t nsize );

int main( int argc, char *argv[] ){
	globalState = lua_newstate( luaAlloc, NULL );
	luaL_openlibs  ( globalState );
	SoulLoadModules( globalState );

	if (luaL_dofile( globalState, "main.lua" ) != LUA_OK){
		puts( "Man.. this is some hot garbage" );
		return EXIT_FAILURE;
	}
	lua_getglobal( globalState, "_start" );
	lua_call( globalState, 0, 0 );

	while (Running( )){
		lua_getglobal( globalState, "_physics" );
		lua_call( globalState, 0, 0 );

		StartDraw( );
			lua_getglobal( globalState, "_draw" );
			lua_call( globalState, 0, 0 );

			lua_getglobal( globalState, "_ui" );
			lua_call( globalState, 0, 0 );
		EndDraw( );
	}

	return EXIT_SUCCESS;
}

STATIC void *luaAlloc( void *ud, void *ptr, size_t osize, size_t nsize ){
	if (nsize == 0){
		free( ptr );
		return NULL;
	}
	return realloc( ptr, nsize );
}

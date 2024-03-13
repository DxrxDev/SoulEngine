#define _SOUL_IMPLEMENTATION
#include "soul.h"

#include "raylib.h"
EXTERN CFuncs windowCFuncs[];
EXTERN CFuncs uiCFuncs[];

STATIC lua_State *_fs;

PUBLIC void SoulLoadModules( lua_State *_s ){
	_fs = _s;
	luaL_dofile( _s, "soul.lua" );

	for (CFuncs *i = windowCFuncs; i->name != NULL; i++){
		lua_getglobal( _s, "window" );
		lua_pushcfunction( _s, i->func );
		lua_setfield( _s, -2, i->name );
	}
	lua_setglobal( _s, "window" );

	for (CFuncs *i = uiCFuncs; i->name != NULL; ++i){
		lua_getglobal( _s, "ui" );
		lua_pushcfunction( _s, i->func );
		lua_setfield( _s, -2, i->name );
	}
	lua_setglobal( _s, "ui" );
}
PUBLIC void CleanUpSoulStuff( ){
	CloseWindow( );
}

PUBLIC bool Running( ){
	lua_getglobal ( _fs, "window" );
	
	lua_pushnumber( _fs, GetScreenWidth() );
	lua_setfield  ( _fs, -2, "width" );

	lua_pushnumber( _fs, GetScreenHeight() );
	lua_setfield  ( _fs, -2, "height" );

	return !WindowShouldClose( );
}
PUBLIC void StartDraw( void ){
	BeginDrawing( );
	ClearBackground( (Color){ 15, 40, 120, 255 } );
}
PUBLIC void EndDraw( void ){
	EndDrawing( );
}

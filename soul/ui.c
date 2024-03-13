#include "core.h"
#include "raylib.h"

PUBLIC int ui_write( lua_State *_s );
PUBLIC int ui_rectangle( lua_State *_s );

PUBLIC CFuncs uiCFuncs[] = {
	{ ui_write,     "write" },
	{ ui_rectangle, "rectangle" },
	{ NULL,         NULL },
};

PUBLIC int ui_write( lua_State *_s ){
	const char *text = lua_tostring( _s, -4 );
	float fs = lua_tonumber( _s, -3 );

	int rectSP = -2;
	float x, y, w, h;
	lua_getfield( _s, rectSP--, "x" );
	x = lua_tonumber( _s, -1 );
	lua_getfield( _s, rectSP--, "y" );
	y = lua_tonumber( _s, -1 );

	lua_getfield( _s, rectSP--, "w" );
	w = lua_tonumber( _s, -1 );

	lua_getfield( _s, rectSP--, "h" );
	h = lua_tonumber( _s, -1 );

	int colSP = rectSP+1;
	float r, g, b, a;
	lua_getfield( _s, colSP--, "r" );
	r = lua_tonumber( _s, -1 );

	lua_getfield( _s, colSP--, "g" );
	g = lua_tonumber( _s, -1 );
	
	lua_getfield( _s, colSP--, "b" );
	b = lua_tonumber( _s, -1 );
	
	lua_getfield( _s, colSP--, "a" );
	a = lua_tonumber( _s, -1 );

	DrawText( text, x - (MeasureText(text, fs) / 2.0), y - (fs / 2.0), fs, (Color){ r, g, b, a } );
	return 1;
}
PUBLIC int ui_rectangle( lua_State *_s ){

	int rectSP = -2;
       	float x, y, w, h;
	lua_getfield( _s, rectSP--, "x" );
	x = lua_tonumber( _s, -1 );
	
	lua_getfield( _s, rectSP--, "y" );
	y = lua_tonumber( _s, -1 );

	lua_getfield( _s, rectSP--, "w" );
	w = lua_tonumber( _s, -1 );

	lua_getfield( _s, rectSP--, "h" );
	h = lua_tonumber( _s, -1 );

	int colSP = rectSP+1;
	float r, g, b, a;
	lua_getfield( _s, colSP--, "r" );
	r = lua_tonumber( _s, -1 );

	lua_getfield( _s, colSP--, "g" );
	g = lua_tonumber( _s, -1 );
	
	lua_getfield( _s, colSP--, "b" );
	b = lua_tonumber( _s, -1 );
	
	lua_getfield( _s, colSP--, "a" );
	a = lua_tonumber( _s, -1 );

	DrawRectangle( 
		x - (w / 2), y - (h / 2), w, h, (Color){ r, g, b, a }
	);
	return 1;
}

#include "core.h"
#include "raylib.h"

PUBLIC int window_new( lua_State *_s );

PUBLIC CFuncs windowCFuncs[] = {
	{ window_new, "new" },
	{ NULL, NULL }
};

PUBLIC int window_new( lua_State *_s ){
	lua_Number width, height;
	width  = lua_tonumber( _s, -3 );
	height = lua_tonumber( _s, -2 );
	const char *title = lua_tostring( _s, -1 );

	printf( "Creating a window. width=%f, height=%f, title=%s\n", width, height, title );
	InitWindow( width, height, title );
	SetTargetFPS( 60 );	

	return 1;
}

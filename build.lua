gcc = require "tools/gcc"

dofile "source/meta.lua"

local outdir = "output"
local powby  = "output/poweredBy"

local raylib = gcc.cmd:new( powby,  "raylib",   gcc.shared,  gcc.ndebug )
local soul   = gcc.cmd:new( powby,  "soul",     gcc.shared,  gcc.ndebug )
local game   = gcc.cmd:new( outdir ,_Meta.name, gcc.program, _Meta.debug )

function CompileRaylib( )
	raylib.files = {
		"raylib/src/*.c"
	}
	raylib.fileDirs = { "raylib/src/external/glfw/include" }
	raylib.defines = { _Meta.glVer, "PLATFORM_DESKTOP", "_GNU_SOURCE", "PLATFORM_OS=LINUX" }

	raylib:run( )
end

function CompileSoul( )
	soul.files       = { "soul/*.c" }
	soul.fileDirs = { "raylib/src", "." }

	soul:run( )

	-- Now for the lua files >:)
end

function CompileGame( )
	game.files = {
		"source/*.c"
	}
	game.fileDirs = { ".", "soul", "raylib/src", "lua" }

	game.rpath   = "poweredBy"
	game.libDirs = { "output/poweredBy" }
	game.libs    = { "raylib", "lua", "soul", "m", "GL", "X11", "dl", "rt", "pthread" }

	game:run( game )

	-- Now for the lua files >:)
	c = "cp source/*.lua output"
	os.execute( c )

	c = "luac -o output/soul.lua soul/*.lua"
	os.execute( c )
end

function main( )
	print "Welcome to the soul engine build system!"
	print "Only implemented for Gnu/linux\n"

	CompileRaylib( )
	CompileSoul  ( )
	CompileGame  ( )
end

main( )

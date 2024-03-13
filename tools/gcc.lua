gcc = {}

gcc.program = 1
gcc.shared  = 2

gcc.ndebug = false
gcc._debug = true

gcc.cmd = {
	cc   = "gcc",
	cVer = "11",

	outDir  = ".",
	name    = "Untitled",
	buildTo = gcc.program,
	debug   = gcc.ndebug,
	rpath   = ".",

	files    = {},
	fileDirs = {},
	libs     = {},
	libDirs  = {},
	defines  = {}
}

function gcc.cmd:new( outDir, name, buildTo, debug )
	ret = {}

	for key, val in pairs(gcc.cmd) do
		ret[key] = val
	end
	ret.outDir  = outDir  or "."
	ret.name    = name    or "Untitled"
	ret.buildTo = buildTo or gcc.program
	ret.debug   = debug   or gcc.ndebug

	return ret
end

function gcc.cmd:run( )
	c = self.cc.." -std=c"..self.cVer.." -o"..self.outDir.."/"
	if     self.buildTo == gcc.program then
		c=c..       self.name..    " -Wl,-rpath="..self.rpath.." "
	elseif self.buildTo == gcc.shared  then
		c=c.."lib"..self.name..".so -shared -fPIC "
	else
		print( "Unknown buildTo value" )
		os.exit( -1 )
	end

	for _, f in pairs(self.files) do
		c=c..f.." "
	end
	for _, f in pairs(self.fileDirs) do
		c=c.."-I"..f.." "
	end
	for _, l in pairs(self.libs) do
		c=c.."-l"..l.." "
	end
	for _, l in pairs(self.libDirs) do
		c=c.."-L"..l.." "
	end
	for _, d in pairs(self.defines) do
		c=c.."-D"..d.."  "
	end

	if self.debug then
		c=c.."-D_DEBUG"
	else
		c=c.."-DNDEBUG"
	end

	print( c )
	print( "Building "..self.name.."..." )
	if os.execute( c ) == true then
		print( "  Built awesomely :3" )
	else
		print( "  Buildn't >:(" )
	end
end

return gcc

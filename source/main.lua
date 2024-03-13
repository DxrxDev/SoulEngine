_Meta = require "meta"

--startButton.bcolor = ui.Color( 140, 155, 72, 255 )

DVD = ui.newButton( "DVD", 40 )
DVD.dim = Rectangle( 0, 0, 180, 60 )
DVD.fcolor = ui.Color( 200, 200, 200, 255 )
DVD.bcolor = ui.Color( 100, 20,  150, 255 )

x = 500
y = 500
dirx = 5
diry = 5

function _start( )
	print( "loaded main successfully" )
	window.new( 1280, 720, "DemoGallery" )
end

function _physics( )
	x=x+dirx
	y=y+diry

	if (x - DVD.dim.w / 2) <= 0 or (x + DVD.dim.w / 2) >= window.width then
		dirx = dirx * -1
	end
	if (y - DVD.dim.h / 2) <= 0 or (y + DVD.dim.h / 2) >= window.height then
		diry = diry * -1
	end

	DVD.dim.x = x
	DVD.dim.y = y
end

function _draw( )
	
end

function _ui( )
	DVD:draw( )
end

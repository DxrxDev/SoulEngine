ui = {}
--[[
-- Welcome to the soul ui (lua) source file !
--
--
--    “Good times become good memories, but bad times become good lessons.”
--                                                                  - Iroh
-- I've been learning goood
-- 
--]]

--[[ COLO(U)R STUFF ]]
function ui.Color( r, g, b, a )
	ret = {}
		ret.r = r or 0
		ret.g = g or 0
		ret.b = b or 0
		ret.a = a or 255
	return ret
end
ui.white = ui.Color( 255, 255, 255, 255 )
ui.black = ui.Color( 0,   0,   0,   255 )
ui.blank = ui.Color( 0,   0,   0,   0   )

--[[ BUTTON STUFF ]]
ButtonFuncs = {}
ButtonFuncs.draw = function( self )
	ui.rectangle( self.dim, self.bcolor ) -- This is one of the only uses for the 3rd parameter.		
	ui.write( self.text, self.fs, self.dim, self.fcolor )
end

function ui.newButton( text, fontSize )
	Button = {}
		Button.__index = Button

		Button.text   = text     or "Button"
		Button.fs     = fontSize or 20
		Button.dim    = Rectangle( 0, 0, 0, 0 )
		Button.fcolor = ui.black
		Button.bcolor = ui.white

		Button.draw = ButtonFuncs.draw
	return Button
end

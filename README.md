[ bg-colour 33 33 33, ltr-colour 255 255 255 ]: #

# Soul Engine
[ stick-to-top 100% 10% ]: #

# Welcome To The Soul Engine

[]: #
This is a light-weight game engine that prioratises simplicity and code aesthetic above all else.

It uses code written in:
 - modern C for engine sided features
 - lua 5.4 for user-sided scripting and engine communicating
 - markdown (Doro's Extension) for documentation
[]: #

# Instalation / Building {#inst}
Go into the tags, and download what version youd like.

You (hopefully) downloaded a zip file containting all the files needed to make your game !

Depending on what platofrm youre building on (for example windows or linux), youll have to

run one of the provided commandline scrpits to build everything into a neat package located in `compiled_game`

The zip file should include a template `GameSettings.lua` file as well as all necessary boiler plate C & lua code.


# Dependencies

[raylib 5.0]( https://github.com/raysan5/raylib/releases/tag/5.0 )
[premake5]( https://github.com/premake/premake-core/releases/tag/v5.0.0-beta2 )
[lua 5.4.6]( https://github.com/lua/lua/releases/tag/v5.4.6 )

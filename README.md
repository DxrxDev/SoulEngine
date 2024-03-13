[ bg-colour 33 33 33, ltr-colour 255 255 255 ]: #
[ #id top stick-to-top ]: #

# Soul Engine {#top}


# Welcome To The Soul Engine {#wese}

This is a light-weight game engine that prioratises simplicity and code aesthetic above all else.

It uses code written in:
 - modern C for engine sided features
 - lua 5.4 for user-sided scripting and engine communicating
 - markdown for documentation


# Instalation / Building {#inst}

### Get The Zip

Go into the tags, and download what version youd like.

You (hopefully) downloaded a zip file containting all the files needed to make your game!

Unfortunately, the Soul Engine is only tested on linux, hopefully windows & other OS implementations will be out in the near future.

### Once Youve Extracted The Zip

Depending on what platofrm youre building on (for example windows or linux), youll have to

run one of the provided commandline scrpits to bootstrap the build process.

Alongside these scripts youll find the `source` directory, that contains a template project.

### Template Project

In the `source` directory, you will find `meta.lua`, `main.lua`, and `loader.c` which will

have all the necessary code for you to get your game up and running.

Here's what the 3 files do:
 - GameSettings.lua | This is a file containing information about your game
 - main.lua         | In [here]( #mlua ) is where the magic heppens
 - loader.c         | In here you can load your native-script modules (Coming soon)


# Build Process {#buipro}

### What Just Happened?

Well if you didnt have lua or luac programs before, now you do.

Feel free to play about with the lua command line interface but lets move along with your project.

all you have to do is call `./lua4 build.lua` to get your project compiled into a neat folder called `output`,

here you'll find your game file along with all the tools it needs.


### But Why Not Just Use Make???

To be honest, I didn't wanna :)

I wanted to experiment alternatives and stumbled on the one in use currently.

It is a build system based on pure lua with some `os.execute`s for using the compiler, luac, and copy commands

The build system `tools/gcc.lua` should technically work for any project, outside of The Soul Engine.


# Whats new !? (v0.1)

### Major

- EVERYTHING


# Dependencies {#deps}

 - [raylib 5.0]( https://github.com/raysan5/raylib/releases/tag/5.0 )
 - [lua 5.4.6](  https://github.com/lua/lua/releases/tag/v5.4.6 )


# Changes made on dependencies {#depcha}

 - [lua]    Added luac to the source code & added it to the makefile
 - [lua]    Edited the makefile to build a shared library instead of a static one

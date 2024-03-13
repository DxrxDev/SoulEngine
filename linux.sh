#! /usr/bin/sh

cd lua
make

cp ./luac     ../luac
cp ./lua      ../lua4

mv ./liblua.so ../output/poweredBy

#cp ./tools/unix-like/premake5 .

make clean
cd ..

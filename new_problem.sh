#!/usr/bin/env bash
[ -d "$(pwd)/$1" ] && { echo "ERR: Directory already exists: $(pwd)/$1"; exit 1; }
mkdir -p $1
cp ./misc/meson.build.in $1/meson.build
sed -i $([[ $OSTYPE == 'darwin'* ]] && echo ".bak") "s|@NUMBER@|'$1'|g" $1/meson.build
rm -rf $1/meson.build.bak
touch $1/$1.cc
echo "subdir('$1')" >> ./meson.build


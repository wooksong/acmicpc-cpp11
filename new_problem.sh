#!/usr/bin/env bash

mkdir -p $1
cp ./misc/meson.build.in $1/meson.build
sed -i "s|@NUMBER@|'$1'|g" $1/meson.build
touch $1/$1.cc
echo "subdir('$1')" >> ./meson.build


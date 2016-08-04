#!/bin/bash


cp ../../build/sources/$1/$1 .
cp ../../build-static/sources/$1/$1 ${1}-static
cp ../../build-cross/sources/$1/$1.exe .

md5sum --tag ${1} ${1}.exe ${1}-static > md5.txt
sha1sum --tag ${1} ${1}.exe ${1}-static > sha1.txt
sha256sum --tag ${1} ${1}.exe ${1}-static > sha256.txt
sha256sum --tag ${1} ${1}.exe ${1}-static > sha256.txt

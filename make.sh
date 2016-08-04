#!/bin/bash

cd build
make "$@"
cd ..

cd build-static
make "$@"
cd ..

cd build-cross
make "$@"
cd ..

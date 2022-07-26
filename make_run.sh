#!/bin/bash
mkdir -p build_debug
cd build_debug
cmake .. -DCMAKE_BUILD_TYPE=Debug
make
cd ..
./run_app.sh
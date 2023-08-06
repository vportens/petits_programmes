#!/usr/bin/env sh

######################################################################
# @author      : anclarma (anclarma@$HOSTNAME)
# @file        : test
# @created     : Monday May 09, 2022 00:40:28 CEST
#
# @description : 
######################################################################

mkdir build
cd build
cmake ..
cmake --build .
./main

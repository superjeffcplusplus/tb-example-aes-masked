#!/bin/bash

thisDir=$(pwd)
mainDir=$(realpath "$thisDir"/..)
libName=aes

echo "Main directory: $mainDir"

pushd "$mainDir" || exit
make clean
make -j lib_ar || { echo "Failed to build ${libName}"; exit 1; }
popd || exit

make all || { echo "Failed to build targets"; exit 1; }
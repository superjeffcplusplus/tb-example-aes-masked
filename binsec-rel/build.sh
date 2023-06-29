#!/bin/bash

thisDir=$(pwd)
mainDir=$(realpath "$thisDir"/..)
libSymDir="$thisDir"/__libsym__
libName=tinyaes_32bits

echo "Main directory: $mainDir"

pushd "$mainDir" || exit
make clean
make -j libtinyaes_32bits || { echo "Failed to build ${libName}"; exit 1; }
popd || exit

pushd "$libSymDir" || exit
make clean
make || { echo "Failed to build libsym"; exit 1; }
popd || exit

make all || { echo "Failed to build targets"; exit 1; }
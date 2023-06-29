#!/bin/bash

thisDir=$(pwd)
mainDir=$(realpath "$thisDir"/..)
libName=tinyaes

# Build library
# TODO You may either directly use the CI build of your library, or replace the `make -j all` by the command needed
# to compile you library.
pushd "$mainDir" || exit
make -j lib_so
dwarfdump -l "lib${libName}.so" >"microwalk/lib${libName}.so.dwarf"
popd || exit

echo "Main directory: $mainDir"

# Generate MAP file for library
pushd "$MAP_GENERATOR_PATH" || exit
dotnet MapFileGenerator.dll "${mainDir}/lib${libName}.so" "${thisDir}/lib${libName}".map
popd || exit

# Build targets
for target in $(find . -name "target-*.c" -print)
do
  targetName=$(basename -- "${target%.*}")

  echo "main.c $targetName.c -g -fno-inline -fno-split-stack -L $mainDir -l$libName -I $mainDir -o $targetName"
  # TODO Adjust command line to link against your library
  gcc main.c "$targetName".c -g -fno-inline -fno-split-stack -L "$mainDir" -l"$libName" -I "$mainDir" -o "$targetName"

  echo "Generating MAP file for $targetName"
  pushd "$MAP_GENERATOR_PATH" || exit
  dotnet MapFileGenerator.dll "$thisDir"/"$targetName" "$thisDir"/"$targetName".map
  popd || exit

  dwarfdump -l "$targetName" >"$targetName".dwarf
done

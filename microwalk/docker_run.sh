#! /bin/bash

make clean

docker run -it \
-v "$(pwd)"/:/mw/library \
microwalk/microwalk-pin:latest /bin/bash
#-v "$(pwd)"/microwalk/results:/mw/work \

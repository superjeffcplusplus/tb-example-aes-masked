#! /bin/bash

#docker run -it \
#-v "$(pwd)"/:/home/opam/binsec_bench \
#binsec/rel:ocaml-4.14 /bin/bash

docker run -it \
-v "$(pwd)"/:/home/binsec/binsec_bench \
 binsec/binsec:rel-2023-02-14 /bin/bash
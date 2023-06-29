#!/usr/bin/bash
#
# Run binsec on a set of binary files and check whether they enforce
# secret-erasure or if they fail to scrub secret-data from memory.
#
# All results can be found in the `log` subdirectory. By default, if results are
# found in `log`, they are not recomputed. Delete files in `log` to rerun binsec
# and recompute the results.
##
LOGDIR="./log"
BINSEC_PATH=binsec-rel

# -------- Configure which binary files to analyze
#
# Add you new scrubbing function here
aes_ecb_encrypt="aes_enc_O0"
#aes_ecb_decrypt="aes_ecb_decrypt"

#ALL_PROGRAMS="${aes_enc_O0}"
# ${aes_ecb_decrypt}

binsec relse -fml-solver-timeout 0 -relse-timeout 3600 \
    -sse-depth 0 -sse-memory ./targets/memory.txt -relse-paths 0 -sse-load-ro-sections \
    -sse-load-sections .got.plt,.data,.plt,.bss -relse-stat-prefix "${NAME}" \
    -fml-solver boolector -relse-store-type rel \
    -relse-memory-type row-map -relse-property ct -relse-dedup 1 \
    -relse-fp instr -relse-leak-info instr ./targets/${aes_ecb_encrypt}

exit 0

#binsec -relse -fml-solver-timeout 0 -relse-timeout 3600 -relse-debug-level 0 \
#       -sse-depth 0 -sse-memory src/check-password/memory.txt -relse-paths 0 \
#       -sse-load-ro-sections -sse-load-sections .got.plt,.data,.plt -relse-stat-prefix check_password_nonct_O0 \
#       -relse-stat-file ./__results__/check_password_nonct_2023-06-28.csv \
#       -fml-solver boolector -relse-store-type rel -relse-memory-type row-map \
#       -relse-property ct -relse-dedup 1 -relse-fp block -relse-leak-info instr \
#       -relse-print-model ./src/check-password/check_password_nonct_O0

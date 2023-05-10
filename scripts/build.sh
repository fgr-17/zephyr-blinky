#!/bin/bash

BOARD=nucleo_u575zi_q
./update_git_hash_on_file.sh
cd ..
west build -b $BOARD .
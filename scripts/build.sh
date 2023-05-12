#!/bin/bash

BOARD=nucleo_u575zi_q

echo "Creating git version information files..."
./update_git_hash_on_file.sh
./update_git_branch_on_file.sh
cd ..
west build -b $BOARD .
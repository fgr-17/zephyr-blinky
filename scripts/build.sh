#!/bin/bash

BOARD=nucleo_u575zi_q

if [ $# -eq 0 ]; then
  echo "No board received. Using $BOARD as default"
else
  BOARD=$1
  echo "Board: Using $BOARD"
fi


echo "Creating git version information files..."
./update_git_hash_on_file.sh
./update_git_branch_on_file.sh
cd ..
west build -b $BOARD . --pristine

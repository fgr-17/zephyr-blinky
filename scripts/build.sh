#!/bin/bash

if [ $# -eq 0 ]; then
  echo "No board received. Exiting..."
  exit 1
else
  BOARD=$1
  echo "Building firmware for board ${BOARD}"
fi

echo "Creating git version information files..."
./update_git_hash_on_file.sh
./update_git_branch_on_file.sh
cd ..
west build -b $BOARD . --pristine

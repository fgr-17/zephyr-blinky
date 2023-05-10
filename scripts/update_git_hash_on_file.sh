#!/bin/bash

APP="BLINKY"

HASH_FILE=../src/version_git_hash.h
OUTPUT=$(git rev-parse --short HEAD)

echo "Version hash: ${OUTPUT}"

echo "#ifndef ${APP}_GIT_HASH_H" > $HASH_FILE
echo "#define ${APP}_GIT_HASH_H" >> $HASH_FILE
echo -e "#define ${APP}_GIT_HASH \"${OUTPUT}\"" >> $HASH_FILE
echo "#endif" >> $HASH_FILE	
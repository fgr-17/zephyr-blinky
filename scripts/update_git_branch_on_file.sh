#!/bin/bash

APP="BLINKY"

HASH_FILE=../src/version_git_branch.h
BRANCH=$(git rev-parse --abbrev-ref HEAD)

echo "Version branch: ${BRANCH}"

echo "#ifndef ${APP}_GIT_BRANCH_H" > $HASH_FILE
echo "#define ${APP}_GIT_BRANCH_H" >> $HASH_FILE
echo -e "#define ${APP}_GIT_BRANCH \"${BRANCH}\"" >> $HASH_FILE
echo "#endif" >> $HASH_FILE	


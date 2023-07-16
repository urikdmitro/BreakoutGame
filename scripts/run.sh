#! /bin/bash

SCRIPT_PATH="${BASH_SOURCE:-$0}"
SCRIPT_DIRECTORY="$(dirname "${SCRIPT_PATH}")"

cd ${SCRIPT_DIRECTORY}/..

build/Breakout_Game


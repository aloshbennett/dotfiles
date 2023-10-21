#!/bin/sh
if [ $# -eq 0 ]; then "${SHELL: -sh}"; else "$@"; fi
read line

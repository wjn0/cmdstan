#!/bin/bash

usage() {
    echo "$0 <git-hash-1> <git-hash-2> '<extra args for runPerformanceTests.py>''"
}

checkout() {
    git checkout "$1"
    git submodule update --recursive
    dirty=$(git status --porcelain)
    if [ "$dirty" != "" ]; then
        echo "ERROR: Git repo isn't clean - I'd recommend you make a separate recursive clone of CmdStan for this."
        exit
    fi
}

checkout "$1"
./runPerformanceTests.py -j8 --runj 5 --overwrite-golds $3

checkout "$2"
./runPerformanceTests.py -j8 --runj 5 --check-golds-exact 1e-8 $3

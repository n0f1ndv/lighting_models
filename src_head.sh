#!/bin/bash

# Simple script that creates source and header file

USAGE_MESSAGE="Usage:
./src_head <file_name>
DO NOT PROVIDE ANY EXTENSIONS TO THE <file_name>"

FILE_EXISTS_MESSAGE="File already exists. Aborting..."

if (( $# != 1)); then
    echo "$USAGE_MESSAGE"
    exit 1
elif [ -e src/$1.cpp ] || [ -e src/$1.hpp ]; then
    echo "$FILE_EXISTS_MESSAGE"
    exit 1
else
    exec `touch src/$1.cpp include/$1.hpp`

    echo "#pragma once" > include/$1.hpp
    echo "#include \"$1.hpp\"" > src/$1.cpp
    
    echo "Created src/$1.cpp include/$1.hpp files."
fi

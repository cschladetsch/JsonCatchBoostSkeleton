#!/bin/sh

if [ -e build ]; then
	exit 0
fi

mkdir -p build && cd build && cmake .. && echo "--- Build files generated"


#!/bin/sh

buildDir="$HOME/local/repos/Skeleton/build/"

# Create the build directory if it doesn't exist
mkdir -p "$buildDir"

# Change to the build directory
cd "$buildDir" || exit

# Check if the first argument is "c"
if [ "$1" = "c" ]; then
	# Remove all files and directories in the current directory
	rm -rf ./*
fi

# Run cmake and ninja
cmake -G Ninja .. && ninja

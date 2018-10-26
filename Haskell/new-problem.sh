#!/usr/bin/env bash

declare -r number=$(printf "%03i" $1)
declare -r dir="euler${number}"

usage () {
  echo "${BASH_SOURCE[0]} problem-number"
  exit 1
}

fail () {
  echo "File system operation failed. Directory '$dir/' may be corrupt."
  exit 1
}

create () {
  local -r filename="$1"
  sed -e "s/XXX/${number}/g" "template/$filename" > "$dir/$filename" || fail
}

[[ "$number" == "000" ]] && usage

if [[ -e "$dir" ]]; then
  echo "ERROR: '$dir' already exists."
  exit 1
fi

# toplevel
mkdir "$dir" || fail

# app/
mkdir "$dir/app" || fail

# app/Main.hs
create "app/Main.hs"

# eulerXXX.cabal
create "eulerXXX.cabal"
mv "$dir/eulerXXX.cabal" "$dir/euler${number}.cabal" || fail

# package.yaml
create "package.yaml"

# README.md
create "README.md"

# Setup.hs
create "Setup.hs"

# src/
mkdir "$dir/src/" || fail

# src/EulerXXX.hs
create "src/EulerXXX.hs"
mv "$dir/src/EulerXXX.hs" "$dir/src/Euler${number}.hs" || fail

# stack.yaml
create "stack.yaml"

# test/
mkdir "$dir/test/" || fail
create "test/EulerXXXTest.hs"
mv "$dir/test/EulerXXXTest.hs" "$dir/test/Euler${number}Test.hs" || fail

# DONE!
echo "Problem ${number} created successfully!"

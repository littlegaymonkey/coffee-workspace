#!/bin/bash

files=(
  random5000 random10000 random50000
  reversed5000 reversed10000 reversed50000
  sorted5000 sorted1000 sorted50000
)

sorts=(sort1 sort2 sort3)

for s in "${sorts[@]}"; do
  for f in "${files[@]}"; do
    result=$( (time ./$s ${f}.txt) 2>&1 | awk '/real/ {print $2}' )
    echo "$s ${f}.txt real $result"
  done
done

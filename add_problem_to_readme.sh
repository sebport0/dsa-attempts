#!/bin/bash

name=$1
lang=$2
source=$3

if [ "${source,,}" == "leetcode" ]; then
  link=$(echo "$name" | sed 's/^[0-9]*\. //')
  link=${link// /-}
  link="https://leetcode.com/problems/$(echo "$link" | tr "[:upper:]" "[:lower:]")"
  code_path=${name//". "/_}
  code_path=$(echo "$code_path" | tr " " "_" | tr "[:upper:]" "[:lower:]")
  code_path="/leetcode/$code_path"
fi
echo "| [$name]($link) | [$lang]($code_path) | $source |" >> README.md

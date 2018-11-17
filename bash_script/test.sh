#!/bin/bash

cmdlist=( "mkdir hello" "cd hello" "mkdir 123" "ls -al")

count=${#cmdlist[*]}

for ((i=0;i<$count;i++)); do
	${cmdlist[$i]}
done

echo "done"

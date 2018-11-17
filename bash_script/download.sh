#!/bin/bash

count=0

while read cmd; do
	cmdlist[$count]=`echo $cmd`
	${cmdlist[$count]}
	count=$((count+1))
done < cmd.txt

#count=${#cmdlist[*]}

#for ((i=0;i<$count;i++)); do
#	${cmdlist[$i]}
#done

echo "done"


#! /bin/bash
for f in $(find temp -name '*.c' -or -name '*.h' -type f)
do
 #astyle --style=ansi --indent=spaces=4 -M80  -p  -D -H -c -w -n $f
	astyle --style=ansi -bps4 -M80 -w $f
done

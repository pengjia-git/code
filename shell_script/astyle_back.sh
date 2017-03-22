#! /bin/bash
for f in $(find temp -name '*.c' -or -name '*.h' -type f)
do
 astyle --style=ansi --indent=spaces=4 -M80  -p   -H -c -w -n $f
done

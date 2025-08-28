find . -name "*.c" > tmp/all_c_files.txt
# find drivers -type f -name "*.c" > tmp/all_c_files.txt
#find . -path ./scripts -prune -o -print -name "*..c" > tmp/all_c_files.txt
find . -name "*.o" > tmp/all_obj_files.txt
./a.out

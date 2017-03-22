#awk program
BEGIN {FS=","}
$5 !~ /MA/ {print $1 " " $6}


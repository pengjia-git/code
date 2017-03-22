#output format:data,commit
BEGIN{FS="\n"; RS=""}
{
    if(NF == 3)
	print $3,$1
}

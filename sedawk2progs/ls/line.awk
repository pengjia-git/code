BEGIN{
    sum=0
}
{
	sum+=$1
}
END{
	print sum
}


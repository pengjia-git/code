FILENAME == "acronyms"{
    n=split($0,entry,"\t")
    #printf "n=%d\n",n
    #print entry[1],"; ",entry[2]
    acro[entry[1]]=entry[2]
    next
}

/[A-Z][A-Z]*/{
    for(i=1;i<NF;i++){
	if($i in acro)
	    $i=acro[$i] "("$i")"
    }
    #print $0
}
{
    print $0
}

BEGIN{count=0;pre=0;cur=0;sum=0}
$3 ~ /frame=/{
    #print $3
    pos=index($3,"=")
    if(pos == 0){
	print "index error"
	next
    }
   
    cur=substr($3,pos+1)
    if(count == 0){
	pre=cur
    }

    if((cur+0) < (pre+0)){
	print "waning" cur " " pre
	pre=cur
	next
   }
    sum+=cur-pre
    pre=cur
    count++
}

END{ printf "count=%d,sum=%d,ave=%f\n",count,sum,sum/count}

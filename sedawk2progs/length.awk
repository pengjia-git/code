BEGIN{sum=0;}
$4 ~/actual_len/{
    print $4
    pos=index($4,"=")
    len=substr($4,pos+1)
#    print len
    sum+=len
}
END {printf "sum=%d,sum=%fM\n",sum,sum/1024/1024}

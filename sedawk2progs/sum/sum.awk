BEGIN{FS="=";sum=0}
/len=/{
    #print $2
    cur=$2+0
    sum+=cur
}

END{
    print sum
    print sum/1024/1024
}

BEGIN{
    pos=index("Mississippi","is")
    printf "pos=%d\n",pos

    str=substr("Mississippi",5)
    printf "str=%s\n",str
}

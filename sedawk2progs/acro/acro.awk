BEGIN{
FS="\t"
}
$0 ~ word{
    print $2
}

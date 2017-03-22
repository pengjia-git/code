{
    if(NF != 0){
	tar=substr($1,1,1)
	other=substr($1,2)
	up=toupper(tar);
	$1=up other
    }
    print $0
}

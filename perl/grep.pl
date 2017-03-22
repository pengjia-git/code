if (!open GREP ,"<","1.txt"){
    warn "open file fail$!"
}

if (!open RESULT ,">","log"){
    warn "open file fail$!"
}
while(<GREP>){
    chomp();
    print RESULT "$1\n" if /(MID_S.*?,)/;
}
print "Please Enter key to end\n";
<STDIN>;

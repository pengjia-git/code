%char_hash={};
if (!open GREP ,"<:encoding(UCS-2LE)","strtable.txt"){
    warn "open file fail$!"
}

if (!open RESULT ,">","log.txt"){
    warn "open file fail$!"
}
while(<GREP>){
    if (/lang 1 /){
	    my @chars =split //,$_;
	    foreach $char (@chars){
		$char_hash{$char}="1";
	    }
    }
  
}
my @char_key =sort keys %char_hash;
print RESULT "@char_key\n";

if (!open GREP ,"<:encoding(UTF-8)","12.txt"){
    warn "open file fail$!"
}

if (!open RESULT ,">","√ª”–∆¥“Ù.txt"){
    warn "open file fail$!"
}

if (!open RESULT1 ,">","”–∆¥“Ù.txt"){
    warn "open file fail$!"
}
$i=0;
%char_h={};
while(<GREP>){
    chomp();
    @chars =split(/\)/,$_);
    foreach $char (@chars){
	$char_h{$char}=$char;
    }
}

while ( (my $key,my $value) = each %char_h){
    #print RESULT1 "$key";
    if($i == 0){
	$line++;
	print RESULT "$line";
	print RESULT1 "$line";
    }
    $i++;
    my @hanzi=split(/\(/,$key);
    print RESULT "@hanzi[0](        )";
    print RESULT1 "$key";
    if($i == 8){
	$i=0;
	print RESULT "\n";
	print RESULT1 "\n"
    }
}


print "Please Enter key to end\n";
<STDIN>;

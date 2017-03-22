my @files = glob '*';

foreach $file (@files){

    if( $file =~ /DYN/){
	#print "$file\n";
#DYN_APK_DOG_SOURTH_JID.jpg
#dog_direction_east.jpg
	my $new_file =$file;
	$new_file =~ s/DYN_APK_DOG_DIRECTION(.*)_JID/dog_direction\1/;
	$new_file =lc($new_file);
	#print "$new_file\n";
	rename $file,$new_file || warn "$!\n"
    }
}

<STDIN>;

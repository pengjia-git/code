use File::Find;
my @files;
#�ҳ���ǰĿ¼�������ļ�
my $path = './';
sub wanted {
    #print "$File::Find::name\n";
    push(@files ,$File::Find::name);
}

find( \&wanted, $path );

#my @files = glob '*';

chomp(my $something=<STDIN>);
#����
#print "$something @files";
foreach $file (@files){
    if( !open(FILE,'<',$file)){
	#warn "open $file error:$!\n";
	next;
    }
    my $line_number=0;
    while(<FILE>){
	$line_number++;
	if(/$something/){
	    printf "%-3d\t$file\t$_",$line_number;
	}
    }
    #print "$line_number";
}

<STDIN>;

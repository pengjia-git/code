use strict;
#use 5.010001;

chomp( my $name = <STDIN>);

print "find fred in $name" if $name ~~ /fred/;

print "Please Enter key to end\n";
<STDIN>;

#!/usr/bin/perl -w
#$a='aligned = 11.8424277753889 (426327399914 frames)';
#$a=~/(.*)=(.*)\((.*)/;
#print $2; 
my $path="pick.pl";
open (LOG,"<$path")
    or die "open file fail $!\n";

while( $line = <LOG>){
    print $line;
}
my $a='CPU:   0% usr  15% sys   0% nic  84% idle   0% io   0% irq   0% sirq';
    $a=~/([0-9][0-9])% idle/;
print $1;

use strict;

my %score =("barney" => 195,"fred" => 205, "dino" =>30);

#while ( (my $key,my $value) = each %score){
#    print "$key,$value\n";
#}
my @winers =sort by_score keys %score;

sub by_score{
    $score{$b} <=> $score{$a};
}

#print "@winers\n";
foreach (@winers){
    print "$_\n";
}

print "Press Enter to close.\n";
my $jia=<STDIN>;

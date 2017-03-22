#! /usr/bin/perl
use File::Path;
$rm_folder="shoule_be_delted1";

rmtree ($rm_folder,1,1) || die "$!\n";

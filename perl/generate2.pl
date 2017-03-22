use File::Copy;
copy( $original, $new_copy ) or die "Copy failed: $!";

if (!open GREP ,"<","1.txt"){
    warn "open file fail$!"
}

if (!open RESULT ,">","log"){
    warn "open file fail$!"
}

my @keys=(VOL,REAL_TRAFFIC,ALARM_MODE,RADA_MUTE);
#my $pre="MID_ITEM_EDOG_";
#my $suf=",";
#foreach my $key (@keys){
#    print RESULT"{ $pre$key$suf";
#    print RESULT"\"edog $key\",";
#    print RESULT"P_EDOG_${key}_MBID |MTP_MULTILANG, MFG_NULL,\n";
#    print RESULT"SETID_EDOG_${key}, ";
#    $key=lc($key);
#    print RESULT"apk_edog_${key}_subitems },";
#    print RESULT"\n";
#}

#my $pre="MID_ITEM_EDOG_";
#my $suf=",";
#print RESULT "#ifdef ENABLE_APK_EDOG_MENU\n";
#foreach my $key (@keys){
#
#    print RESULT"SETID_EDOG_${key}, ";
#    print RESULT"\n";
#}
#print RESULT "#endif";

#print RESULT "#ifdef ENABLE_APK_EDOG_MENU\n";
#foreach my $key (@keys){
#    print RESULT "static TMenuSubItem ";
#    $key=lc($key);
#    print RESULT"apk_edog_${key}_subitems";
#    print RESULT "[] =\n{\n\n";
#    print RESULT "{ MID_ITEM_MAX, \"\", 0 }\n};";
#    print RESULT"\n";
#}
#print RESULT "#endif";

print RESULT "#ifdef ENABLE_APK_EDOG_MENU\n";
foreach my $key (@keys){
    print RESULT "static TMenuSubItem ";
    print RESULT"\n";
}
print RESULT "#endif";

foreach my $key (0,20,30,40,50,60,80,100,1200){
print RESULT "    { MID_SUBITEM_EDOG_RADA_MUTE_${key}, \"${key}\", P_EDOG_RADA_MUTE_${key}_MBID | MTP_MULTILANG },\n";
}
print "Please Enter key to end\n";
<STDIN>;

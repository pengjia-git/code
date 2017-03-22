use strict;

#Ҫ��ѹ�����ĵ�
my $files_to_tar='20150403';
unless ( -e $files_to_tar){
    warn "no $files_to_tar\n";
}

#��ȡʱ��
my($sec,$min,$hour,$mday,$mon,$year,$wday,$yday,$isdst) = localtime(time()); 
$year+=1900;
$mon+=1;
my $format_time=sprintf("%4d%02d%02d",$year,$mon,$mday);
print "$format_time\n";

#������
my $tar_file_name="$format_time-$files_to_tar.7z";
my $i=0;
while(-e $tar_file_name){
    $i++;
    $tar_file_name="$format_time-$i-$files_to_tar.7z";
    print "$i\n";
}

#��ȷѹ��ʱ����0������ʱ������ֵ;���������Զ��˳��Ի����Ը����ʵ���ʾ��
if(system "7z a $tar_file_name $files_to_tar -mmt=2 -bd"){
    print "Error\n";
    print "Press \'ENTER\'to exit\n";
    <STDIN>;
}


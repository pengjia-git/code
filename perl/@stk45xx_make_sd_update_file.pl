use File::Path;
use Cwd;
$rm_folder="sd_update_file";
rmtree ($rm_folder,1,1); 

#system('CALL @stk45xx_make_sd_update_file.bat');
#system('@ECHO off');
system('RD sd_update_file /s /q');
system('MD sd_update_file');
#my $cur_dir = getcwd;
#print "$cur_dir\n";

unless (-e "BootScrip.srb"){
    system('DscMaker -chip:STK45XX -gsrb -insr:stk45xx_script.srl');
}
system('COPY BootScrip.srb sd_update_file\stkarmfw.srb');
system('COPY bindata_menu6.dat sd_update_file\stkarmfw.dat');
system('COPY stkarm.bin sd_update_file\stkarmfw.bin');
#system('del BootScrip.srb');
#<STDIN>;

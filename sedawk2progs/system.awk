#测试awk--system命令的使用
BEGIN{
    if(system("mkdir temp") != 0)
	print "mkdir temp fail"
}
END{
    system("rmdir temp")
}

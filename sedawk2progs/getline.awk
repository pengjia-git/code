#测试awk--getline函数
BEGIN{
    "whoami"|getline own
    print own
}

/*
研究用extern “C” 包括后用g++编译的区别。
没有加extern “C”
1.g++ -c -o extern.o extern.cc 
2.
[jia@localhost c]$ readelf -s extern.o|grep 'add'
     8: 0000000000000000    20 FUNC    GLOBAL DEFAULT    1 _Z3addii

加extern "C"之后
1.g++ -c -o extern.o extern.cc 
[jia@localhost c]$ readelf -s extern.o|grep 'add'
     8: 0000000000000000    20 FUNC    GLOBAL DEFAULT    1 add
*/
extern "C"{
int add(int a,int b)
{

    return a+b;
}
}
.section .data  
hi:
	.rept 0x100000
	.long 3
	.endr
hello_str:  
	.byte 'h'
	.byte '\n'
  
.section .text  
.global _start  
_start:  
    // write(1, hello_str, 13)  
    mov x0, #1         // 文件描述符（stdout）  
    ldr x1, =hello_str // 字符串地址  
    //adr x1,hello_str
    mov x2, #13        // 字符串长度  
    mov x8, #64        // 系统调用号（SYS_write 在 Linux 上是 64）  
    svc #0             // 触发系统调用  
  
    // exit(0)  
    mov x0, #0         // 退出码  
    mov x8, #93        // 系统调用号（SYS_exit 在 Linux 上是 93）  
    svc #0             // 触发系统调用

#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";

SEC("fentry/hello_timer_callback")
int BPF_PROG(hello_timer_callback)
{
    bpf_printk("timer monitor pengjia");
    return 0;
}


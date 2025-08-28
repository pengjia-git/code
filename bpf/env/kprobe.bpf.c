#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>

char LICENSE[] SEC("license") = "Dual BSD/GPL";

SEC("kprobe/hello_timer_callback")
int BPF_KPROBE(hello_timer_callback)
{
    bpf_printk("pengjia timer callback probe");
    return 0;
}

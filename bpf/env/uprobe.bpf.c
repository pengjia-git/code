#include "vmlinux.h"
#include <bpf/bpf_helpers.h>
#include <bpf/bpf_tracing.h>
#include <bpf/bpf_core_read.h>

struct func_stats {
    __u64 start_time;
    __u64 total_time;
    __u64 count;
};

struct {
    __uint(type, BPF_MAP_TYPE_HASH);
    __uint(max_entries, 1024);
    __type(key, __u64);
    __type(value, struct func_stats);
} function_times SEC(".maps");

SEC("uprobe//home/pengjia/work/code/bpf/env/a.out:busy_work")
int BPF_PROG(trace_func_start)
{
    __u64 pid_tgid = bpf_get_current_pid_tgid();
    __u64 start_time = bpf_ktime_get_ns();

    struct func_stats init_val = {};
    bpf_map_update_elem(&function_times, &pid_tgid, &init_val, BPF_ANY);
    
    struct func_stats *stats = bpf_map_lookup_elem(&function_times, &pid_tgid);
    if (stats) {
        stats->start_time = start_time;
    }
    
    bpf_printk("trace start");
    return 0;
}

SEC("uprobe//home/pengjia/work/code/bpf/env/a.out:busy_work")
int BPF_PROG(trace_func_end)
{
    __u64 pid_tgid = bpf_get_current_pid_tgid();
    __u64 end_time = bpf_ktime_get_ns();

    struct func_stats *stats = bpf_map_lookup_elem(&function_times, &pid_tgid);
    if (stats) {
        stats->total_time += end_time - stats->start_time;
        stats->count += 1;
    }

    bpf_printk("trace end");
    return 0;
}

char LICENSE[] SEC("license") = "Dual BSD/GPL";


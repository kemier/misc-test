#include <linux/bpf.h>
#include <linux/ptrace.h>
#include <linux/sched.h>
#include <linux/version.h>
#include <uapi/linux/ptrace.h>

struct key_t {
    u64 ip;
    u64 pid;
};

struct val_t {
    u64 size;
};

BPF_HASH(counts, struct key_t, struct val_t);

int trace_alloc(struct pt_regs *ctx) {
    struct key_t key = {};
    struct val_t zero = {}, *val;

    key.ip = PT_REGS_IP(ctx);
    key.pid = bpf_get_current_pid_tgid();

    val = counts.lookup_or_init(&key, &zero);
    val->size += PT_REGS_RC(ctx);

    return 0;
}

int trace_free(struct pt_regs *ctx) {
    struct key_t key = {};
    struct val_t *val;

    key.ip = PT_REGS_IP(ctx);
    key.pid = bpf_get_current_pid_tgid();

    val = counts.lookup(&key);
    if (val) {
        val->size -= PT_REGS_RC(ctx);
        if (val->size == 0) {
            counts.delete(&key);
        }
    }

    return 0;
}
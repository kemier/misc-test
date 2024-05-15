from bcc import BPF

# BPF program code
bpf_code = """
#include <uapi/linux/ptrace.h>

BPF_HASH(allocations, u64);

int trace_alloc(struct pt_regs *ctx) {
    u64 addr = PT_REGS_RC(ctx);
    u64 zero = 0;

    // Store the allocation address in the hash table
    allocations.update(&addr, &zero);

    return 0;
}

int trace_free(struct pt_regs *ctx) {
    u64 addr = PT_REGS_RC(ctx);

    // Remove the allocation address from the hash table
    allocations.delete(&addr);

    return 0;
}
"""

# Load the BPF program
bpf = BPF(text=bpf_code)

# Attach the BPF program to the appropriate tracepoints
bpf.attach_uprobe(name="/usr/lib/libc.so.6", sym="malloc", fn_name="trace_alloc")
bpf.attach_uprobe(name="/usr/lib/libc.so.6", sym="free", fn_name="trace_free")

# Print memory leak detection results
print("Memory Leak Detection Tool")
print("--------------------------")
print("Monitoring memory allocations and deallocations...")
print()

# Start the BPF program's event loop
try:
    bpf.trace_print()
except KeyboardInterrupt:
    pass
# minikernel

a kernel for openmini, running on openmini's apis and providing banked memory and scheduling

need:
	syscalls
	multiple processes
	ipc
	dynamic linking (...sort of)
	executable loader (could use ELF, but that seems inefficient)
	executable builder

how to implement syscalls:
	- syscalls reside in flash
	- syscall finder (aka `syscallf(int)`) finds syscall from id and returns ptr to syscall function
	- flash should be readonly in user mode, probably also in kernel mode
	- binaries should begin with `int (*main)(void *(*syscallf)(int), int argc, char **argv)` (relative ptr to main function taking syscallf, argc, and argv as arguments)


need MMU level protection of kernel memory, limit reads and writes to kernel code
riscv supports this
need to figure out how to use it
flash memory readable, but only writable by kernel code
each process has at least 256 KiB ram
swap to flash or microsd card...
microsd card preferred, maybe microsd card used as ram expansion?
	- very tempting
	- needs a second socket
	- needs a secure latching mechanism
alternatively, could use DIP sram chip and DIP-to-sd converter board?
	- seems redundant
	- probably only use one type
	- found 64 Mb psram for $1.80 https://www.digikey.com/en/products/detail/adafruit-industries-llc/4677/13148775
	- 256 KiB native process memory
	- 128 KiB banked memory in second half?
		- no, it would be better to just give the process a way to load from its executable and let it manage the weirdness
		- still leaves the problem of dynamically allocated ram
			- 64 KiB memory using faults to dynamically map memory?
				- NOPE
			- reimplement stdlibc++ to use manually paged memory?
				- difficult but possible
			
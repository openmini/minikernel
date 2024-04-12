# minikernel

a kernel for openmini, running on openmini's apis and providing banked memory and scheduling

need:
	system to load modules
	syscalls
	executable loader
	executable builder

how do we implement syscalls...
jump to *(*x)? sure, but that seems risky
do_syscall(syscall,args) should theoretically work but it needs a fixed size arg list
var args don't work across function address calls
but. there is a potential solution.
setup args in stack array + call addr w/ syscall number & array size
- avoids memory limitations, we can swap modules
- really difficult to pull off correctly
- dangerous
- but there's a chance. let's do this shit.

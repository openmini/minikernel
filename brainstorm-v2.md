# brainstorm v2: system startup, services, processes, etc - construction of the kernel

startup is partially modeled after linux:

- kernel gives itself a certain portion of memory
- kernel initializes structures
- kernel inits basic stuff (i.e. clocks, internal components, preparation for init process)
- kernel uses fs stub to load init into ram
- init process structure is constructed and init is given full perms
- kernel starts init process
- end startup

minikernel, as of now, has these 7 system calls:

- fork
- exec
- exit
- kill
- abort
- send
- recv
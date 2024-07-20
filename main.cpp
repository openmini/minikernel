#include <cstdio>
#include <ctime>
#include <vector>
#include "api/main.hpp"
#include "api/builtin.hpp"
struct process {
	// TBD
};

std::vector<process> processes;


void dbg(char* x) {
	static char buf[256];
	int a = snprintf(buf, 256, "[% 9.16f] %s\n", ((double) clock())/CLOCKS_PER_SEC, x);
	openmini::builtin::debug.send(buf, a);
}
void init() {
	dbg("end init()");
}
int main(void) {
	init();
}
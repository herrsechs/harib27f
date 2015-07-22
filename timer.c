#include "bootpack.h"
#include <stdio.h>

void HariMain(){
    char *buf;
    int win;
    api_initmalloc();
    buf = api_malloc(150 * 100);
	win = api_openwin(buf, 150, 100, -1, "timer");
    api_end();
}

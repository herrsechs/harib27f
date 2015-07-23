#include "apilib.h"

void HariMain(void)
{
	char *buf;
	int win, i, x, y;
	int wall[30][30];
	int ii, jj;
	for(ii = 0; ii < 30; ii++){
        for(jj = 0; jj < 30; jj++){
            wall[ii][jj] = 0;
        }
	}
	api_initmalloc();
	buf = api_malloc(300 * 300);
	win = api_openwin(buf, 300, 300, -1, "walk");
	api_boxfilwin(win, 4, 24, 295, 295, 0 /* 黒 */);
	x = 150;
	y = 150;
	api_putstrwin(win, x, y, 3 /* 黄 */, 1, "*");
	int ix, jx;
	//col1
	for(ix = 1 ; ix < 6; ix++)
    {
        for(jx = 30; jx < 290; jx += 10)
        {
            api_putstrwin(win, ix * 20, jx,  10 /* 绿 */, 1, "*");
            int wx = ix * 2, wy = jx / 10;
            wall[wx][wy] = 1;
        }
    }
    //col2
    for(ix = 1 ; ix < 6; ix++)
    {
        for(jx = 30; jx < 290; jx += 10)
        {
            api_putstrwin(win, 290-ix * 20, jx,  10 /* 绿 */, 1, "*");
            int wx = 29 - 2*ix, wy = jx / 10;
            wall[wx][wy] = 1;
        }
    }
    //row1
    for(jx = 1; jx < 5; jx++)
    {
        for(ix = 10; ix < 290; ix += 10)
        {
            api_putstrwin(win, ix, jx * 20, 10 /* 绿 */, 1, "*");
            int wx = ix / 10, wy = jx * 2;
            wall[wx][wy] = 1;
        }
    }
    //row2
    for(jx = 1; jx < 5; jx++)
    {
        for(ix = 10; ix < 290; ix += 10)
        {
            api_putstrwin(win, ix, 290-jx*20, 10 /* 绿 */, 1, "*");
            int wx = ix/10, wy = 29 - jx*2;
            wall[wx][wy] = 1;
        }
    }


	for (;;) {
		i = api_getkey(1);
		api_putstrwin(win, x, y, 0 /* 黒 */, 1, "*"); /* 黒で消す */
		if (i == '4' && x >=  10 && wall[x/10-1][y/10] == 0) { x -= 10; }
		if (i == '6' && x <= 290 && wall[x/10+1][y/10] == 0) { x += 10; }
		if (i == '8' && y >=  30 && wall[x/10][(y-10)/10] == 0) { y -= 10; }
		if (i == '2' && y <=  290 && wall[x/10][(y+10)/10] == 0) { y += 10; }
		if (i == 0x0a) { break; } /* Enterで終了 */
		api_putstrwin(win, x, y, 3 /* 黄 */, 1, "*");
	}
	api_closewin(win);
	api_end();
}

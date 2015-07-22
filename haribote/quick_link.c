#include "bootpack.h"

struct QLCTL* qlctl_init(struct MEMMAN *memman)
{
    struct QLCTL *ctl;
	ctl = (struct SHTCTL *) memman_alloc_4k(memman, sizeof (struct QLCTL));
	if (ctl == 0) {
		return ctl;
	}
	ctl->amount = 0;
    int i;
    for(i=0; i < MAX_QL; i++){
        ctl->bitmap[i] = 0;
    }
    return ctl;
}

struct QUICKLINK* quicklink_alloc(struct QLCTL* ctl)
{
    struct QUICKLINK* ql;
    int i = ctl->amount;
    for(; i < MAX_QL; i++)
    {
        if(ctl->bitmap[i] == 0){
            ctl->amount++;
            ctl->bitmap[i] = 1;
            return ctl->qls[i];
        }
    }

    return ql;
}

#ifndef SO_CTL_H_
#define SO_CTL_H_

/*
 * sophia database
 * sphia.org
 *
 * Copyright (c) Dmitry Simonenko
 * BSD License
*/

typedef struct soctl soctl;

struct soctl {
	soobj o;
	/* sophia */
	char    *path;
	/* compaction */
	uint32_t node_size;
	uint32_t node_page_size;
	uint32_t node_branch_wm;
	uint32_t node_compact_wm;
	/* scheduler */
	uint32_t threads;
	/* memory */
	uint64_t memory_limit;
	/* log */
	int      log_enable;
	char    *log_path;
	int      log_sync;
	int      log_rotate_wm;
	int      log_rotate_sync;
	int      two_phase_recover;
	int      commit_lsn;
	void *e;
};

void  so_ctlinit(soctl*, void*);
void  so_ctlfree(soctl*);
int   so_ctlvalidate(soctl*);
int   so_ctldump(soctl*, srbuf*);
void *so_ctlreturn(srctl*, void*);

#endif

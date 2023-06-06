#ifndef ADD_INTERACTIVE_H
#define ADD_INTERACTIVE_H

#include "color.h"

struct add_i_state {
	struct repository *r;
	int use_color;
	char header_color[COLOR_MAXLEN];
	char help_color[COLOR_MAXLEN];
	char prompt_color[COLOR_MAXLEN];
	char error_color[COLOR_MAXLEN];
	char reset_color[COLOR_MAXLEN];
	char fraginfo_color[COLOR_MAXLEN];
	char context_color[COLOR_MAXLEN];
	char file_old_color[COLOR_MAXLEN];
	char file_new_color[COLOR_MAXLEN];

	int use_single_key;
	char *interactive_diff_filter, *interactive_diff_algorithm;
};

void init_add_i_state(struct add_i_state *s, struct repository *r);
void clear_add_i_state(struct add_i_state *s);

struct repository;
struct pathspec;
int run_add_i(struct repository *r, const struct pathspec *ps);

enum add_p_mode {
	/*表示将文件的变更内容逐个添加到索引中。这是最常见的模式，用于交互地选择文件补丁并将其添加到索引。*/
	ADD_P_ADD,
	/* 表示将文件的变更内容存储为一个临时储藏（stash）。使用这个模式时，文件的变更内容不会添加到索引中，而是保存在储藏中，可以稍后恢复。*/
	ADD_P_STASH,
	/* 表示重置文件的变更内容。使用这个模式时，文件的变更内容将被撤销，恢复到之前的状态。*/
	ADD_P_RESET,
	/*表示从暂存区中撤销文件的变更内容并还原到工作树。使用这个模式时，文件的变更内容将从暂存区中移除，并在工作树中还原到之前的状态。*/
	ADD_P_CHECKOUT,
	/*表示直接修改工作树中的文件而不通过索引。使用这个模式时，文件的变更内容会直接修改工作树中的文件，而不会影响索引*/
	ADD_P_WORKTREE,
};

int run_add_p(struct repository *r, enum add_p_mode mode,
	      const char *revision, const struct pathspec *ps);

#endif

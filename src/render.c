#include "game_state.h"
#include <ncurses.h>
#include <locale.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

void render(game_state_t *gs_ptr) {
	//setlocale(LC_ALL, "");
	clear();
	int r, c;
	char temp[] = "x";
	for(r = 0; r < gs_ptr->num_rows; r++) {
		int curr_c;
		for(c = 0, curr_c = 0; c < gs_ptr->num_cols; c++, curr_c += 2) {
			temp[0] = gs_ptr->grid[r][c];
			if(temp[0] == 'X') {
				mvprintw(r, curr_c, "X");
				mvprintw(r, curr_c + 1, "X");
			} else {
				mvprintw(r, curr_c, temp);
				mvprintw(r, curr_c + 1, " ");
			}
			refresh();
		}
	}
}

int render_main() {
	game_state_t* test = (game_state_t*)malloc(sizeof(game_state_t));
	test->num_rows = 16, test->num_cols = 16;
	test->grid = (char**)malloc(sizeof(char*) * 3);
	int i;
	for(i = 0; i < 3; i++) {
		test->grid[i] = (char*)malloc(sizeof(char) * 3);
		int j;
		for(j = 0; j < 3;j ++) {
			test->grid[i][j] = 'X';
		}
	}
	render(test);
	return 0;
}
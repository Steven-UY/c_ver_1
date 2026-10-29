#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define W 50
#define H 30

//2d arr?
int state[H][W] = {0};
int next[H][W] = {0};

//rendering in the 0s
void render(void){
    for (size_t j = 0; j < H; j++){
        for (size_t i = 0; i < W; i++){
            if (!state[j][i])
                printf("%c", ' '); //means char type
            else
                printf("%d", state[j][i]); //means decimal type
        }
        printf("\n");
    }
}

void init(void){
    state[10][10] = 1;
    memcpy(next, state, sizeof(int) * W * H);
}

const int moves[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},           {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};


void update(void){
    for (size_t j = 0; j < H; j++){
        for (size_t i = 0; i < W; i++){
            if(state[j][i]){
                const int *move = moves[rand() % 2];
                int nj = j + move[0];
                int ni = i + move[1];

                if (nj >= 0 && nj < H && ni >= 0 && ni < W){
                    next[nj][ni] = 1;
                    next[nj][ni] = 1;
                }
            }
        }
    }
    memcpy(state, next, sizeof(int) * W * H);
}

void clear_term(void){
    usleep(500000);
    system("clear");
}

int main(void){
    srand(time(NULL));
    init();

    while (1){
        clear_term();
        render();
        update();
    }
    return 0;
}


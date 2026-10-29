#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define W 50
#define H 30

int state[H][W];
int next[H][W];

//with this we
void render(void){
    for (size_t j = 0; j < H; j++){
        for(size_t i = 0; i < W; i ++){
            if(!state[j][i])
                printf("%c", ' ');
            else
                printf("%d", state[j][i]);
        }
        printf("\n");
    }
}


void init(void){
    state[10][10] = 1; //initial value
    //copying the bytes from current to next state
    memcpy(next, state, sizeof(int) * W * H);
}

//structure here is for visual aid largely pretty much
const int moves[8][2] = {
    {-1, -1}, {-1, 0}, {-1, 1},
    {0, -1},         {0, 1},
    {1, -1}, {1, 0}, {1, 1}
};


void update(void){
    for (size_t j = 0; j < H; j++){
        for (size_t i = 0; i < W; i++){
            if(state[j][i]){
                const int *move = moves[rand() % 8];
                int nj = j + move[0];
                int ni = i + move[1];

                //in bounds we fill with 1
                if (nj >= 0 && nj < H && ni >= 0 && ni < W){
                    next[j][i] = 1; //empty
                    next[nj][ni]++; //moving 
                }
            }
        }
    }
    memcpy(state, next, sizeof(int) * W * H);
}


void clear_term(void){
    usleep(500000);
    system("clear"); //clear command in terminal
}

int main(void){
    srand(time(NULL));
    init();

    //infinite loop not an issue since memory is bound
    while (1){
        clear_term();
        render();
        update();
    }
    return 0;
}

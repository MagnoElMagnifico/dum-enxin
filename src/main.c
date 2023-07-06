#include <SDL2/SDL.h>
#include "game.h"

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main() {
    dum_Game game = dum_CreateGame(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (game.running) {
        dum_HandleEvents(&game);
        dum_UpdateLogic(&game);
        dum_RenderFrame(&game);
        // TODO?: wait for next frame
    }

    dum_DestroyGame(&game);
    return 0;
}

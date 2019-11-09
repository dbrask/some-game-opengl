#include "../inc/Game.h"
#include "../inc/Config.h"
#include <iostream>
#include <iterator>
#include <algorithm>

#include <GL/glut.h>

int main(int argc, char** argv) {
    Config config;
    Game game(config);
    game.init();

    return 0;
}

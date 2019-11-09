#ifndef GAME_H
#define GAME_H

class Game
{
public:
    Game();
    ~Game();

    void init();
    static void display();
    static void keyboard(unsigned char key, int x, int y);

private:
    
};

#endif // GAME_H
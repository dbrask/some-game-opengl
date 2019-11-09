#ifndef CONFIG_H_
#define CONFIG_H_

struct Config
{
    int win_x_size;
    int win_y_size;
    bool is_fullscreen = true; 
};

extern Config g_Config;

#endif // CONFIG_H
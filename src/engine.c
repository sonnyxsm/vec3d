#include "engine.h"
#include "world.h"

void v3d_create_context(int x, int y, int vsync, const char *title)
{
        if (vsync == 0) {
               SetTargetFPS(400); 
        }
        SetTargetFPS(vsync);

        InitWindow(x, y, title);
}

int v3d_mainthread(void)
{
        scene_t s1;
        scene_create(&s1);
        
        for (;;) {
                scene_update(&s1);
                scene_draw(&s1); 
        }

        CloseWindow();
        return 0;
}

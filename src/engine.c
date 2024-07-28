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
        /* testing... move some logic out of here at some point */

        scene_t s1;
        scene_create(&s1);
        scene_camera(&s1, (Vector3){0.f, 10.f, 10.f}, (Vector3){0.f, 0.f, 0.f}, 1.f, 90.f);

        for (;;) {
                scene_update(&s1);
                scene_draw(&s1); 
        }

        CloseWindow();
        return 0;
}

#include "world.h"

void ent_create(entity_t *e, const char *modelpath, Vector3 position, Vector3 rotation, Vector3 scale)
{
        e->i = 0;

        e->worldmodel = modelpath;

        e->health = 100.f;
        e->anim.state = 0;
        e->anim.i = 0;
        e->anim.frame = 0;

        e->pos = position;
        e->rot = rotation;
        e->modelscale = scale;
        e->angle = 0.f; 

        e->i++;

        if (modelpath == "") {
                /* do something... this is bad */
        }

        e->model = LoadModel(e->worldmodel);
        e->anim.control = LoadModelAnimations(e->worldmodel, &e->anim.state);
}

void ent_set_anim(entity_t *e, int action)
{
        e->anim.i = action;
}

void ent_update(entity_t *e)
{
        e->matrot = MatrixRotate(e->rot, DEG2RAD * e->angle);
        e->direction = Vector3Transform((Vector3){0.0f, 0.0f, 1.0f}, e->matrot);
        e->anim.anim = e->anim.control[e->anim.i];
        e->anim.frame = (e->anim.frame + 1)%e->anim.anim.frameCount;

        UpdateModelAnimation(e->model, e->anim.anim, e->anim.frame); 
}

void scene_create(scene_t *s)
{
        int maxents = 512; 
        for (int i = 0; i < maxents; i++) {
                
        }
}

void scene_update(scene_t *s)
{

}

void scene_draw(scene_t *s)
{
        BeginDrawing();
        ClearBackground(BLACK);

        EndDrawing();
}


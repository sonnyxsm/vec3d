#include "world.h"

void ent_create(entity_t *e, const char *modelpath, Vector3 position, Vector3 rotation, Vector3 scale)
{
        e->worldmodel = modelpath;

        e->health = 100.f;
        e->anim.state = 0;
        e->anim.i = 0;
        e->anim.frame = 0;

        e->pos = position;
        e->rot = rotation;
        e->modelscale = scale;
        e->angle = 0.f; 

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

void ent_draw(entity_t *e)
{
       DrawModelEx(e->model, e->pos, e->rot, e->angle, e->modelscale, WHITE); 
}

void ent_teleport(entity_t *e, Vector3 position)
{
        e->pos.x = position.x;
        e->pos.y = position.y;
        e->pos.z = position.z;
}

void scene_camera(scene_t *s, Vector3 position, Vector3 rotation, float up, float fov)
{
        s->camera.position = position;
        s->camera.target = rotation;
        s->camera.up = (Vector3){0.0f, up, 0.0f};
        s->camera.fovy = fov;
}

void scene_create(scene_t *s)
{
        for (int i = 0; i < 5; i++) {
               ent_create(&s->entitylist[i], "1.glb", ENT_DEFAULT_POS, ENT_DEFAULT_ROT, ENT_DEFAULT_MS);
        }
}

void scene_update(scene_t *s)
{
        for (int i = 0; i < 5; i++) {
                ent_update(&s->entitylist[i]);
        }
}

void scene_draw(scene_t *s)
{
        BeginDrawing();
        ClearBackground(BLACK);
        BeginMode3D(s->camera); 
        
        for (int i = 0; i < 5; i++) {
                ent_draw(&s->entitylist[i]);
        }
        
        ent_set_anim(&s->entitylist[0], 3);
        ent_set_anim(&s->entitylist[1], 2);
        ent_teleport(&s->entitylist[0], (Vector3){4.f, 0.f, 0.f});
        DrawGrid(100, 10.f);

        EndMode3D();
        EndDrawing();
}


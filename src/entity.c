#include "entity.h"

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

void ent_fire_anim(entity_t *e, int action)
{

}

void ent_update(entity_t *e)
{
        e->matrot = MatrixRotate(e->rot, DEG2RAD * e->angle);
	e->direction = Vector3Transform((Vector3){ 0.0f, 0.0f, 1.0f }, e->matrot);
        
        e->anim.anim = e->anim.control[e->anim.i];
        e->anim.frame = (e->anim.frame + 1) % e->anim.anim.frameCount;

        UpdateModelAnimation(e->model, e->anim.anim, e->anim.frame); 
}

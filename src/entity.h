#include <raylib.h>
#include <raymath.h>

typedef struct {
        ModelAnimation *control;
        ModelAnimation anim;
        int state;
        unsigned int i;
        unsigned int frame;
} anim_t; 

typedef struct {
        const char *worldmodel;

        Model model;
        Mesh collide;
        anim_t anim;

        Matrix matrot;
        Vector3 pos, rot;
        Vector3 modelscale;
        Vector3 direction;
        float angle;

        float health;
        int i;
} entity_t;

void ent_create(entity_t *, const char *, Vector3, Vector3, Vector3);
void ent_set_anim(entity_t *, int);
void ent_update(entity_t *);

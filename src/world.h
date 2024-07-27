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

typedef struct {
        Model model;
} map_t;

typedef struct {
        map_t level;
        Camera camera;

        entity_t entitylist[512];

        int i;
} scene_t;

void ent_create(entity_t *, const char *, Vector3, Vector3, Vector3);
void ent_set_anim(entity_t *, int);
void ent_update(entity_t *);

void scene_create(scene_t *);
void scene_update(scene_t *);
void scene_draw(scene_t *);

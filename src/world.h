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

} entity_t;

typedef struct {
        Model model;
} map_t;

#define ENT_DEFAULT_POS         (Vector3){0.f, 1.f, 0.f}
#define ENT_DEFAULT_ROT         (Vector3){0.f, 1.f, 0.f}
#define ENT_DEFAULT_MS          (Vector3){10.f, 10.f, 10.f}
#define SCENE_MAX_CAPACITY      2048

typedef struct {
        map_t level;
        Camera camera;
        
        entity_t entitylist[SCENE_MAX_CAPACITY];

        int i;
} scene_t;

void ent_create(entity_t *, const char *, Vector3, Vector3, Vector3);
void ent_set_anim(entity_t *, int);
void ent_update(entity_t *);
void ent_draw(entity_t *);
void ent_moveto(entity_t *, Vector3);

void scene_camera(scene_t *, Vector3, Vector3, float, float);
void scene_create(scene_t *);
void scene_update(scene_t *);
void scene_draw(scene_t *);

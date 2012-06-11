#ifndef SKETCH_H_INCLUDED
#define SKETCH_H_INCLUDED

#include <glib.h>

typedef struct _Sketch {
  GHashTable *nodes;
} Sketch;

Sketch *sketch_create();
void sketch_free(Sketch *sketch);
void sketch_destroy(Sketch **sketch);

int sketch_get_nb_nodes(Sketch *sketch);

#endif/*SKETCH_H_INCLUDED*/

#ifndef SKETCH_H_INCLUDED
#define SKETCH_H_INCLUDED

#include <glib.h>

#include "transform.h"

typedef struct _Sketch {
  GHashTable *nodes;
  GHashTable *modules;
} Sketch;

typedef struct _SketchModule {
  const char *name;
  void *dl_handle;
  NodeTransform transform;
} SketchModule;

Sketch *sketch_create();
void sketch_free(Sketch *sketch);
void sketch_destroy(Sketch **sketch);

int sketch_get_nb_nodes(Sketch *sketch);
SketchModule *sketch_get_module(Sketch *sketch, const char *name);

gboolean sketch_add_modules_from_path(Sketch *sketch, const char *path);
gboolean sketch_add_module(Sketch *sketch, const char *filename);
void module_free(SketchModule *module);

#endif/*SKETCH_H_INCLUDED*/

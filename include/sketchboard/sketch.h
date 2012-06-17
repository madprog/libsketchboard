#ifndef SKETCH_H_INCLUDED
#define SKETCH_H_INCLUDED

#include <glib.h>

#include "transform.h"

typedef struct _Sketch {
  GHashTable *nodes;
  GHashTable *modules;
} Sketch;

typedef const char *(*DocGetter)(int index);

typedef struct _SketchModule {
  const char *name;
  void *dl_handle;
  int min_inputs;
  int max_inputs;
  int min_outputs;
  int max_outputs;

  NodeTransform transform;
  DocGetter get_doc_input;
  DocGetter get_doc_output;
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

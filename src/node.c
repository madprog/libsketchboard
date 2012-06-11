#include <glib.h>

#include "sketchboard/node.h"

SketchNode *node_create(Sketch *sketch) {
  SketchNode *node = g_malloc(sizeof(SketchNode));

  return node;
}

void node_free(SketchNode *node) {
  g_free(node);
}

void node_destroy(Sketch *sketch, SketchNode **node) {
  node_free(*node);
  *node = NULL;
}

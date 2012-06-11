#include <assert.h>
#include <glib.h>

#include "sketchboard/node.h"

SketchNode *node_create(Sketch *sketch) {
  assert(sketch != NULL);

  SketchNode *node = g_malloc(sizeof(SketchNode));

  node->id = 0;
  while(g_hash_table_contains(sketch->nodes, &(node->id))) {
    node->id ++;
  }
  g_hash_table_insert(sketch->nodes, &(node->id), node);

  return node;
}

void node_free(SketchNode *node) {
  assert(node != NULL);

  g_free(node);
}

void node_destroy(Sketch *sketch, SketchNode **node) {
  assert(sketch != NULL);
  assert(node != NULL);
  assert(*node != NULL);

  g_hash_table_remove(sketch->nodes, &((*node)->id));

  *node = NULL;
}

#include <glib.h>
#include <string.h>

#include "sketchboard/sketch.h"
#include "sketchboard/node.h"

Sketch *sketch_create() {
  Sketch *sketch = g_malloc(sizeof(Sketch));

  sketch->nodes = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, (GDestroyNotify)node_free);

  return sketch;
}

void sketch_free(Sketch *sketch) {
  g_hash_table_destroy(sketch->nodes);
  g_free(sketch);
}

void sketch_destroy(Sketch **sketch) {
  sketch_free(*sketch);
  *sketch = NULL;
}

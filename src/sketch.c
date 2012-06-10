#include <glib.h>
#include <string.h>

#include "sketchboard/sketch.h"
#include "sketchboard/node.h"

Sketch *sketch_create() {
  Sketch *sketch = g_malloc(sizeof(Sketch));

  return sketch;
}

void sketch_free(Sketch *sketch) {
  g_free(sketch);
}

void sketch_destroy(Sketch **sketch) {
  sketch_free(*sketch);
  *sketch = NULL;
}

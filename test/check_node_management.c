#include <sketchboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Sketch *sketch;
  SketchNode *node;

  sketch = sketch_create();

  /* Check that the created node is returned by node_create */
  node = node_create(sketch);
  if(node == NULL) {
    fprintf(stderr, "node_create returned NULL\n");
    exit(1);
  }

  node_destroy(sketch, &node);
  if(node != NULL) {
    fprintf(stderr, "node is not NULL after being destroyed\n");
    exit(1);
  }

  sketch_destroy(&sketch);

  exit(0);
}

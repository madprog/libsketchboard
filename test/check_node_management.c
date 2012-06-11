#include <sketchboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Sketch *sketch;
  SketchNode *node;
  int n;

  sketch = sketch_create();

  /* Check that there is no node in the sketch */
  n = sketch_get_nb_nodes(sketch);
  if(n != 0) {
    fprintf(stderr, "sketch_get_nb_nodes returned %d instead of 0\n", n);
    exit(1);
  }

  /* Check that the created node is returned by node_create */
  node = node_create(sketch);
  if(node == NULL) {
    fprintf(stderr, "node_create returned NULL\n");
    exit(1);
  }

  /* Check that there is one node in the sketch */
  n = sketch_get_nb_nodes(sketch);
  if(n != 1) {
    fprintf(stderr, "sketch_get_nb_nodes returned %d instead of 1\n", n);
    exit(1);
  }

  node_destroy(sketch, &node);
  if(node != NULL) {
    fprintf(stderr, "node is not NULL after being destroyed\n");
    exit(1);
  }

  /* Check that there is no node in the sketch */
  n = sketch_get_nb_nodes(sketch);
  if(n != 0) {
    fprintf(stderr, "sketch_get_nb_nodes returned %d instead of 0\n", n);
    exit(1);
  }

  sketch_destroy(&sketch);

  exit(0);
}

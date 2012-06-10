#include <sketchboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Sketch *sketch;

  /* Check that the created sketch is returned by sketch_create */
  sketch = sketch_create();
  if(sketch == NULL) {
    fprintf(stderr, "sketch_create returned NULL\n");
    exit(1);
  }

  sketch_destroy(&sketch);
  if(sketch != NULL) {
    fprintf(stderr, "sketch is not NULL after being destroyed\n");
    exit(1);
  }

  exit(0);
}

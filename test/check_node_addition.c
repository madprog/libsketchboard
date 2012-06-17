#include <assert.h>
#include <glib.h>
#include <math.h>
#include <sketchboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Sketch *sketch;
  SketchNode *node1;

  sketch = sketch_create();

  node1 = node_create_instance(sketch, "addition");

  node_set_input_number(node1, 0, 4);
  node_set_input_number(node1, 1, -3);
  node_set_input_number(node1, 2, 5);

  GArray *node1_output = node_get_output(node1);

  if(node1_output == NULL) {
    fprintf(stderr, "node_get_output returned NULL\n");
    exit(1);
  }

  if(node1_output->len != 1) {
    fprintf(stderr, "node_get_output returned %d elements instead of 1\n", node1_output->len);
    exit(1);
  }

  {
    SketchValue *node1_output_1 = &g_array_index(node1_output, SketchValue, 0);

    if(node1_output_1->type != SKETCH_VALUE_NUMBER) {
      fprintf(stderr, "node_get_output didn't return a number (type code: %d)\n", node1_output_1->type);
      exit(1);
    }

    if(fabs(node1_output_1->value.number - 6) > 1e-7) {
      fprintf(stderr, "node_get_output returned %f instead of 6\n", node1_output_1->value.number);
      exit(1);
    }
  }

  g_array_free(node1_output, TRUE);

  node_destroy(sketch, &node1);
  sketch_destroy(&sketch);

  exit(0);
}

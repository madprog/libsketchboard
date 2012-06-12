#include <assert.h>
#include <glib.h>
#include <math.h>
#include <sketchboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

GArray *node1_transform(SketchNode *node, GArray *inputs) {
  GArray *ret;
  SketchValue val;

  assert(inputs != NULL);
  if(inputs->len == 2
      && g_array_index(inputs, SketchValue, 0).type == SKETCH_VALUE_NUMBER
      && g_array_index(inputs, SketchValue, 1).type == SKETCH_VALUE_NUMBER) {
    val.type = SKETCH_VALUE_NUMBER;
    val.value.number = g_array_index(inputs, SketchValue, 0).value.number + g_array_index(inputs, SketchValue, 1).value.number;
  } else {
    if(inputs->len != 2) fprintf(stderr, "node1_transform is in error because it has %d inputs\n", inputs->len);
    else if(g_array_index(inputs, SketchValue, 0).type != SKETCH_VALUE_NUMBER) fprintf(stderr, "node1_transform is in error because input 0 is of type %d\n", g_array_index(inputs, SketchValue, 0).type);
    else if(g_array_index(inputs, SketchValue, 1).type != SKETCH_VALUE_NUMBER) fprintf(stderr, "node1_transform is in error because input 1 is of type %d\n", g_array_index(inputs, SketchValue, 1).type);
    val.type = SKETCH_VALUE_ERROR;
  }

  ret = g_array_new(FALSE, TRUE, sizeof(SketchValue));
  g_array_set_size(ret, 1);
  g_array_index(ret, SketchValue, 0) = val;

  return ret;
}

GArray *node2_transform(SketchNode *node, GArray *inputs) {
  GArray *ret;
  SketchValue val;

  assert(inputs != NULL);
  if(inputs->len == 2
      && g_array_index(inputs, SketchValue, 0).type == SKETCH_VALUE_NUMBER
      && g_array_index(inputs, SketchValue, 1).type == SKETCH_VALUE_NUMBER) {
    val.type = SKETCH_VALUE_NUMBER;
    val.value.number = g_array_index(inputs, SketchValue, 0).value.number * g_array_index(inputs, SketchValue, 1).value.number;
  } else {
    if(inputs->len != 2) fprintf(stderr, "node2_transform is in error because it has %d inputs\n", inputs->len);
    else if(g_array_index(inputs, SketchValue, 0).type != SKETCH_VALUE_NUMBER) fprintf(stderr, "node2_transform is in error because input 0 is of type %d\n", g_array_index(inputs, SketchValue, 0).type);
    else if(g_array_index(inputs, SketchValue, 1).type != SKETCH_VALUE_NUMBER) fprintf(stderr, "node2_transform is in error because input 1 is of type %d\n", g_array_index(inputs, SketchValue, 1).type);
    val.type = SKETCH_VALUE_ERROR;
  }

  ret = g_array_new(FALSE, TRUE, sizeof(SketchValue));
  g_array_set_size(ret, 1);
  g_array_index(ret, SketchValue, 0) = val;

  return ret;
}

int main() {
  Sketch *sketch;
  SketchNode *node1, *node2;

  sketch = sketch_create();

  /* Compute 4 + 3 */
  node1 = node_create(sketch);

  node_set_input_number(node1, 0, 4);
  node_set_input_number(node1, 1, 3);
  node_set_transformation(node1, node1_transform);

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

    if(fabs(node1_output_1->value.number - 7) > 1e-7) {
      fprintf(stderr, "node_get_output didn't returned %f instead of 7\n", node1_output_1->value.number);
      exit(1);
    }
  }

  g_array_free(node1_output, TRUE);

  /* Compute (4 + 2) * 5 */
  node2 = node_create(sketch);

  node_set_input_number(node1, 1, 2);

  node_set_input_node(node2, 0, node1, 0);
  node_set_input_number(node2, 1, 5);
  node_set_transformation(node2, node2_transform);

  GArray *node2_output = node_get_output(node2);

  if(node2_output == NULL) {
    fprintf(stderr, "node_get_output returned NULL\n");
    exit(1);
  }

  if(node2_output->len != 1) {
    fprintf(stderr, "node_get_output returned %d elements instead of 1\n", node2_output->len);
    exit(1);
  }

  {
    SketchValue *node2_output_1 = &g_array_index(node2_output, SketchValue, 0);

    if(node2_output_1->type != SKETCH_VALUE_NUMBER) {
      fprintf(stderr, "node_get_output didn't return a number (type code: %d)\n", node2_output_1->type);
      exit(1);
    }

    if(fabs(node2_output_1->value.number - 30) > 1e-7) {
      fprintf(stderr, "node_get_output didn't returned %f instead of 30\n", node2_output_1->value.number);
      exit(1);
    }
  }

  g_array_free(node2_output, TRUE);

  node_destroy(sketch, &node2);
  node_destroy(sketch, &node1);
  sketch_destroy(&sketch);

  exit(0);
}

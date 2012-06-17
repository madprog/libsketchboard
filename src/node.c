#include <assert.h>
#include <glib.h>

#include "sketchboard.h"

SketchNode *node_create(Sketch *sketch) {
  assert(sketch != NULL);

  SketchNode *node = g_malloc(sizeof(SketchNode));

  node->id = 0;
  while(g_hash_table_contains(sketch->nodes, &(node->id))) {
    node->id ++;
  }
  node->inputs = g_array_new(FALSE, TRUE, sizeof(SketchValue));
  g_hash_table_insert(sketch->nodes, &(node->id), node);

  return node;
}

static GArray *transform_error(SketchNode *node, GArray *inputs) {
  GArray *ret = g_array_new(FALSE, TRUE, sizeof(SketchValue));

  g_array_set_size(ret, 1);
  g_array_index(ret, SketchValue, 0).type = SKETCH_VALUE_ERROR;

  return ret;
}

SketchNode *node_create_instance(Sketch *sketch, const char *name) {
  assert(sketch != NULL);
  assert(name != NULL);

  SketchNode *node;
  SketchModule *module;

  module = sketch_get_module(sketch, name);

  node = node_create(sketch);
  if(module != NULL && module->transform != NULL) {
    node->transform = module->transform;
  } else {
    node->transform = transform_error;
  }

  return node;
}

void node_free(SketchNode *node) {
  assert(node != NULL);

  g_array_free(node->inputs, TRUE);
  g_free(node);
}

void node_destroy(Sketch *sketch, SketchNode **node) {
  assert(sketch != NULL);
  assert(node != NULL);
  assert(*node != NULL);

  g_hash_table_remove(sketch->nodes, &((*node)->id));

  *node = NULL;
}

void node_set_input_number(SketchNode *node, int position, double value) {
  SketchValue *val;

  if(node->inputs->len <= position) {
    g_array_set_size(node->inputs, position + 1);
  }

  val = &g_array_index(node->inputs, SketchValue, position);

  val->type = SKETCH_VALUE_NUMBER;
  val->value.number = value;
}

void node_set_input_node(SketchNode *node, int position, SketchNode *value, int index) {
  SketchValue *val;

  if(node->inputs->len <= position) {
    g_array_set_size(node->inputs, position + 1);
  }

  val = &g_array_index(node->inputs, SketchValue, position);

  val->type = SKETCH_VALUE_NODE;
  val->value.node_output.node = value;
  val->value.node_output.index = index;
}

void node_set_transformation(SketchNode *node, NodeTransform transform) {
  node->transform = transform;
}

GArray *node_get_output(SketchNode *node) {
  GArray *inputs, *ret;

  inputs = g_array_new(FALSE, TRUE, sizeof(SketchValue));
  g_array_set_size(inputs, node->inputs->len);

  /* Get each input value into inputs array */
  for(int i = 0; i < node->inputs->len; ++ i) {
    SketchValue val = g_array_index(node->inputs, SketchValue, i);

    /* If the input is from a node, or if a node returned a node, compute its value */
    while(val.type == SKETCH_VALUE_NODE) {
      GArray *sub_ret = node_get_output(val.value.node_output.node);
      assert(sub_ret != NULL);

      if(sub_ret->len > val.value.node_output.index) {
        val = g_array_index(sub_ret, SketchValue, val.value.node_output.index);
      } else {
        val.type = SKETCH_VALUE_ERROR;
      }

      g_array_free(sub_ret, TRUE);
    }

    /* Here val should be a scalar value */
    g_array_index(inputs, SketchValue, i) = val;
  }

  /* Call the transformation */
  ret = node->transform(node, inputs);
  assert(ret != NULL);

  g_array_free(inputs, TRUE);

  return ret;
}

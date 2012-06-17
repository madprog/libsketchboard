#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "sketch.h"
#include "transform.h"
#include "value.h"

typedef struct _SketchNode {
  int id;
  GArray *inputs;
  NodeTransform transform;
} SketchNode;

SketchNode *node_create(Sketch *sketch);
SketchNode *node_create_instance(Sketch *sketch, const char *name);
void node_free(SketchNode *node);
void node_destroy(Sketch *sketch, SketchNode **node);

void node_set_input_number(SketchNode *node, int position, double value);
void node_set_input_node(SketchNode *node, int position, SketchNode *value, int index);
void node_set_transformation(SketchNode *node, NodeTransform transform);

GArray *node_get_output(SketchNode *node);

#endif/*NODE_H_INCLUDED*/

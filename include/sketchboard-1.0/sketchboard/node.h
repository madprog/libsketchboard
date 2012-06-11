#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "sketch.h"

typedef struct _SketchNode {
  int id;
} SketchNode;

SketchNode *node_create(Sketch *sketch);
void node_free(SketchNode *node);
void node_destroy(Sketch *sketch, SketchNode **node);

#endif/*NODE_H_INCLUDED*/

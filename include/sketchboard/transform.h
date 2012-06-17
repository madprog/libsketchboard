#ifndef TRANSFORM_H_INCLUDED
#define TRANSFORM_H_INCLUDED

#include <glib.h>

struct _SketchNode;

typedef GArray *(*NodeTransform)(struct _SketchNode *node, GArray *inputs);

#endif/*TRANSFORM_H_INCLUDED*/

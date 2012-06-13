#ifndef VALUE_H_INCLUDED
#define VALUE_H_INCLUDED

#define SKETCH_VALUE_ERROR  0
#define SKETCH_VALUE_NUMBER 1
#define SKETCH_VALUE_NODE   2

typedef struct _SketchValue {
  int type;
  union {
    double number;
    struct {
      struct _SketchNode *node;
      int index;
    } node_output;
  } value;
} SketchValue;

#endif/*VALUE_H_INCLUDED*/

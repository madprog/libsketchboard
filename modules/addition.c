#include <assert.h>
#include <glib.h>
#include <sketchboard.h>

const int nb_outputs = 1;
const char *name = "addition";

GArray *transform(SketchNode *node, GArray *inputs) {
  GArray *ret;
  SketchValue *val;

  ret = g_array_new(FALSE, TRUE, sizeof(SketchValue));
  g_array_set_size(ret, 1);
  val = &g_array_index(ret, SketchValue, 0);

  assert(inputs != NULL);
  val->type = SKETCH_VALUE_NUMBER;
  val->value.number = 0;
  for(int i = 0; i < inputs->len; ++i) {
    if(g_array_index(inputs, SketchValue, i).type != SKETCH_VALUE_NUMBER) {
      val->type = SKETCH_VALUE_ERROR;
      return ret;
    }
    val->value.number += g_array_index(inputs, SketchValue, i).value.number;
  }

  return ret;
}

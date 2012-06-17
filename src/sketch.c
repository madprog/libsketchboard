#include <assert.h>
#include <dlfcn.h>
#include <glib.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "sketchboard.h"

Sketch *sketch_create() {
  Sketch *sketch;
  char *modules_path;

  sketch = g_malloc(sizeof(Sketch));

  sketch->nodes = g_hash_table_new_full(g_int_hash, g_int_equal, NULL, (GDestroyNotify)node_free);
  sketch->modules = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify)module_free);

  modules_path = getenv("SKETCHBOARD_MODULES_PATH");
  if(modules_path == NULL) {
    modules_path = DEFAULT_MODULES_PATH;
  }

  sketch_add_modules_from_path(sketch, modules_path);

  return sketch;
}

void sketch_free(Sketch *sketch) {
  assert(sketch != NULL);

  g_hash_table_destroy(sketch->nodes);
  g_hash_table_destroy(sketch->modules);

  g_free(sketch);
}

void sketch_destroy(Sketch **sketch) {
  assert(sketch != NULL);
  assert(*sketch != NULL);

  sketch_free(*sketch);
  *sketch = NULL;
}

int sketch_get_nb_nodes(Sketch *sketch) {
  assert(sketch != NULL);

  return g_hash_table_size(sketch->nodes);
}

SketchModule *sketch_get_module(Sketch *sketch, const char *name) {
  assert(sketch != NULL);
  assert(name != NULL);

  SketchModule *ret = g_hash_table_lookup(sketch->modules, name);

  return ret;
}

gboolean sketch_add_modules_from_path(Sketch *sketch, const char *path) {
  GError *error = NULL;
  GDir *dir;
  char module_path[_POSIX_PATH_MAX];

  dir = g_dir_open(path, 0, &error);
  if(dir != NULL) {
    const gchar *filename;
    while((filename = g_dir_read_name(dir)) != NULL) {
      if(g_str_has_suffix(filename, MODULE_EXT)) {
        snprintf(module_path, sizeof(module_path), "%s/%s", path, filename);
        if(!sketch_add_module(sketch, module_path)) {
          return FALSE;
        }
      }
    }
    g_dir_close(dir);
    return TRUE;
  } else {
    fprintf(stderr, "Unable to read modules path: %s\n", error->message);
    g_error_free(error);
    return FALSE;
  }
}

gboolean sketch_add_module(Sketch *sketch, const char *filename) {
  void *dl_handle;
  const char *error;
  char **name;
  NodeTransform transform;
  SketchModule *module;

  dl_handle = dlopen(filename, RTLD_LAZY | RTLD_LOCAL);
  if(dl_handle == NULL) {
    fprintf(stderr, "Failed loading module '%s': %s\n", filename, dlerror());
    return FALSE;
  }

  dlerror(); /* Clear any previous error */
  transform = dlsym(dl_handle, "transform");
  error = dlerror();
  if(error != NULL) {
    fprintf(stderr, "Failed loading symbol '%s::transform': %s\n", filename, error);
    dlclose(dl_handle);
    return FALSE;
  }

  dlerror(); /* Clear any previous error */
  name = dlsym(dl_handle, "name");
  error = dlerror();
  if(error != NULL) {
    fprintf(stderr, "Failed loading symbol '%s::name': %s\n", filename, error);
    dlclose(dl_handle);
    return FALSE;
  }
  if(name == NULL || *name == NULL) {
    fprintf(stderr, "Failed loading symbol '%s::name': should not be NULL.\n", filename);
    dlclose(dl_handle);
    return FALSE;
  }

  module = g_malloc(sizeof(SketchModule));
  module->dl_handle = dl_handle;
  module->name = *name;
  module->transform = transform;
  g_hash_table_insert(sketch->modules, *name, module);

  return TRUE;
}

void module_free(SketchModule *module) {
  dlclose(module->dl_handle);
}

/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#pragma once

#include <glib-object.h>

G_BEGIN_DECLS

#define G_TYPE_HELLO                            \
  (g_hello_get_type())
#define G_HELLO(obj)                                            \
  (G_TYPE_CHECK_INSTANCE_CAST((obj), G_TYPE_HELLO, GHello))
#define G_HELLO_CLASS(klass)                                    \
  (G_TYPE_CHECK_CLASS_CAST((klass), G_TYPE_HELLO, GHelloClass))
#define G_IS_HELLO(obj)                                 \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj), G_TYPE_HELLO))
#define G_IS_HELLO_CLASS(klass)                         \
  (G_TYPE_CHECK_CLASS_TYPE((klass), G_TYPE_HELLO))
#define G_HELLO_GET_CLASS(obj)                                  \
  (G_TYPE_INSTANCE_GET_CLASS((obj), G_TYPE_HELLO, GHelloClass))

typedef struct _GHello         GHello;
typedef struct _GHelloClass    GHelloClass;

/**
 * GHello:
 *
 * A GHello.
 */
struct _GHello
{
    /*< private >*/
    GObject parent_instance;
};

struct _GHelloClass
{
    GObjectClass parent_class;
};

GType          g_hello_get_type (void) G_GNUC_CONST;
GHello        *g_hello_new      (void);
const gchar   *g_hello_greet    (GHello *hello);

G_END_DECLS

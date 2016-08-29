/* -*- Mode: C; indent-tabs-mode: nil; c-basic-offset: 4 -*- */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <hello.h>

#include "ghello.h"

/**
* SECTION: hello
* @short_description: A hello.
*
* The #GHello is a hello class.
*/

#define G_HELLO_GET_PRIVATE(obj)                               \
    (G_TYPE_INSTANCE_GET_PRIVATE((obj),                        \
                                 G_TYPE_HELLO,                 \
                                 GHelloPrivate))
typedef struct _GHelloPrivate
{
    Hello *hello;
} GHelloPrivate;

G_DEFINE_TYPE(GHello, g_hello, G_TYPE_OBJECT)

static void
g_hello_init(GHello *hello)
{
    GHelloPrivate *priv;

    priv = G_HELLO_GET_PRIVATE(hello);
    priv->hello = hello_new();
}

static void
dispose (GObject *object)
{
    GHello *hello;
    GHelloPrivate *priv;

    hello = G_HELLO(object);
    priv = G_HELLO_GET_PRIVATE(hello);

    if (priv->hello) {
        hello_free(priv->hello);
        priv->hello = NULL;
    }

    G_OBJECT_CLASS(g_hello_parent_class)->dispose(object);
}

static void
g_hello_class_init(GHelloClass *klass)
{
    GObjectClass *gobject_class;

    gobject_class = G_OBJECT_CLASS(klass);
    gobject_class->dispose = dispose;
    g_type_class_add_private(gobject_class, sizeof(GHelloPrivate));
}

/**
 * g_hello_new:
 *
 * Allocates a new #GHello.
 *
 * Returns: a new #GHello.
 */
GHello *
g_hello_new(void)
{
    GHello *hello;
    hello = g_object_new(G_TYPE_HELLO, NULL);
    return hello;
}

/**
 * g_hello_message:
 * @hello: A #GHello.
 *
 * Message.
 *
 * Returns: Hello message.
 */
const gchar *
g_hello_message(GHello *hello)
{
    GHelloPrivate *priv;

    priv = G_HELLO_GET_PRIVATE(hello);
    return hello_message(priv->hello);
}

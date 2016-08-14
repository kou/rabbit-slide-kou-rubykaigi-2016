#include <ruby.h>

#include <hello.h>

static void
rb_hello_free(void *data)
{
  Hello *hello = data;
  hello_free(hello);
}

static const rb_data_type_t rb_hello_type = {
  "Hello",
  {
    NULL,
    rb_hello_free,
    NULL,
  },
  NULL,
  NULL,
  RUBY_TYPED_FREE_IMMEDIATELY,
};

static VALUE
rb_hello_alloc(VALUE klass)
{
  return TypedData_Wrap_Struct(klass, &rb_hello_type, NULL);
}

static VALUE
rb_hello_initialize(VALUE self)
{
  Hello *hello;
  hello = hello_new();
  DATA_PTR(self) = hello;
  return Qnil;
}

static VALUE
rb_hello_message(VALUE self)
{
  Hello *hello;
  const char *message;

  TypedData_Get_Struct(self, Hello, &rb_hello_type, hello);
  message = hello_message(hello);

  return rb_str_new_cstr(message);
}

void
Init_hello(void)
{
  VALUE hello;

  hello = rb_define_class("Hello", rb_cData);
  rb_define_alloc_func(hello, rb_hello_alloc);
  rb_define_method(hello, "initialize", rb_hello_initialize, 0);
  rb_define_method(hello, "message", rb_hello_message, 0);
}

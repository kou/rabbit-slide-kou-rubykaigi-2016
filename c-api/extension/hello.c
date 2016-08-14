#include <ruby.h>

static VALUE
hello_to_s(VALUE self)
{
  return rb_str_new_cstr("Hello");
}

void
Init_hello(void)
{
  VALUE hello;

  hello = rb_define_class("Hello", rb_cObject);
  rb_define_method(hello, "to_s", hello_to_s, 0);
}

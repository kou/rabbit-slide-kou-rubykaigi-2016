#include <ruby.h>

#include <calc.h>

static VALUE
calc_s_add(VALUE self, VALUE rb_x, VALUE rb_y)
{
  return INT2NUM(calc_add(NUM2INT(rb_x), NUM2INT(rb_y)));
}

void
Init_calc(void)
{
  VALUE calc;

  calc = rb_define_module("Calc");
  rb_define_singleton_method(calc, "add", calc_s_add, 2);
}

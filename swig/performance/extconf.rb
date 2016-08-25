require "mkmf"

dir_config("libcalc")
have_header("calc.h")
have_library("calc", "calc_add")

create_makefile("calc")

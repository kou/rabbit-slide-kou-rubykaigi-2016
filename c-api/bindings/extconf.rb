require "mkmf"

dir_config("libhello")
exit(false) unless have_header("hello.h")
exit(false) unless have_library("hello", "hello_new")

create_makefile("hello")

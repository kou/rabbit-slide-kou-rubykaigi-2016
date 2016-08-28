require "mkmf"

dir_config("libhello")
have_header("hello.h")
have_library("hello", "hello_new")

create_makefile("hello")

require "mkmf"

include_dir, library_dir = dir_config("libhello")
exit(false) unless have_header("hello.h")
exit(false) unless have_library("hello", "hello_new")

$srcs = ["hello_wrap.c"]
$cleanfiles << "hello_wrap.c"

create_makefile("hello")
File.open("Makefile", "a") do |makefile|
  makefile.puts(<<-MAKEFILE)
hello_wrap.c: hello.i
	swig -Wall -I"#{include_dir}" -ruby -o $@ $<
  MAKEFILE
end

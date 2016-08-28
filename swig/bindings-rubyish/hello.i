%module hello

%{
#include <hello.h>
%}

typedef struct hello_t {
  %extend {
    hello_t() {return hello_new();}
    ~hello_t() {hello_free($self);}
    const char *message() {
      return hello_message($self);
    }
  }
} Hello;

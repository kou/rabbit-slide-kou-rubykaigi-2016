#include <hello.h>

#include <stdlib.h>
#include <string.h>

struct hello_t {
  char *message;
};

Hello *
hello_new(void)
{
  Hello *hello;

  hello = malloc(sizeof(Hello));
  hello->message = strdup("Hello");

  return hello;
}

void
hello_free(Hello *hello)
{
  free(hello->message);
  free(hello);
}

const char *
hello_message(Hello *hello)
{
  return hello->message;
}


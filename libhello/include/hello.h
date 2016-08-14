#pragma once

typedef struct hello_t Hello;

Hello      *hello_new    (void);
void        hello_free   (Hello *hello);
const char *hello_message(Hello *hello);

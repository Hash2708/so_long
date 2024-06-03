#include "so_long.h"

void error_exit(const char *message) {
    write(2, "Error\n", 6);
    write(2, message, strlen(message));
    write(2, "\n", 1);
    exit(1);
}

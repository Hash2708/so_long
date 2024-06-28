#include "so_long.h"

void error_exit(const char *error_message) {
    const char *error_prefix = "Error\n";
    ssize_t ret;

    ret = write(2, error_prefix, strlen(error_prefix));
    if (ret == -1) {
        exit(1);
    }
    ret = write(2, error_message, strlen(error_message));
    if (ret == -1) {
        exit(1);
    }
    ret = write(2, "\n", 1);
    if (ret == -1) {
        exit(1);
    }
    exit(1);
}

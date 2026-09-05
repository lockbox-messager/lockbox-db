#include "socket.h"

int main() {
    int res;

    res = socket_main();
    if (res) return 1;

    // TODO: LOOP

    return 0;
}
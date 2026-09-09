#include "param.hpp"
#include "parse.hpp"

#include <cstring>

int main(int argc, char *argv[]) {
    const bool debug = argc > 1 && std::strcmp(argv[1], "-Debug") == 0;
    Param params;

    (void)debug;
    (void)params;

    return 0;
}

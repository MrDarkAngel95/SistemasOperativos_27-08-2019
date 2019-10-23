#include <stdio.h>

int main() {
    for (int i = 2; i <= 100; i++) {
        fprintf(stdout, "%d\n", i);
    }
    fprintf(stdout, "%d\n", -1);
}
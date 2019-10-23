#include "types.h"
#include "stat.h"
#include "stdio.h"

int main(void) {

    int flag = 0;
    int num;
    int p = 1;

    for (;;) {
        scanf("%d\n", &num);
        if (num == -1) {
            fprintf(stdout, "%d\n", -1);
            break;
        } else {
            if (flag == 0) {
                flag = 1;
                p = num;
                fprintf(stderr, "%d\n", p);
            } else {
                if (num%p != 0) {
                    fprintf(stdout, "%d\n", num);
                }
            }
        }
    }
}

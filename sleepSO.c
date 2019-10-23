#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv) {
    int i;

    if(argc <= 0) {
        printf(1,"NO SLEEP TIME SPECIFIED!!!!! \n");
    } else {
        printf(1,"\n");
        sleepSO(atoi(argv[0]));
    }

    exit();
}


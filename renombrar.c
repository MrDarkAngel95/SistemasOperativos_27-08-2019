#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){
    char *file = argv[1];
    char *newName = argv[2];
    char *pwd = getcwd(NULL,0);
    char path1[strlen(file)+strlen(pwd)+2];
    char path2[strlen(newName)+strlen(pwd)+2];
    sprintf(path1,"%s/%s",pwd,file);
    sprintf(path2,"%s/%s",pwd,newName);

    int fd1 = link(path1,path2);
    int fd2 = unlink(path1);

}
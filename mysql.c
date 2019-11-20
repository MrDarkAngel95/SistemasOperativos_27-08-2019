#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct s{
    char firstName[20];
    char lastName[20];
    int prisonerId;
    char semester;
} Student;

void writeStudent(char * file) {
    int fd = open(file,O_RDONLY|O_CREAT,0666);
    for(int i = 0; i < 10; i++) {
        Student myStudent;
        sprintf(myStudent.firstName,"Juanito_%d",i);
        sprintf(myStudent.lastName,"Perez_%d",i);
        myStudent.prisonerId = (i + 1)*10;
        myStudent.semester = (i + 1);
        write(fd,&myStudent,sizeof(Student));
    }
    close(fd);
}

void readStudent(char * file, int element) {
    int fd = open(file,O_RDONLY);
    Student myStudent;
    //int element = atoi(argv[2]);
    lseek(fd,element*sizeof(Student),SEEK_SET);
    read(fd,&myStudent,sizeof(Student));
    close(fd);
    printf("Student name: %s, %s\n",myStudent.lastName,myStudent.firstName);
    printf("Id: %d, Semester: %d\n",myStudent.prisonerId,myStudent.semester);
}

int main(int argc, char **argv) {
    /*
    char * fileName = argv[1];
    int element = atoi(argv[2]);
    writeStudent(fileName);
    readStudent(fileName, element);
    */

    
    char *fileName = argv[1];
    char *lastName = argv[2];
    char *newLastName = argv[3];
    int fd = open(fileName,O_RDONLY);
    int posElement = -1;
    for(int i = 0; i < 5; i++) {
        Student myStudent;
        read(fd,&myStudent,sizeof(Student));
        if(!strcmp(myStudent.lastName, lastName)) {
            posElement = i;
            break;
        }
    }
    close(fd);
    if(posElement == -1){
        printf("Valor --%s-- no encontrado\n",lastName);
    } else {
        Student myStudent;
        int lastNameMaxSize = sizeof(myStudent.lastName);
        char * trunLastName;
        strncpy(trunLastName, newLastName, lastNameMaxSize);
        int fd = open(fileName,O_WRONLY);
        lseek(fd,posElement * sizeof(Student) + sizeof(myStudent.lastName), SEEK_SET);
        write(fd,newLastName,strlen(newLastName));
        
        close(fd);
    }

}

#include <stdio.h>
#include <stdlib.h>

void opening_stage()
{
    printf("Todo application\n================\n\nCommands:\n\n");
    printf(" -a   Adds a new task\n -wr  Write current todos to file\n -rd  Read todos from a file\n");
    printf(" -l   Lists all the tasks\n -e   Empty the list\n -r   Removes a task\n");
    printf(" -c   Completes a task\n -p   Add priority to a task\n -lp  Lists all the tasks by priority\n\n");
}

void get_command(char *command, char *buff, int *fp)
{
    for (int i = 0; i < 3; i++){
        scanf("%s", &command);
        if (command[0] == 'a'){
            scanf("%s", &buff);
            fprintf(fp, "%s\n", buff);
        }
    }
}

int main()
{
    opening_stage();

    FILE *fp;

    char command[50];
    char buff[255];

    fp = fopen("test_todo.txt", "a+");
    get_command(command, buff, fp);

    /*fgets(buff, 255, (FILE*)fp);
    printf("1: %s\n", buff );;
    fgets(buff, 255, (FILE*)fp);
    printf("2: %s\n", buff );
    */
    fclose(fp);

    return 0;
}

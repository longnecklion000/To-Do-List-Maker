#include <stdio.h>

int main() {
    int listnum;
    printf("How many to-do things do you want to add: ");
    scanf("%d", &listnum);

    getchar();

    char listname[1000];

    int fileNumber = 1;
    char filename[100]; 

    while (1) {
        snprintf(filename, sizeof(filename), "To-DoList%d.txt", fileNumber);
        FILE *file = fopen(filename, "r");
        
        if (file == NULL) {
            break;
        }
        
        fileNumber++;
        fclose(file);  
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return 1;
    }

    for (int i = 0; i < listnum; i++) {
        printf("Enter the name of the to-do thing %d: ", i + 1);
        fgets(listname, sizeof(listname), stdin);

        fprintf(file, "[%c] %s", ' ', listname);
    }

    fclose(file);

    printf("To-do list has been saved to %s\n", filename);

    return 0;
}

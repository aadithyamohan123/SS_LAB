#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 100
#define MAX_SUBDIRS 10

typedef struct Directory 
{
    char name[MAX_NAME_LEN];
    struct Directory* subDirs[MAX_SUBDIRS];
    int subDirCount;
} Directory;

Directory* createDirectory(const char* name) 
{
    Directory* newDir = (Directory*)malloc(sizeof(Directory));
    strcpy(newDir->name, name);
    newDir->subDirCount = 0;
    return newDir;
}

int isDuplicateName(Directory* parent, const char* name) 
{
    for (int i = 0; i < parent->subDirCount; i++) 
    {
        if (strcmp(parent->subDirs[i]->name, name) == 0) 
        {
            return 1; 
        }
    }
    return 0; 
}

void addSubDirectory(Directory* parent, Directory* subDir) 
{
    if (parent->subDirCount < MAX_SUBDIRS) 
    {
        if (isDuplicateName(parent, subDir->name)) 
        {
            printf("Subdirectory '%s' already exists under '%s'.\n", subDir->name, parent->name);
            free(subDir); 
        } 
        else 
        {
            parent->subDirs[parent->subDirCount++] = subDir;
            printf("Subdirectory '%s' added under '%s'.\n", subDir->name, parent->name);
        }
    } 
    else 
    {
        printf("Cannot add more subdirectories under %s. Limit reached.\n", parent->name);
    }
}

void printDirectoryStructure(Directory* dir, int level) 
{
    for (int i = 0; i < level; i++) 
    {
        printf("    ");  
    }
    printf("|-- %s\n", dir->name);
    
    for (int i = 0; i < dir->subDirCount; i++) 
    {
        printDirectoryStructure(dir->subDirs[i], level + 1);
    }
}

void freeDirectory(Directory* dir) 
{
    for (int i = 0; i < dir->subDirCount; i++) 
    {
        freeDirectory(dir->subDirs[i]);
    }
    free(dir);
}

Directory* findDirectory(Directory* root, const char* name) 
{
    if (strcmp(root->name, name) == 0) 
    {
        return root;
    }
    
    for (int i = 0; i < root->subDirCount; i++) 
    {
        Directory* result = findDirectory(root->subDirs[i], name);
        if (result != NULL) 
        {
            return result;
        }
    }
    
    return NULL;
}

int main() 
{
    Directory* root = createDirectory("root");
    char parentName[MAX_NAME_LEN], dirName[MAX_NAME_LEN];
    int choice;

    printf("Directory Structure Management\n");
    printf("1. Add a subdirectory\n");
    printf("2. Display directory structure\n");
    printf("3. Exit\n");

    while (1) 
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) 
        {
            case 1:
                printf("Enter the name of the parent directory (or 'root' for the root directory): ");
                fgets(parentName, MAX_NAME_LEN, stdin);
                parentName[strcspn(parentName, "\n")] = '\0'; 

                Directory* parentDir = findDirectory(root, parentName);
                if (parentDir == NULL) 
                {
                    printf("Parent directory not found.\n");
                    break;
                }

                printf("Enter the name of the new subdirectory: ");
                fgets(dirName, MAX_NAME_LEN, stdin);
                dirName[strcspn(dirName, "\n")] = '\0';  

                Directory* newDir = createDirectory(dirName);
                addSubDirectory(parentDir, newDir);
                break;

            case 2:
                printf("\nDirectory Structure:\n");
                printDirectoryStructure(root, 0);
                break;

            case 3:
                freeDirectory(root);
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

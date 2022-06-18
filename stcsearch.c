#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* find_file(char* short_filename, char* curr_path) {
    DIR *dir;
    dir = opendir(curr_path);
    if (!dir) return NULL;

    struct dirent *dir_e;
    while ((dir_e = readdir(dir)) != NULL) {
        char* full_dir_e = malloc(sizeof(curr_path) + sizeof(dir_e->d_name));
        strcpy(full_dir_e, curr_path);
        strcat(full_dir_e, dir_e->d_name);
        strcat(full_dir_e, "/");
        if (!strcmp(dir_e->d_name, ".") || !strcmp(dir_e->d_name, "..")) {
            free(full_dir_e);
            continue;
        }
        if (dir_e->d_type == 4) {
            find_file(short_filename, full_dir_e);
        } else {
            if (!strcmp(dir_e->d_name, short_filename))
                printf("%s%s\n", curr_path, dir_e->d_name);
        }
        free(full_dir_e);
    }
    closedir(dir);
    return curr_path;
}
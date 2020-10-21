#include <unistd.h>
#include <libgen.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include "sys/types.h"

int main(){
    struct dirent *dp;
    char path[1000];
    
    DIR *dirp = opendir("./tmp/");
    if (dirp == NULL) {
        return (228);
    }
    
    while ((dp = readdir(dirp)) != NULL) {
        if (dp) {
            memset(path, 0, sizeof(path));
            strcat(path, "./tmp/");
            strcat(path, dp->d_name);
            struct stat st;
    
            if ((stat(path, &st) == 0) && (st.st_nlink == 2)) {
                // We need to use cmd here
                fflush(stdout);
                
                char cmd[70];
                sprintf(cmd, "find ~ -inum %lu", st.st_ino);
                system(cmd);
                
                fflush(stdout);
            }
        }
    }
    
    (void) closedir(dirp);
    
    return 0;
}

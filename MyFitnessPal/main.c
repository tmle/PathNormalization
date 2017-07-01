//
//  main.c
//  MyFitnessPal
//
//  Created by Thinh Le on 2017-06-30.
//  Copyright © 2017 Lac Viet Inc. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define kTestString1 "foo/./bar"
#define kTestString2 "foo/bar/../baz"
#define kTestString3 "../foo/bar"
#define kTestString4 "../foo/bar/./foo/../bar"
#define kTestString5 "./foo/bar/./foo/../bar"

void removeDot1(char path[]) {
    // this algorithm has two passes.
    int i;
    int pathLen = (int)strlen(path);
    char newPath[pathLen];
    printf("path = %s\n", path);
    
    // the first pass is to remove the dot(s).
    int j = 0;
    for (i = 0; i < pathLen; i++) {
        if (path[i] != '.') {
            newPath[j] = path[i];
            j++;
        }
    }
    newPath[j] = '\0'; // end the string with a null character
    
    // the second pass is to check for // and remove one of them.
    j = 0;
    int newPathLen = (int)strlen(newPath);
    for (i = 0; i<newPathLen; i++) {
        if ((newPath[i] == '/') && (newPath[i+1] == '/')) {
        } else {
            path[j] = newPath[i];
            j++;
        }
    }
    path[j] = newPath[i];
    path[j++] = '\0'; // end the string with a null character
    
    printf("newPath using removeDot1 = %s\n", path); // path is reused the second time.
    
}

void removeDot2(char path[]) {
    // this algorithm has only one pass
    int i;
    int pathLen = (int)strlen(path);
    char newPath[pathLen];
    //printf("path    = %s\n", path);
    
    // it checks for patterns: './' and '../, removes the dot(s) accordingly
    int j = 0;
    for (i = 0; i < pathLen; i++) {
        if ((path[i] == '.') && (path[i+1] == '/')) {
            i++;
            if ( j == 0 ) {
                // since the very first / is removed, it has to be added back.
                newPath[j] = '/';
                j++;
            }
        } else if ((path[i] == '.') && (path[i+1] == '.') && (path[i+2] == '/')) {
            i++; i++;
            if ( j == 0 ) {
                // since the very first / is removed, it has to be added back.
                newPath[j] = '/';
                j++;
            }
        } else {
            newPath[j] = path[i];
            j++;
        }
        
    }
    newPath[j] = '\0'; // end the string with a null character
    printf("newPath using removeDot2 = %s\n", newPath);
    
}

int main(int argc, const char * argv[]) {


    char pathURL[] = kTestString5; // test 4
    removeDot1(pathURL);
    removeDot2(pathURL);

    return 0;
}

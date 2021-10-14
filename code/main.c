/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int setdfssz, setbfssz, setdiffsz;

int * getTree(){
    int * tree = (int * )malloc(7*sizeof(int));
    for(int i = 0; i<7; i++){
        tree[i] = 1 + i;
    }
    return tree;
}


int * dfs(int * tree){
    int * set = (int* ) malloc(1*sizeof(int));
    int  i = 0;
    setdfssz = 0;
    while(setdfssz < 3){
        set = (int *)realloc(set, (setdfssz+1)*sizeof(int));
        set[setdfssz]  = tree[i];
        i = 2*i+1;
        setdfssz++;
    }
    return set;
}

int *bfs(int * tree){
    int * set = (int* ) malloc(1*sizeof(int));
    int  i = 0;
    setbfssz = 0;
    while(setbfssz<3){
        set = (int *)realloc(set, (setbfssz+1)*sizeof(int));
        set[setbfssz]  = tree[i];
        i++;
        setbfssz++;
    }
    return set;
}

int * setdiff(int * a, int * b){
    int * set = (int* ) malloc(1*sizeof(int));
    setdiffsz = 0;
    for(int i = 0; i< setbfssz; i++){
        bool found = false;
        for(int j = 0; j < setdfssz; j++){
            // printf("%d %d", a[i], b[j]);
            // printf("\n");
            if(a[i] == b[i]) found = true;
        }
        if(!found){
            set = (int *)realloc(set, (setdiffsz+1)*sizeof(int));
            set[setdiffsz] = a[i];
            setdiffsz++;
        }
    }
    // printf("%d", sizeof(set)/sizeof(int));
    return set;
}
int main(void) {
   
    int * tree = getTree();
    int * setdfs = dfs(tree);
    int * setbfs = bfs(tree);
   
   
    for(int i = 0; i< setdfssz; i++){
        printf("%d", setdfs[i]);
    }
    printf("\n");
    for(int i = 0; i< setbfssz; i++){
        printf("%d", setbfs[i]);
    }
   
    int * diff = setdiff(setbfs, setdfs);
    printf("\n");
    for(int i = 0; i< setdiffsz; i++){
        printf("%d", diff[i]);
    }
    
    printf("\nTherefore |A-B| = 1");
}
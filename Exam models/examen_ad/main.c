#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct set set;
struct set{
    char *name;
    set *element[20];
    int n;
    set* next;
}*bookList = 0, *authorList=0;
char* getAuthor(){
    char string[50], *name = (char*)malloc(50);
    name[0]=0;
    scanf("%s ", &string);
    strcpy(name, string);
    scanf("%s ", &string);
    strcat(name, " ");
    strcat(name, string);
    return name;
}
set* findAuthor(char* name){
    set* anAuthor = authorList;
    while(anAuthor != 0){
        if(strcmp(name, anAuthor->name) == 0)
            break;
        anAuthor = anAuthor->next;
    }
    return anAuthor;
}
set* addAuthor(char* name){
    set* anAuthor = malloc(sizeof(set));
    anAuthor->next = authorList;
    authorList = anAuthor;
    anAuthor->name = name;
    anAuthor->n = 0;
}
set* findBook(char* name){
    set* aBook = bookList;
    while(aBook != 0){
        if(strcmp(name, aBook->name) == 0)
            break;
        aBook = aBook->next;
    }
    return aBook;
}
int main()
{
    int k, n;
    char *name;
    set *aBook, * anAuthor;
    while(420){
        scanf("%d", &k);
        if(k == 4) break;
        if(k == 1){
            scanf("%d ", &n);
            printf("1 %d ", n);
            aBook = malloc(sizeof(set));
            aBook->n = n;
            for(int i = 0;i<n;i++){
                name = getAuthor();
                printf("%s ", name);
                anAuthor = findAuthor(name);
                if(anAuthor == 0)
                    anAuthor = addAuthor(name);
                aBook->element[i] = anAuthor;
                anAuthor->element[anAuthor->n++] = aBook;
            }
            scanf("%s", aBook->name);
            printf("%s\n", (*aBook).name);
            aBook->next = bookList;
            bookList = aBook;
        }
        //TEMA: sa re-afisezi intrarea + sa vezi dc citește k pula
        else if(k==2) {
            scanf("%s ", name);
            aBook = findBook(name);
            if(!aBook)
            for(int i = 0; i< aBook->n; i++){
                printf("%s ", aBook->element[i]->name);
            }
        }
        else if(k==3) {
            name = getAuthor();
            anAuthor = findAuthor(name);
            for(int i = 0; i< anAuthor->n; i++){
                printf("%s ", anAuthor->element[i]->name);
            }
        }
    }
}

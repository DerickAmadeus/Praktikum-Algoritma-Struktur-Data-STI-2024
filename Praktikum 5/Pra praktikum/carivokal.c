# include <stdio.h>

int main () {
    char vok;
    scanf("%c", &vok);
    char pita[100];
    scanf("%s", &pita);
    int count = 0;
    int i = 0;

    while(pita[i] != '.') {
        if (pita[i] =='a' | pita[i] =='i' | pita[i] =='u' | pita[i] =='e' | pita[i] =='o'){
            if (pita[i] != vok){
                printf("%c", pita[i]);
                count += 1;
            }
        }
        i += 1;
    }
    if (pita[i] == '.' && count!=0){
        printf(" ");
    }
    printf("%d\n", count);
    return 0;
}
# include <stdio.h>

int main () { 
    char str[20];
    scanf("%s", str);
    if (str[0] == 'A' || str[0]=='I' || str[0]=='U' || str[0] == 'E' || str[0]=='O' || str[0]=='a'||str[0] == 'i' || str[0]=='u' || str[0]=='e' || str[0]=='o'){
        printf("%s menjawab: \"Bintang skibidi, bintang yang paling skibidi tertinggi itu kecuali skibidi 5 hanyalah mewing besar\"\n", str);
    }
    else {
        printf("%s menjawab: \"Bintang skibidi. Matahari terbenam di balik skibidi, hanya skibidi 7 yang tahu apa artinya\"\n", str);
    }
}
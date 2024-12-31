# include <stdio.h> 

int main () { 
    int a;
    scanf("%d", &a);
    int b = a;
    int digit = 0;
    while (b!=0) { 
        b = b/10;
        digit += 1;
    }

    int total = 0;
    while (a!=0){
        if (digit%2 == 0) { 
            total += (a%10);
            a /= 10;
            digit -= 1;
        }
            
        else {
                a /= 10;
                digit -=1 ;
            }
        }
    printf("%d\n", total);
    return 0;
}
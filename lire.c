
#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *f;
    double a;
    
    f=fopen("data.txt","r");
    
    fscanf(f,"%lf",&a);
    printf("%lf\n", a);
    
    fclose(f);
    return 0;
}

#include <stdio.h>

int main(){
    float basic_sal, hra, da, gross_sal;

    printf("Enter the basic salary: ");
    scanf("%f", &basic_sal);

    if (basic_sal < 1500){
        hra = 0.10 * basic_sal;
        da = 0.90 * basic_sal;
    }else{
        hra = 500;
        da = 0.98 * basic_sal;
    }

    gross_sal = basic_sal + hra + da;
    printf("The gross salary is: Rs. %.2f\n", gross_sal);
    return 0;
}


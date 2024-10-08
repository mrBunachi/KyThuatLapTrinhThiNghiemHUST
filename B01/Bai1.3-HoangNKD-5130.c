# include <stdio.h>
int main()
{
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;
    *ptr = (*ptr) + 100;
    printf("x = %d\n", *ptr);

    ptr = &y;
    *ptr = (*ptr) + 100;
    printf("y = %d\n", *ptr);

    ptr = &z;
    *ptr = (*ptr) + 100;
    printf("z = %d\n", *ptr);

    ///printf("\nNguyen Khong Duy Hoang - 20225130 - 2023.2\n");
    return 0;
}

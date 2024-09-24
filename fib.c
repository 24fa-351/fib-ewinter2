#include <stdio.h>
#include <stdlib.h>

int fib_r(int n) {
    if (n <= 1)
        return n;
    return fib_r(n - 1) + fib_r(n - 2);
}

int fib_i(int n) {
    if (n <= 1)
        return n;
    int a = 0;
    int b = 1;
    for (int i = 2; i <= n; i++) {
        int fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main(int argc, char *argv[]) {
   
    if (argc != 4 || argv[2][0] == 'r' && argv[2][0] == 'i') {
        printf("Invalid Input\n");
        return 0;
    }

    int command_num = atoi(argv[1]);

    FILE *file = fopen(argv[3], "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        fclose(file);
        return 0;
    }

    int file_num = 0;

    fscanf(file, "%d", &file_num);
    fclose(file);

    int N = file_num + command_num - 1;
    int result;

    if (argv[2][0] == 'r') {
       result = fib_r(N);
    }
    else {
       result = fib_i(N);
    }

   printf("%d\n", result);

   return 0;
}

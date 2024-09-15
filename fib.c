#include <stdio.h>
#include <stdlib.h>

unsigned long long int terms[1000];

unsigned long long int fib_r(unsigned long long int n) {
    if (n <= 1)
        return n;
    if (terms[n] != 0)
        return terms[n];
    else {
        terms[n] = fib_r(n - 1) + fib_r(n - 2);
 
        return terms[n];
    }
}

unsigned long long int fib_i(int n) {
    if (n <= 1)
        return n;
    unsigned long long int a = 0;
    unsigned long long int b = 1;
    unsigned long long int fib;
    for (int i = 2; i <= n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }
    return b;
}

int main(int argc, char *argv[]) {
   
   if (argc != 4) {
        printf("Not enough params.\n");
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

    char buffer[100]; 
    if (fgets(buffer, sizeof(buffer), file) != NULL) {
        file_num = atoi(buffer); 
    } else {
        printf("Error reading file\n");
    }

   fclose(file);

   int N = file_num + command_num - 1;
   
   unsigned long long int result;

   if (argv[2][0] == 'r') {
      result = fib_r(N);
   }
   else if (argv[2][0] == 'i') {
      result = fib_i(N);
   }
   else {
    printf("Invalid method.\n");
    return 0;
   }

   printf("%llu\n", result);

   return 0;
}

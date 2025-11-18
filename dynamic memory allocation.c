#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    struct Employee *emp;
    float total = 0;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    printf("\n size of structure employee:%d bytes\n",(int)sizeof(struct Employee));
    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter details of employees:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &emp[i].id);
        printf("Enter Name: ");
        scanf("%s", emp[i].name);
        printf("Enter Monthly Salary: ");
        scanf("%f", &emp[i].salary);

        total += emp[i].salary * 12;
    }

    printf("\nTotal annual expenditure on salaries = %.2f\n", total);

    free(emp);
    return 0;
}

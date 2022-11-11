#include <stdio.h>

float calculateSalary(const char emp_fn, const int emp_exp, const int contracted_hours, const int worked_hours, float *ir, float *inss, float *salary, int *exceding_hours) {
    const int YEARS_TB_JUNIOR = 2, YEARS_TB_FULL = 5;
    const int JUNIOR_PG = 25, FULL_PG = 30, SENIOR_PG = 38;
    const int JUNIOR_AN = 45, FULL_AN = 55, SENIOR_AN = 70;
    const int JUNIOR_MG = 85, FULL_MG = 102, SENIOR_MG =  130;

    int hour_value;
    *exceding_hours = worked_hours - contracted_hours;
    if (*exceding_hours < 0) *exceding_hours = 0;

    switch (emp_fn) {
        case 'p':
        case 'P':
            if (emp_exp <= YEARS_TB_JUNIOR)
                hour_value = JUNIOR_PG;
            else if (emp_exp <= YEARS_TB_FULL)
                hour_value = FULL_PG;
            else
                hour_value = SENIOR_PG;
            break;
        case 'a':
        case 'A':
            if (emp_exp <= YEARS_TB_JUNIOR)
                hour_value = JUNIOR_AN;
            else if (emp_exp <= YEARS_TB_FULL)
                hour_value = FULL_AN;
            else
                hour_value = SENIOR_AN;
            break;
        case 'g':
        case 'G':
            if (emp_exp <= YEARS_TB_JUNIOR)
                hour_value = JUNIOR_MG;
            else if (emp_exp <= YEARS_TB_FULL)
                hour_value = FULL_MG;
            else
                hour_value = SENIOR_MG;
            break;
        default:
            break;
    }

    *salary = hour_value * (worked_hours - *exceding_hours);

    if (*exceding_hours < 13)
        *salary += *exceding_hours * hour_value * 0.23;
    else if (*exceding_hours < 22)
        *salary += *exceding_hours * hour_value * 0.37;
    else
        *salary += *exceding_hours * hour_value * 0.56;

    *inss = *salary * 0.11;
    float net_salary = *salary - *inss;

    if (net_salary > 4200)
        *ir = net_salary * 0.3;
    else if (net_salary > 2700)
        *ir = net_salary * 0.2;
    else if (net_salary > 1500)
        *ir = net_salary * 0.15;


    net_salary =  net_salary - *ir;
    return net_salary;
}

void readEmployee(char *emp_fn, int *emp_exp, int *contracted_hours, int *worked_hours) {
    char c;
    do {
        printf("- Function: ");
        scanf(" %c", emp_fn);
        while((c = getchar()) != '\n' && c != EOF)
            (void)0;
    } while (*emp_fn != 'p' && *emp_fn != 'P' && *emp_fn != 'a' && *emp_fn != 'A' && *emp_fn != 'g' && *emp_fn != 'G');

    do {
        printf("- Years of experience: ");
        scanf("%d", emp_exp);
        if ((c = getchar()) != '\n' && c != EOF) {
            *emp_exp = -1;
            while((c = getchar()) != '\n' && c != EOF)
                (void)0;
        }
    } while (*emp_exp < 0);

    do {
        printf("- Contracted hours: ");
        scanf("%d", contracted_hours);
        while((c = getchar()) != '\n' && c != EOF)
            (void)0;
    } while (*contracted_hours <= 0);

    do {
        printf("- Worked hours: ");
        scanf("%d", worked_hours);
        while((c = getchar()) != '\n' && c != EOF)
            (void)0;
    } while (*worked_hours <= 0);
}

void printPayroll(const float net, const float gross, const float ir, const float inss, const int iter, const int exceding_hours) {
    printf("Payroll of Employee n: %d\n- Gross Salary...(R$): %.2f", iter, gross, exceding_hours);
    if (exceding_hours != 0)
        printf("\n- Exceding hours.(hr): %dhr", exceding_hours);
    printf("\n- INSS Discount..(R$): %.2f\n- IR Discount....(R$): %.2f\n- Net Salary.....(R$): %.2f\n", inss, ir, net);
}

int main() {
    int contracted_hours = 0, worked_hours = 0, exceding_hours, experience_years = -1;
    float net_salary, salary, inss, ir = 0;
    char employee_function = '\0';

    int employee_count = 0;

    char c;
    do {
        printf("Qtd: ");
        scanf("%d", &employee_count);
        while((c = getchar()) != '\n' && c != EOF)
            (void)0;
    } while (employee_count <= 0);

    for (int i = 1; i <= employee_count; i++) {
        printf("=========================\nEmployee n: %d\n", i);
        readEmployee(&employee_function, &experience_years, &contracted_hours, &worked_hours);
        net_salary = calculateSalary(employee_function, experience_years, contracted_hours, worked_hours, &ir, &inss, &salary, &exceding_hours);
        printPayroll(net_salary, salary, ir, inss, i, exceding_hours);
    }
    
    return 0;
}
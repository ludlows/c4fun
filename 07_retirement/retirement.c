#include<stdio.h>
#include<stdlib.h>

struct _retire_info{
  int months;
  double contribution;
  double rate_of_return;
}; 

typedef struct _retire_info retire_info;

double month_balance(retire_info ret_info,int months, double balance){
    printf("Age %3d month %2d you have $%.2lf\n", months/12, months%12, balance);
    balance += balance/12.0 * ret_info.rate_of_return;
    balance += ret_info.contribution;
   // printf("contribution is %.2f\n",ret_info.contribution);
   // printf("rates is %.2f\n", ret_info.rate_of_return);
    return balance;
}


void retirement (int startAge,   //in months

                double initial, //initial savings in dollars

                retire_info working, //info about working

                retire_info retired) //info about being retired
{
    int total_months = startAge+ working.months + retired.months;
   // printf("working rate is %.2f\n", working.rate_of_return);
   // printf("retired rate is %.2f\n", retired.rate_of_return);
    int age = startAge;
    for(;age < total_months;age++){
        if(age<working.months+startAge){
        initial = month_balance(working,age, initial);
       } else {
       // printf("EEEEEEE\n");
        initial = month_balance(retired,age, initial);
       }
}
}

int main(void){
  retire_info working;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;
  retire_info retired;
  retired.months = 384;
  retired.contribution = -4000.0;
  retired.rate_of_return = 0.01;
  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}

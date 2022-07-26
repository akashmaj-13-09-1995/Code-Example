#include<stdio.h>

using name space std;

 int main () {

int data[20];
for (int i=0; i< 20; i++)
scanf("&d",&data[i]);
int count._A = count_B = count_C = count_D = count_F=0;

for (int i=0;i<20; i++)
 if (data[i]>= 70)

count_A ++;

else if (data[i] >=60)

count_B ++;
 else if (data[i]>= 50)
count_C++;
else if (data[i] >= 40)

count_D ++;

else 

count_F++;

printf( "A: %d\n B: %d\nC: %d\n D: %d\n F: %d\n " count_A,count_B,count_C,count_D,count_F);


return 0;
}
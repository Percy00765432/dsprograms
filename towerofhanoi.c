#include <stdio.h>
void towerofhanoi(int n,char source,char destination,char auxiliary) {
if(n==1) {
printf("Move disk 1 from %c to %c\n",source,destination);
return;
}
towerofhanoi(n-1,source,auxiliary,destination);
printf("Move disk %d from %c to %c\n",n,source,destination);
towerofhanoi(n-1,auxiliary,destination,source);
}
int main() {
int n;
printf("Enter the number of disks: ");
scanf("%d",&n);
printf("The sequence of moves are: \n");
towerofhanoi(n,'A','C','B');
return 0;
}
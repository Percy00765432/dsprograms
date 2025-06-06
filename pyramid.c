#include <stdio.h>
void printPyramid(int rows, int currentRow) {
if (currentRow > rows) {
return;
}
for (int i = 0; i < rows - currentRow; i++) {
printf(" ");
}
for (int j = 0; j < currentRow; j++) {
printf("#");
}
printf("\n");
printPyramid(rows, currentRow + 1);
}
int main() {
int rows;
printf("Enter the number of rows: ");
scanf("%d", &rows);
printPyramid(rows, 1);
return 0;
}

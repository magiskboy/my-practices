#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int tipPer, taxPer;
    float mealCost, totalCost;
    scanf("%f", &mealCost);
    scanf("%d", &tipPer);
    scanf("%d", &taxPer);
    totalCost = mealCost*(1+(float)tipPer/100+(float)taxPer/100);
    totalCost = (totalCost- (int)totalCost) >=0.5 ? (int)totalCost+1 : totalCost;
    printf("The total meal cost is %d dollars.", (int)totalCost);
    return 0;
}

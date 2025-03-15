#include <stdio.h>
#include <stdlib.h>


void b_search(int* a, int k, int s, int f, int* p) {

}

void count_merge(int* a, int sa, int fa, int sb, int fb, int* inv) {
    int la, lb;
    int ia = 0, ic = 0;
    la = fa - sa;
    lb = fb - sb;
    int* c = (int*)malloc((la + lb) * sizeof(int));
    for (int ib = sb; ib < fb; ++ib) {
        if (a[ia] <= a[ib]) {
            c[ic++] = a[ia++];
        }
        else {
            c[ic++] = a[ib];
            inv += (fa - sa) - ia;
        }
    }
    for (int i = sa; i < sa + la + lb; ++i) {
        a[i] = c[i-sa];
    }
    return;
}

void count_sort(int* a, int s, int f, int* inv) {
    static int iter = 0;
    printf("Count %d\n", iter++);
    if (f - s == 1) {
        inv = 0;
        return;
    }
    int mid = (f - s) / 2, x = 0, y = 0, z = 0;
    count_sort(a, s, mid, &x);
    count_sort(a, mid, f, &y);
    count_merge(a, s, mid, mid, f, &z);
    *inv = x + y + z;
    return;
}


int main(int argc, char** argv) {
    int a[5] = {4, 3, 5 ,1, 6};
    int inv = 0;
    count_sort(a, 0, 5, &inv);
    printf("Inv = %d\n", inv);

    return 0;
}

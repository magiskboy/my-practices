#include <stdio.h>
#include <stdlib.h>

void find_cross_subarray(int* a, int l, int mid, int h, int* lf, int* hf, int* sf) {
    int s = 0;
    int s_left = -9999999, s_right = -9999999;
    int i;
    for (i = mid; i >= l; --i) {
        s += a[i];
        if (s_left < s) {
            s_left = s;
            *lf = i;
        }
    }
    s = 0;
    for (i = mid+1; i <= h; ++i) {
        s += a[i];
        if (s_right < s) {
            s_right = s;
            *hf = i;
        }
    }
    *sf = s_left + s_right;
    return;
}

void find_subarray(int* a, int l, int h, int* lf, int* hf, int* sf) {
    if (l == h) {
        *lf = l;
        *hf = h;
        return;
    }

    int mid = (l + h) / 2;
    int l_left, l_right, l_cross, h_left, h_right, h_cross;
    int s_left, s_right, s_cross;
    find_subarray(a, l, mid, &l_left, &h_left, &s_left);
    find_subarray(a, mid+1, h, &l_right, &h_right, &s_right);
    find_cross_subarray(a, l, mid, h, &l_cross, &h_cross, &s_cross);

    if (s_left >= s_right && s_left >= s_cross) {
        *sf = s_left;
        *lf = l_left;
        *hf = h_left;
    }
    else if (s_right >= s_left && s_right >= s_cross) {
        *sf = s_right;
        *lf = l_right;
        *hf = h_right;
    }
    else {
        *sf = s_cross;
        *lf = l_cross;
        *hf = h_cross;
    }
    return;
}

void find_subsequence(int* a, int l, int h, int* s) {
    if (l == h) {
        *s = a[l];
        return;
    }

    int mid = (l + h) / 2;
    int s_left, s_right;
    find_subsequence(a, l, mid, &s_left);
    find_subsequence(a, mid+1, h, &s_right);
    *s = s_left + s_right;
    *s = s_left > *s ? s_left : *s;
    *s = s_right > *s ? s_right : *s;
    return;
}

int is_negative(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        if (arr[i] >= 0) return 0;
    }
    return 1;
}

int* max_subarray(int arr_count, int* arr, int* result_count) {
    *result_count = 2;
    int* a = (int*)malloc(*result_count * sizeof(int));
    if (is_negative(arr, arr_count)) {
        a[0] = -1;
        a[1] = -1;

    }
    else {
        int l, h;
        int s1 = 0, s2 = 0;
        find_subarray(arr, 0, arr_count-1, &l, &h, &s1);
        find_subsequence(arr, 0, arr_count-1, &s2);
        a[0] = s1;
        a[1] = s2;

    }
    return a;

}

int main(int argc, char** argv) {
    int a[4] = {1, 2, 3, 4};
    int l = 0, h = 0, rs = 0;
    int* r = max_subarray(4, a, &rs);
    printf("Find 1 = %d\n", r[0]);
    printf("Find 2 = %d", r[1]);

    return 0;
}

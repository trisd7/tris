#include <stdio.h>

int n; // number of frames

int findmax(int a[]) {
    int max = a[0], i, k = 0;
    for (i = 1; i < n; i++) {
        if (max < a[i]) {
            max = a[i];
            k = i;
        }
    }
    return k;
}

void main() {
    int seq[30], fr[5], pos[5];
    int find, flag, max, i, j, m, k, t, s;
    int count = 1, pf = 0, p = 0;
    float pfr;

    printf("Enter maximum limit of the sequence: ");
    scanf("%d", &max);

    printf("Enter the sequence: ");
    for (i = 0; i < max; i++)
        scanf("%d", &seq[i]);

    printf("Enter number of frames: ");
    scanf("%d", &n);

    fr[0] = seq[0];
    pf++;
    printf("%d\t", fr[0]);
    i = 1;

    while (count < n) {
        flag = 1;
        p++;
        for (j = 0; j < i; j++) {
            if (seq[i] == seq[j]) {
                flag = 0;
                break;
            }
        }
        if (flag != 0) {
            fr[count] = seq[i];
            printf("%d\t", fr[count]);
            count++;
            pf++;
        }
        i++;
    }

    printf("\n");

    for (i = p; i < max; i++) {
        flag = 1;
        for (j = 0; j < n; j++) {
            if (seq[i] == fr[j]) {
                flag = 0;
                break;
            }
        }

        if (flag != 0) {
            for (j = 0; j < n; j++) {
                m = fr[j];
                pos[j] = -1;
                for (k = i + 1; k < max; k++) {
                    if (seq[k] == m) {
                        pos[j] = k;
                        break;
                    }
                }
            }

            int found = 0;
            for (k = 0; k < n; k++) {
                if (pos[k] == -1) {
                    s = k;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                s = findmax(pos);
            }

            fr[s] = seq[i];
            for (k = 0; k < n; k++)
                printf("%d\t", fr[k]);
            printf("\n");
            pf++;
        }
    }

    pfr = (float)pf / (float)max;
    printf("\nThe number of page faults = %d", pf);
    printf("\nPage Fault Rate = %.2f\n", pfr);
}
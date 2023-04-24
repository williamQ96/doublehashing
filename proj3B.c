#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 20000

typedef struct {
    char *keys[MAX_SIZE];
    float value[MAX_SIZE];
} ArrayDictionary;

int my_strcmp(char *a, char *b) {
    int i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return 1;
        }
        i++;
    }
    return 0;
}

void Initialize(ArrayDictionary *ad) {
    for (int i = 0; i < MAX_SIZE; i++) {
        ad->keys[i] = "N";
        ad->value[i] = 0;
    }
}

void Store(ArrayDictionary *ad, char *key, float value) {
    int yy = (key[6] - '0') * 10 + key[7] - '0';
    int temp = yy * 365;
    int hash1 = temp % MAX_SIZE;
    int hash2 = 13 - temp % 13;
    int temp2 = hash1;

    for (int i = 0; i < MAX_SIZE; i++) {
        if (my_strcmp(ad->keys[temp2], "N") == 0) {
            ad->keys[temp2] = key;
            ad->value[temp2] = value;
            return;
        } else {
            temp2 = (temp2 + hash2) % MAX_SIZE;
        }
    }

    exit(EXIT_FAILURE);
}

float Fetch(ArrayDictionary *ad, char *key) {
    int yy = (key[6] - '0') * 10 + key[7] - '0';
    int temp = 365 * yy;

    for (int i = 0; i < MAX_SIZE; i++) {
        int temp2 = (temp + i) % MAX_SIZE;
        if (my_strcmp(ad->keys[temp2], key) == 0) {
            return ad->value[temp2];
        }
    }

    return 0;
}

int main() {
    clock_t start, end;
    start = clock();

    FILE *f = fopen("DJIA", "r");
    if (f == NULL) {
        fprintf(stderr, "Unable to open file \"DJIA\" ... did you copy it to the current directory?\n");
        exit(EXIT_FAILURE);
    }

    ArrayDictionary ad;
    Initialize(&ad);

    size_t size = 1024;
    char *buffer = malloc(size * sizeof(char));
    getline(&buffer, &size, f);  // pass first line

    while (getline(&buffer, &size, f) > 0) {
        char date[20];
        float price1, price2, price3, closePrice;
        sscanf(buffer, "%s %f %f %f %f", date, &price1, &price2, &price3, &closePrice);
        char *temp = strdup(date);
        Store(&ad, temp, closePrice);
    }

    char dates[91][10] = {
        // dates array
    };

    float sum = 0;

    for (int i = 0; i < 91; i++) {
        float val = Fetch(&ad, dates[i]);
        if (val == 0.) {
            printf("Bad fetch!\n");
            exit(EXIT_FAILURE);
        }
        sum = sum + val;
    }

    end = clock();
    double duration = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Over the 91 days, the average value was %d\n", (int)(sum / 91.0));
    // It should print:
    //    Over the 91 days, the average value was 13209
    printf("time taken to execute in seconds:%f\n", duration);

    return 0;


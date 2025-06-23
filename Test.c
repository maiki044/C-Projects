#include <stdio.h>

#define N 100

void rotateImage(int n, int image[N][N], int rotation) {

    int temp[N][N];

    int i, j;

    if (rotation == 90) {

        for (i = 0; i < n; i++)

            for (j = 0; j < n; j++)

                temp[j][n - 1 - i] = image[i][j];

    } else if (rotation == 180) {

        for (i = 0; i < n; i++)

            for (j = 0; j < n; j++)

                temp[n - 1 - i][n - 1 - j] = image[i][j];

    } else if (rotation == 270) {

        for (i = 0; i < n; i++)

            for (j = 0; j < n; j++)

                temp[n - 1 - j][i] = image[i][j];

    } else {

        return;

    }

    for (i = 0; i < n; i++)

        for (j = 0; j < n; j++)

            image[i][j] = temp[i][j];

}

void verticalFlip(int n, int image[N][N]) {

    int temp;

    for (int i = 0; i < n / 2; i++) {

        for (int j = 0; j < n; j++) {

            temp = image[i][j];

            image[i][j] = image[n - 1 - i][j];

            image[n - 1 - i][j] = temp;

        }

    }

}

void horizontalFlip(int n, int image[N][N]) {

    int temp;

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n / 2; j++) {

            temp = image[i][j];

            image[i][j] = image[i][n - 1 - j];

            image[i][n - 1 - j] = temp;

        }

    }

}

void getFinalImage(int n, int image[N][N], int rotation, int verticalFlipFlag, int horizontalFlipFlag) {

    if (rotation != 0) {

        rotateImage(n, image, rotation);

    }

    if (verticalFlipFlag == 1) {

        verticalFlip(n, image);

    }

    if (horizontalFlipFlag == 1) {

        horizontalFlip(n, image);

    }

}

void printImage(int n, int image[N][N]) {

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            printf("%d ", image[i][j]);

        }

        printf("\n");

    }

}

int main() {

    int n = 3;

    int image[N][N] = {

        {0, 0, 1},

        {0, 1, 1},

        {1, 0, 0}

    };

    int rotation = 270;

    int verticalFlipFlag = 0;

    int horizontalFlipFlag = 1;

    getFinalImage(n, image, rotation, verticalFlipFlag, horizontalFlipFlag);

    printImage(n, image);

    return 0;

}

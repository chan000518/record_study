#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000
#define M 2

int data[N];
int depth; // Global variable
int Rtime;

/*** THE ABOVE CODE OF QUICKSORT COMES HERE ***/
void swap(int *x, int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int arr[], int l, int r){
    int x=arr[l];
    int i=l+1;
    int j=r;
    while (1) {
        while (arr[i] <= x && i<=r) i++;
        while (arr[j] > x && j>=l) j--;
        if (i<j) swap(&arr[i],&arr[j]);
        else break;
    }
    swap(&arr[l],&arr[j]);
    return j;
}

void myQuicksort(int arr[], int l, int r, int d){
    int p;
    Rtime++;
    if (depth < d) depth = d; // depth updated
    if (l < r) {
        p = partition(arr, l, r);
        // printf("partition at p=%d\n", p);
        myQuicksort(arr, l, p-1, d+1);
        myQuicksort(arr, p+1, r, d+1);
    }
}

int L[N], R[N];

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // 임시 배열 생성
    
    // 데이터를 임시 배열에 복사
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // 임시 배열을 병합하여 arr[]에 다시 복사
    i = 0; // 첫 번째 서브 배열의 초기 인덱스
    j = 0; // 두 번째 서브 배열의 초기 인덱스
    k = l; // 병합된 서브 배열의 초기 인덱스
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // L[]의 남은 요소들을 복사
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // R[]의 남은 요소들을 복사
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r, int d) {
    Rtime++;
    if (depth < d) depth = d; // depth updated
    if (l < r) {
        // 같은 타입으로 나눈다
        int m = l + (r - l) / 2;

        // 첫 번째와 두 번째 하프를 정렬한다
        mergeSort(arr, l, m, d+1);
        mergeSort(arr, m + 1, r, d+1);

        merge(arr, l, m, r);
    }
}

int main(){
    clock_t start, end;
    double cpu_time_used;
    time_t t;
    srand((unsigned) time(&t)); // Intializes random number generator
    int i, j;
    for(j=0; j<M; j++){
        start = clock();
        for(i=0; i<N; i++){
            data[i]=rand();
        }
        depth=0; // set the global variable depth = 0 before calling quicksort
        Rtime = 0;
        myQuicksort(data,0,N-1,0); // the first call with d=0
        printf("Recursion depth = %d\n", depth);
        printf("%d\n",Rtime);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken by Quick: %f seconds\n", cpu_time_used);
    }
    for(j=0; j<M; j++){
        start = clock();
        for(i=0; i<N; i++){
            data[i]=rand();
        }
        depth=0; // set the global variable depth = 0 before calling quicksort
        Rtime = 0;
        mergeSort(data,0,N-1,0); // the first call with d=0
        printf("merge depth = %d\n", depth);
        printf("%d\n",Rtime);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Time taken by merge: %f seconds\n", cpu_time_used);
    }
}
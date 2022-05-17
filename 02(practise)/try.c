#include<stdio.h>

void main() {
  int arr[20], size, i, c = 0, j, a, z, m = 0, ct = 0;
  ct++;
  ct++;
  ct++;
  printf("\nenter no of elements : ");
  ct++;
  scanf("%d", & size);
  ct++;
  printf("\nenter the elements ");
  ct++;
  for (i = 0; i < size; i++) {
    ct++;
    scanf("%d", & arr[i]);
    ct++;
  }
  ct++;
  printf("\nthe elements are :");
  ct++;
  for (i = 0; i < size; i++) {
    ct++;
    printf(" %d ", arr[i]);
    ct++;
  }
  ct++;
  for (i = 0; i < size; ++i) {
    ct++;
    for (j = i + 1; j < size; ++j) {
      ct++;
      if (arr[i] == arr[j]) {
        ct++;
        c++;
        ct++;
        for (z = j; z < size - 1; z++) {
          ct++;
          arr[z] = arr[z + 1];
          ct++;
        }
        ct++;
        size--;
        ct++;
        j--;
        ct++;
      }

    }
    ct++;
  }
  ct++;
  printf("\nsize %d", size);
  ct++;
  printf("\nValue of Counter c = %d ", c);
  ct++;
  for (i = 0; i < c; i++) {
    ct++;
    size++;
    ct++;
    arr[size] = 0;
    ct++;
  }
  ct++;
  printf("\nthe elements are :");
  ct++;
  for (i = 0; i < size; i++) {
    ct++;
    printf(" %d ", arr[i]);
    ct++;
  }
  ct++;
  ct++;
  printf("\nTime Complexity%d", ct);
  //end
}

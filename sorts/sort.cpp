/*
 * selectioonsort.cpp
 *
 *  Created on: Apr 9, 2018
 *      Author: a
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "sort.h"

#define num 10

int a[num];
int b[num];
int cc[10];

void p() {
	for (int i = 0; i < num; i++) {
		printf("%d ", a[i]);
	}
}

void swap(int *a, int *b) {
	if (a == b)
		return;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

void quickSort(int left, int right) {
	int i = left, j = right;
	int pivot = a[(i + j) / 2];

	if (i >= j)
		return;

	while (i < j) {
		while (a[i] < pivot)
			i++;
		while (a[j] > pivot)
			j--;
		swap(&a[i], &a[j]);
		i++;
		j--;
	}
	quickSort(left, i - 1);
	quickSort(i, right);
}

void merge(int left, int mid, int right) {
	int i = left, j = mid + 1;
	int ib = left;
	int c = 0;
	while (i <= mid && j <= right) {
		if (a[i] < a[j]) {
			b[ib++] = a[i++];
		} else {
			b[ib++] = a[j++];
		}
	}
	while (i <= mid)
		b[ib++] = a[i++];
	while (j <= right)
		b[ib++] = a[j++];

	for (c = left; c <= right; c++)
		a[c] = b[c];
}
void mergesort(int l, int r) {
	if (l >= r)
		return;
	int m = (l + r) / 2;

	mergesort(l, m);
	mergesort(m + 1, r);

	merge(l, m, r);
}
void countsort() {
	for (int i = 0; i < num; i++) {
		cc[a[i]]++;
	}

	int z = 0;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < cc[i]; j++) {
			a[z++] = i;
		}
	}
}

void ShellSort(int a[num], int n) {
	int i, j, len, stemp;
	len = 3;
	while (true) {
		for (i = 0; i < n; i++) {
			j = i;
			stemp = a[i];
			while ((j >= len) && (a[j - len] > stemp)) {
				a[j] = a[j - len];
				j = j - len;
			}
			a[j] = stemp;
		}

		if (len == 1) {
			break;
		} else if (len / 2 != 0) {
			len = len / 2;
		} else
			len = 1;
	}
}
Sort::Sort() {
	// TODO Auto-generated constructor stub
	printf("%s started\n", __FUNCTION__);

	for (int i = 0; i < num; i++) {
		a[i] = rand() % 1000;
	}

	printf("\nA : %d:\n", 20 / 11);

	printf("\nArray before sorted:\n");
	p();
	fflush(stdout);
	//	quickSort(0, num - 1);
	//	mergesort(0, num-1);
	//	countsort();
	ShellSort(a, num);
	printf("\nArray after sorted:\n");
	p();

}

Sort::~Sort() {
	// TODO Auto-generated destructor stub
}

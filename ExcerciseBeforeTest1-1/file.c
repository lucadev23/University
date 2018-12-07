/*
*
* @author lucadev23
*
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10
#define LENGHT_FILE_NAME_INPUT 10

int init_array(float *);
void print_from_min_to_max(float *,int);
void print_max_value(float *, int);
int menu(void);
int save_results(float *,int);

int main(void) {
	float v[N] = { 0.0 };
	int num_of_value = 0, c = 0;
	num_of_value = init_array(v);
	if (num_of_value < 0) { //an error
		printf("There is an error with file!\n");
		system("PAUSE");
		return 0;
	}
	if (num_of_value == 0) {
		printf("File empty!\n");
		system("PAUSE");
		return 0;
	} // if num_of_value > 0 , there is at least one number
	system("CLS");
	do {
		c = menu();
		switch (c) {
			case 1:
				print_from_min_to_max(v, num_of_value);
				system("PAUSE");
				system("CLS");
				break;
			case 2:
				print_max_value(v, num_of_value);
				system("PAUSE");
				system("CLS");
				break;
			default: break;
		}
	} while (c != 3);
	if (save_results(v, num_of_value) < 0) {
		printf("There is an error with file output!\n");
		system("PAUSE");
	}
	return 0;
}

int save_results(float v[], int num) {
	FILE *fp;
	int i;
	fp = fopen("uscita.txt", "w");
	if (fp == NULL) {
		return -1;
	}
	for (i = 0; i < num; i++) {
		fprintf(fp, "%f\n", v[i]);
	}
	fclose(fp);
	return 0;
}

int menu(void) {
	int c = 0;
	do {
		printf("Menu:\n");
		printf("\t1) Print value from min to max value\n");
		printf("\t2) Print the max value\n");
		printf("\t3) Exit\n");
		printf("\nChoose --> ");
		scanf("%d", &c);
	} while (c < 1 || c>3);
	system("CLS");
	return c;
}

void print_max_value(float v[], int num) {
	int i,index=0;
	float max=v[0];
	// the first cycle is not usefull
	for (i = 0; i < num; i++) {
		if (max < v[i]) {
			max = v[i];
			index = i;
		}
	}
	printf("Max Value --> %f\n", max);
	printf("Index Value --> %d\n", index+1);
}

void print_from_min_to_max(float v[], int num) { //num describes how much numbers there are in the array
	int i;
	float min, max;
	printf("Insert a min value: ");
	scanf("%f", &min);
	printf("Insert a max value: ");
	scanf("%f", &max);
	printf("Values from %f to %f\n", min, max);
	for (i = 0; i < num; i++) {
		if (v[i] >= min && v[i] <= max) {
			printf("%f\n", v[i]);
		}
	}
}

int init_array(float v[]) {
	float n1=0, n2=0;
	int i, num=0;
	FILE *fp = NULL;
	char name[LENGHT_FILE_NAME_INPUT] = { 0 }; // name array is full of NULL character
	printf("Insert file name of input: ");
	scanf("%s", name);
	fp = fopen(name, "r");
	if (fp == NULL) {
		return -1; //error with file
	}
	for (i = 0; i < N; i++) {
		if (fscanf(fp, "%f %f", &n1, &n2) == EOF) {
			break;
		}
		v[i] = (float)((n1 + n2) / 2);
		num++;
	}
	fclose(fp);
	return num;
}
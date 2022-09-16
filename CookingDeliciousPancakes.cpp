/*********************************************************

	Algorithms, Fall, 2022
	Homework Problem 2 : Cooking delicious pancakes

	Written by Rina Kim (krn2363@gachon.ac.kr)
	September, 2022

************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int Max(int arr[30], int cnt, int k);
int flip(int arr[30], int cnt, int k, int idx, int flip_result[100], int fnum);

int main()
{
	char inFileName[5][20] = { "Input_1.txt", "Input_2.txt", "Input_3.txt", "Input_4.txt","Input_5.txt" };
	char outFileName[5][20] = { "Output_1.txt", "Output_2.txt", "Output_3.txt", "Output_4.txt", "Output_5.txt" };

	for (int fileIndex = 0; fileIndex < 5; fileIndex++)
	{
		FILE* inFile;
		FILE* outFile;
		int k = 0;
		char list[100];	//The list that receives in the beginning
		int arr[30];	//To store each pancakes diameter
		int flip_result[100];	//Flip sequence
		int fnum = 0;	//Flip sequence index
		int cnt = 0;	//The number of pancakes
		int Index;
		char delimit[] = " ";
		char* ptr;

		inFile = fopen(inFileName[fileIndex], "r");
		outFile = fopen(outFileName[fileIndex], "w");

		if (inFile == NULL)
		{
			printf("InFile is not opened\n");
		}

		//Each line is taken from a text file
		while (fgets(list, sizeof(list), inFile) != NULL)
		{
			ptr = strtok(list, "\n");
			fprintf(outFile, "%s", list);

			ptr = strtok(list, delimit);

			//Change character type to int type & store in array
			while (ptr != NULL)
			{
				arr[cnt] = atoi(ptr);
				cnt++;
				ptr = strtok(NULL, delimit);
			}

			//run_algorithm
			for (int i = 0; i < cnt; i++)
			{
				Index = Max(arr, cnt, k);
				fnum = flip(arr, cnt, k, Index, flip_result, fnum);
				k++;
			}

			flip_result[fnum] = 0;	//The last flip sequence

			//prints sorted list
			fprintf(outFile, " (");

			for (int i = 0; i < cnt; i++)
				fprintf(outFile, "%d ", arr[i]);

			fprintf(outFile, ") ");

			//prints the sequence of flip
			for (int i = 0; i < fnum + 1; i++)
				fprintf(outFile, "%d ", flip_result[i]);

			k = 0;
			cnt = 0;
			fnum = 0;
			fprintf(outFile, "\n");
		}

		fclose(inFile);
		fclose(outFile);
	}

	return 0;
}

/*
	Max function
	Input : array(int type), cnt(int type), k(int type)
	Return : index(int type)
	Function : Search the max number and returns max number's index
*/
int Max(int arr[30], int cnt, int k)
{
	int index, max = 0;

	for (int i = 0; i < cnt - k; i++)
	{
		if (max <= arr[i])
		{
			max = arr[i];
			index = i;
		}
	}

	return index;
}

/*
	flip function
	Input : array(int type array), cnt(int type), k(int type), idx(int type),
			flip_result(int type array), fnum(int type)
	Return : fnum(int type)
	Function : Flips pancakes
*/
int flip(int arr[30], int cnt, int k, int idx, int flip_result[100], int fnum)
{
	int i, j, temp;
	if (idx != cnt - k - 1)
	{
		if (idx == 0)
		{
			for (i = 0; i < (cnt - k) / 2; i++)
			{
				j = cnt - 1 - k - i;
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			flip_result[fnum] = k + 1;
			fnum++;
		}

		else
		{
			if (idx >= 3)
			{
				for (i = 0; i < 2; i++)
				{
					j = idx - i;
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			else
			{
				for (i = 0; i < idx; i++)
				{
					j = idx - i;
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			if (idx == 1)
			{
				if (arr[0] == arr[1])
				{
					idx = 0;
					fnum = flip(arr, cnt, k, idx, flip_result, fnum);
				}
				else
				{
					flip_result[fnum] = cnt - idx;
					fnum++;
					idx = 0;
					fnum = flip(arr, cnt, k, idx, flip_result, fnum);
				}
			}
			else
			{
				flip_result[fnum] = cnt - idx;
				fnum++;
				idx = 0;
				fnum = flip(arr, cnt, k, idx, flip_result, fnum);
			}
		}
	}
	return fnum;
}
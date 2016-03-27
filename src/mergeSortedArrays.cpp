/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isolder1(char *dob1, char *dob2);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (((A != NULL) || (B != NULL)) && ((A != NULL) && (B != NULL)))
	{
		struct transaction *res = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
		int r, i = 0, j = 0, l = 0;
		while (i < ALen && j < BLen)
		{
			r = isolder1(A[i].date, B[j].date);
			if (r == 0 || r == 1)
			{
				res[l] = A[i];
				i++;
			}
			else
			{
				res[l] = B[j];
				j++;
			}
			l++;
		}
		while (i < ALen)
		{
			res[l] = A[i];
			i++;
			l++;
		}
		while (j < BLen)
		{
			res[l] = B[j];
			j++;
			l++;
		}


		return res;
	}
return NULL;
}






int isolder1(char *dob1, char *dob2)
{
	int i;
	for (i = 6; i <= 9; i++)
	{
		if (dob1[i] == dob2[i])
		{

		}
		else if (dob1[i] < dob2[i])
		{
			return 1;
		}
		else if (dob1[i] > dob2[i])
		{
			return 2;
		}
	}
	for (i = 3; i < 5; i++)

	{

		if (dob1[i] == dob2[i])
		{

		}
		else if (dob1[i] < dob2[i])
		{
			return 1;
		}
		else if (dob1[i] > dob2[i])
		{
			return 2;
		}

	}
	for (i = 0; i < 2; i++)

	{
		if (dob1[i] == dob2[i])
		{
		}
		else if (dob1[i] < dob2[i])
		{
			return 1;
		}
		else if (dob1[i] > dob2[i])
		{
			return 2;
		}
	}

	return 0;
}
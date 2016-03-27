/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isolder(char *dob1, char *dob2);
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (((A != NULL) || (B != NULL)) && ((A != NULL) && (B != NULL)))
	{
		struct transaction *res = (struct transaction*)malloc(sizeof(struct transaction) * 3);
		int k = 0, r, P = 0;
		for (int i = 0; i < ALen; i++)
		{
			for (int j = 0; j < BLen; j++)
			{
				r = isolder(A[i].date, B[j].date);
				if (r == 0)
				{
					P++;
					res[k] = A[i];
					k++;
				}
				else if (r == 1)
				{
					break;

				}
			}

		}
		if (P == 0)
		{
			return NULL;
		}
		return res;
	}
	return NULL;
}






int isolder(char *dob1, char *dob2) {
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


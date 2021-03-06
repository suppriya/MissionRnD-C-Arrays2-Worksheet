/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) 
{
int count = 0, a = -1, c = 0;
char* temp = date;
int i = 0, a1 = 0;
while (i<len)
{
	c = 0;
	for (int k = 0; k < 10; k++)
	{
		if (Arr[i].date[k] == temp[k])
		{
			c++;
		}
	}
	if (c == 10)
	{
		a = i;
		a1++;
	}
	else if (a1 == 0)
	{
		a = -2;
	}
	i++;
}
if ((a1 == len) || (a == -2))
{
	return 0;
}

else return len - a - 1;

}


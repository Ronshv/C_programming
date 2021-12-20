#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TXT 1024
#define WORD 30
#define SIZE_LIST 26

const char myAlpha[SIZE_LIST] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
										'n','o','p','q','r','s','t','u','v','w','x','y','z' };



int single_val(char c)				//help function to extract gymmetric value of single character
{
	
	for (int i = 0; i < SIZE_LIST; i++)
	{
		if (c == myAlpha[i])
		{
			return i + 1;
		}

	}
	return 0;
}


int calc_gymmetric_seq(char* mystr)
{
	int gym_sum = 0;
	int curr_val;
	char ch;
	for (int i = 0; i < strlen(mystr); i++)
	{
		ch = mystr[i];
		tolower(ch);
		curr_val = single_val(ch);
		gym_sum += curr_val;
	}
	return gym_sum;
}


void cmp_TXT_and_WORD(char* txt, char* word)
{
	char minSEQ[WORD] = { 0 };
	int temp_gym = 0;
	int gym_input_val = calc_gymmetric_seq(word);
	int indx = 0;
	for (int i = 0; i <= strlen(txt); i++)
	{
		if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z'))
		{
			minSEQ[indx] = txt[i];
			indx++;

			/*
			if (flg_reset == 0)
			{
				minSEQ[i] = txt[i];
			}
			else if (flg_reset == 1)
			{
				minSEQ[indx] = txt[i];
				indx++;

			}
			*/

		}
		//should be executed iff there was relevant string
		//before there were deletion

		else
		{
			if (strlen(minSEQ) > 0)
			{
				temp_gym = calc_gymmetric_seq(minSEQ);
				if (temp_gym == gym_input_val)
				{
					printf("* %s", minSEQ);
					printf("\n");
				}
				memset(minSEQ, 0, sizeof(minSEQ));
				indx = 0;
			}
		
		}
	}

}

int get_chIDX(char c)
{
	for (int i = 0; i < strlen(myAlpha); i++)
	{
		if (myAlpha[i] == c)
			return i;
	}
}

char* ATB_Cript(char* word)
{
	char strout[WORD];
	int ch_trans;
	char curr_ch;
	char rel_ch;
	for (int i = 0; i < strlen(word); i++)
	{
		rel_ch = word[i];
		int pos = get_chIDX(tolower(word[i]));
		/*
		if (rel_ch >= 'A' && rel_ch <= 'Z')		//for the situation where big letter has been entered
		{
			rel_ch = tolower(rel_ch);
		}
		*/
		int ch_reper = strlen(myAlpha)-1- pos;
		curr_ch = myAlpha[ch_reper];
		if (rel_ch >= 'A' && rel_ch <= 'Z')
		{
			curr_ch=toupper(curr_ch);
		}
		strout[i] = curr_ch;
	}
	return strout;
}


void pass_over_atbs(char* word,char* txt)
{
	char ch;
	char checked_seq[WORD]="";
	char next_word[WORD];
	memcpy(next_word,ATB_Cript(word), sizeof(next_word));		//to produce string of ATBASH writing
	int my_indx = 0;		//for allocating alphabetic characters in string
	int j, int new_idx;
	for (int i = 0; i <= strlen(txt); i++)
	{
		if ((txt[i] >= 'A' && txt[i] <= 'Z') || (txt[i] >= 'a' && txt[i] <= 'z'))
		{
			checked_seq[my_indx] = txt[i];
			my_indx = my_indx + 1;
		}

		new_idx = my_indx + 1;
		j = my_indx + 1;

		while (isspace(txt[j]) && j < strlen(txt))
		{
			//continue;
			j++;
		}
		checked_seq[new_idx] = txt[j];			//should insert from where the space finishes	
		j++;

		


			if (strlen(checked_seq) >= 1)
			{
				if ((checked_seq == next_word) || (checked_seq == _strrev(next_word)))
				{
					printf("%s", checked_seq);
				}

			}

		
			

		
		else                             //we wouldn't like for us to continue process the word 
		{								//so we'd reset the array
			
			memset(checked_seq, 0, sizeof(checked_seq));
			my_indx = 0;
		}
		
			

	}
	
}






int main()
{
	char txt[TXT], char word[WORD];
	int i = 0;
	while (!(word[i] == '\n' || word[i] == '\t' || word[i] == ' ')
	{
		scanf("%c", word[i]);
		i++;
	}

	for (int j = 0; word[j] != '~'; j++)
	{
		scanf("%c", word[j]);
	}

	pass_over_atbs(word, txt);
}

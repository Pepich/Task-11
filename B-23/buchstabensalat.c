/**********************************/
/* Benedikt Abel, Justus Faust    */
/* Gruppe: Di08                   */
/* Uebungsblatt: 11, Aufgabe B-23 */
/* Thema: buchstabensalat         */
/* Version: v1.0.0                */
/* Datum: 20160711                */
/* Status: werks                  */
/**********************************/

#include <stdio.h>
#include <stdlib.h>

// Searches a vertical column for the given word, beginning at x, y and at the index i of the word.
// Returns 0 if no word was found, 1 if found. If found, the words ending coordinates will be
// put in ex, ey
int vert(char *word, int x, int y, int i, int *ex, int *ey, char grid[10][10])
{
    // End of word reached, word was found
    if (word[i] == '\0')
    {
	*ex = x;
	*ey = y+i-1;
	return 1;
    }
    if (grid[y+i][x] != word[i])
	return 0;
    return vert(word, x, y, i+1, ex, ey, grid);
}

// Same as vert but searching in horizontal direction
int hori(char *word, int x, int y, int i, int *ex, int *ey, char grid[10][10])
{
    // End of word reached, word was found
    if (word[i] == '\0')
    {
	*ex = x+i-1;
	*ey = y;
	return 1;
    }
    if (grid[y][x+i] != word[i])
	return 0;
    return hori(word, x, y, i+1, ex, ey, grid);
}

// Reads a word of length l and clears the input buffer. Returns the length of the word and
// Puts the read word into word.
// Yeah. This exist. Meh. I can do this too without using system functions :3
int getWord(int l, char **word)
{
    int count = 0;
    // Init word
    *word = calloc(l, sizeof(char));
    // Variable to indicate if the buffer was emptied yet
    int done = 0;
    for (int i = 0; i < l-1; ++i)
    {
	char c = '\0';
	scanf("%c", &c);
	// Abort if linefeed was reached, set done to 1 as the buffer is empty, terminate the string
	if (c == '\n' || c == '\r')
	{
	    done = 1;
	    break;
	}
	(*word)[i] = c;
	count++;
    }
    
    while (!done)
    {
	char c = '\0';
	scanf("%c", &c);
	if (c == '\n')
	    done = 1;
    }
    return count;
}

int find(char *word, int *x, int *y, int *ex, int *ey, char grid[10][10])
{
    int l = 0;
    // Get the length of the word for easier calc
    while (word[l] != '\0')
	l++;
    for (*x = 0; *x < 10; ++*x)
	for (*y = 0; *y <= 10-l; ++*y)
	    // Do a vertical scan, if found, end.
	    if (vert(word, *x, *y, 0, ex, ey, grid))
		return 1;

    for (*x = 0; *x <= 10-l; ++*x)
	for (*y = 0; *y < 10; ++*y)
	    // Do a horizontal scan, if found, end.                                                                                                                                                                                                                                           
            if (hori(word, *x, *y, 0, ex, ey, grid))
                return 1;

    // After the whole grid was searched and nothing was found, abort.
    return 0;
}

int main(void)
{
    char bstsalat[10][10] = { {'a','r','r','a','y','i','p','o','u','t'}, 
			      {'r','l','m','p','y','u','o','b','u','n'},
			      {'s','t','r','i','n','g','i','l','w','l'},
			      {'x','o','x','n','t','o','n','a','h','s'},
			      {'u','v','w','t','o','l','t','s','i','t'},
			      {'r','e','t','u','r','n','e','u','l','w'},
			      {'b','z','a','z','y','e','r','m','e','s'},
			      {'f','u','l','c','z','i','o','r','t','u'},
			      {'o','a','m','k','d','o','u','b','l','e'},
			      {'r','f','u','w','z','x','d','d','x','y'}};
    // Variable to hold the user input, as well as position info
    char *word;
    int x, y, ex, ey;
    printf("Bitte Wort eingeben: ");
    getWord(11, &word);

    if (!find(word, &x, &y, &ex, &ey, bstsalat))
	printf("Das Wort %s wurde nicht gefunden.\n", word);
    else
	printf("Das Wort %s wurde an der Stelle (%i, %i) gefunden. Es endet bei (%i, %i).\n", word, x, y, ex, ey);
    return 0;
}

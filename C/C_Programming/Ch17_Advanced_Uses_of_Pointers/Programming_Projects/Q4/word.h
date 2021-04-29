#ifndef WORD_H
#define WORD_H

/*

read_word: Reads the next word from the input and store it
in word. Makes word empty if no word could be read because
of end-of-file. Truncate the word if its length exceeds len.
Returns number of characters stored.

*/
int read_word(char *word, int len);
#endif
/* Chapter 12. String Exercises */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//Q4 a
int read_linea (char str[], int n);
//Q4 b
int read_lineb (char str[], int n);
//Q4 c
int read_linec (char str[], int n);
//Q5
void capitalize(char *p);
//Q6
void censor(char *p);
//Q11
bool my_strcmp(const char *p, const char *q);
//Q12
void get_extension(const char *file_name, char *extension);
//Q13
void build_index_url(const char *domain, char *index_url);
//Q16
int count_space(const char *str);
//Q17
bool test_extension(const char *file_name, const char *extension);
//Q18
void remove_filename(char *url);

int main(void)
{
    char str[255];
    read_linea(str, 255);
    censor(str);
    capitalize(str);
    printf("%s\n", str);

    char q[255] = "";
    strcpy(q, str);
    if (my_strcmp(str, q) == 0) printf("%s\n", q);
    else printf("No\n");
    build_index_url(str, q);
    printf("%s\n", q);
    remove_filename(q);
    printf("%s\n", q);
    return 0;
}

int read_linea (char str[], int n)
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n') if ((i < n) && (i != 0 || ch != ' ')) str[i++] = ch;
    str[i] = '\0';
    return i;
}

int read_lineb (char str[], int n)
{
    int ch, i = 0;

    while (i < n) if (isspace(ch)) {break;} else {str[i++] = ch;}
    str[i] = '\0';
    return i;
}

int read_linec (char str[], int n)
{
    int ch, i = 0;

    while (i < n) {ch = getchar(); if (ch == '\n') {str[i++] = ch; break;} else {str[i++] = ch;}}
    str[i] = '\0';
    return i;
}

void capitalize(char *p)
{
    for (; *p != '\0'; *p++ = toupper(*p));
}

void censor(char *p)
{
    for (; *(p + 2) != '\0'; ++p) if (*p == 'f' && *(p+1) =='o' && *(p+2) == 'o') *p = *(p+1) = *(p+2) = 'x';
}

bool my_strcmp(const char *p, const char *q)
{
    for (; *p == *q; ++p, ++q) if (*p == '\0') return 0;
    return *p - *q;
}

void get_extension(const char *file_name, char *extension)
{
    for (; *file_name != '.' || *file_name != '\0'; ++file_name);
    if (*file_name == '\0') strcat(extension, "");
    else {
        for (; *file_name != 0; ++file_name) *extension++ = *file_name;
    }
}

void build_index_url(const char *domain, char *index_url)
{
    strcpy(index_url, "http://www."); strcat(index_url, domain); strcat(index_url, ".com/index.html");
}

int count_space(const char *str)
{
    int i = 0;
    while (*str++) if(*str == ' ') ++i;
}

bool test_extension(const char *file_name, const char *extension)
{
    while (*file_name++ != '.');
    while (*file_name++) if (toupper(*file_name) !=toupper(*extension++)) return false;
    return true;
}

void remove_filename(char *url)
{
    int i = strlen(url);
    url[i - 11] = 0;
}
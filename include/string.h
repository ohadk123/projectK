#ifndef STRING_H
#define STRING_H

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef size_t
typedef unsigned int size_t;
#endif

// void *memcpy(void * restrict s1, const void * restrict s2, size_t n);
// void *memmove(void *s1, const void *s2, size_t n);
// char *strcpy(char * restrict s1, const char * restrict s2);
// char *strncpy(char * restrict s1, const char * restrict s2, size_t n);
// char *strcat(char * restrict s1, const char * restrict s2);
// char *strncat(char * restrict s1, const char * restrict s2, size_t n);
// int memcmp(const void *s1, const void *s2, size_t n);
// int strcmp(const char *s1, const char *s2);
// int strcoll(const char *s1, const char *s2);
// int strncmp(const char *s1, const char *s2, size_t n);
// size_t strxfrm(char * restrict s1, const char * restrict s2, size_t n);
// void *memchr(const void *s, int c, size_t n);
// char *strchr(const char *s, int c);
// size_t strcspn(const char *s1, const char *s2);
// char *strpbrk(const char *s1, const char *s2);
// char *strrchr(const char *s, int c);
// size_t strspn(const char *s1, const char *s2);
// char *strstr(const char *s1, const char *s2);
// char *strtok(char * restrict s1, const char * restrict s2);
void *memset(void *s, int c, size_t n);
// char *strerror(int errnum);
// size_t strlen(const char *s);

#endif // STRING_H

#include "../main.h"
#include <limits.h>
/**
 * main - simple test cases
 * Return: 0 successful
 */
int main(void)
{
	long int l = UINT_MAX + 1024;
	int len;
	unsigned int ui;
	void *addr;

	len = _printf("Let's try to printf a simple sentence.\n");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;

	_printf("===== Custom format =====\n");
	_printf("%S\n", "Best\nSchool");
	_printf("===== Printing Binary =====\n");
	_printf("[%b]", -1024);
	_printf("[%b]\n", UINT_MAX);
	_printf("[%b]\n", l);
	_printf("===== Printing Chars && Strings =====\n");
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("===== Printing ROT13 =====\n");
	_printf("[Complete the sentence: You %R nothing, Jon Snow.]\n", "xabj");
	_printf("[%R]\n", "Guvf fragrapr vf ergevrirq sebz in_netf!");
	_printf("===== Printing Reverse Order =====\n");
	_printf("[%r]\n", "Let's try to printf a simple sentence.");
	_printf("[%r]\n", "Hello world");
	_printf("Unknown:[%r]\n", "Len");
	_printf("===== Printing Int && Digits =====\n");
	_printf("Length:[%d, %i]\n", len, len);
	_printf("Negative:[%d]\n", -762534);
	_printf("===== Printing Unsigned Int =====\n");
	_printf("Unsigned:[%u]\n", ui);
	_printf("[%u]\n", l);
	_printf("[There is %u bytes in %u KB]\n", 1024, 1);
	_printf("===== Printing Octal =====\n");
	_printf("Unsigned octal:[%o]\n", ui);
	_printf("[%o]\n", l);
	_printf("===== Printing Hexadecimal =====\n");
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("[%X]\n", -1024);
	_printf("[%X]\n", '\n');
	_printf("[%X]\n", UINT_MAX);
	_printf("[%X]\n", l);
	_printf("===== Printing Percent =====\n");
	len = _printf("Percent:[%%]\n");
	_printf("===== Printing memory addresses =====\n");
	_printf("Address:[%p]\n", addr);
	_printf("%p\n", (void *)0x7fff5100b608);
	_printf("%p\n", NULL);
	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	_printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	return (0);
}

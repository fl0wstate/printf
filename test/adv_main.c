#include "../main.h"
#include <limits.h>

/**
 * main - simple test cases
 * Return: 0 successful
 */
int main(void)
{
	long int l = UINT_MAX + 1024;
	int len, len2;
	unsigned int ui;
	char *hello = "Hello";
	void *addr;
	/*long int res = INT_MAX + 1024;*/
	_printf("===== Printing Binary =====\n");
	_printf("[%b]", -1024);
	_printf("[%b]\n", UINT_MAX);
	_printf("[%b]\n", l);
	_printf("===== Printing ROT13 =====\n");
	_printf("[Complete the sentence: You %R nothing, Jon Snow.]\n", "xabj");
	_printf("[%R]\n", "Guvf fragrapr vf ergevrirq sebz in_netf!");
	ui = (unsigned int)INT_MAX + 1024;
	addr = (void *)0x7ffe637541f0;
	_printf("===== Printing Reverse Order =====\n");
	_printf("[%r]\n", "Let's try to printf a simple sentence.");
	_printf("[%r]\n", "Hello world");
	_printf("Unknown:[%r]\n", "Len");
	_printf("===== Printing Int && Digits =====\n");
	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	_printf("Length:[%d, %i]\n", len, len);
	printf("Length:[%d, %i]\n", len2, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("===== Printing Unsigned Int =====\n");
	_printf("Unsigned:[%u]\n", ui);
	printf("Unsigned:[%u]\n", ui);
	_printf("[%u]\n", -1024);
	_printf("[%u]\n", -1);
	printf("%u\n", -1024);
	_printf("[%u]\n", 1024);
	printf("%u\n", 1024);
	_printf("[%u]\n", 0);
	printf("%u\n", 0);
	printf("%u\n", -1);
	_printf("[%u]\n", UINT_MAX);
	printf("%u\n", UINT_MAX);
	_printf("[%u]\n", l);
	printf("%u\n", UINT_MAX + 1024);
	_printf("[There is %u bytes in %u KB]\n", 1024, 1);
	_printf("===== Printing Octal =====\n");
	_printf("Unsigned octal:[%o]\n", ui);
	printf("Unsigned octal:[%o]\n", ui);
	_printf("[%o]\n", l);
	printf("%o\n", UINT_MAX + 1024);
	/*_printf("%X + %X = %X\n", INT_MAX, INT_MAX, res);*/
	_printf("[%u == %o == %x == %X]\n", 1024, 1024, 1024, 1024);
	printf("%u == %o == %x == %X\n", 1024, 1024, 1024, 1024);
	_printf("===== Printing Hexadecimal =====\n");
	_printf("%x\n", hello);
	_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	_printf("[%X]\n", -1024);
	printf("%X\n", -1024);
	_printf("[%X]\n", UINT_MAX);
	printf("%X\n", UINT_MAX);
	_printf("[%X]\n", l);
	printf("%X\n", UINT_MAX + 1024);
	_printf("===== Printing Chars && Strings =====\n");
	_printf("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	printf("String:[%s]\n", "I am a string !");
	_printf("===== Printing Percent =====\n");
	len = _printf("Percent:[%%]\n");
	len2 = printf("Percent:[%%]\n");
	_printf("===== Printing digits =====\n");
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("===== Printing memory addresses =====\n");
	_printf("%p\n", hello);
	printf("%p\n", hello);
	_printf("Address:[%p]\n", addr);
	printf("Address:%p\n", addr);
	_printf("%p\n", (void *)0x7fff5100b608);
	_printf("%p\n", NULL);
	_printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
	_printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
	_printf("Can you print an address?\n%p\nNice!\n", (void *)-1);
	_printf("%pppp\n", (void *)0x7fff5100b6f8);
	return (0);
}

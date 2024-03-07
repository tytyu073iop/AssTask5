#include <iostream>

int main() {
	{
		short b;
		std::cout << "enter bx:";
		std::cin >> b;
		int a;
		_asm {
			xor ebx, ebx
			xor eax, eax
			mov bx, b
			mov ecx, 16 // amount of bits
			lox:
			push bx
				and bx, 1
				cmp bx, 1
				jne ex
				inc eax
				ex :
			pop bx
				shr bx, 1
				loop lox
				mov a, eax
		}
		std::cout << "amount of 1 is " << a << '\n';
	}
	//
	std::cout << "task two:\n";
	{
		int b;
		std::cout << "enter ebx:";
		std::cin >> b;
		_asm {
			mov eax, b
			mov ebx, eax
			shl eax, 4
			sub eax, ebx
			mov b, eax
		}
		std::cout << "result is: " << b << '\n';
	}

}
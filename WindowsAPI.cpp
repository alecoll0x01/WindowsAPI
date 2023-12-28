// WindowsAPI.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <Windows.h>

int showWindow() {
	LPCWSTR titulo = L"Mente Binária";

	int ret = MessageBox(nullptr,
		L"Voce quer gerar um arquivo de Log?",
		titulo,
		MB_YESNO | MB_ICONQUESTION);

	return ret;
}

int main()
{
	HANDLE hFile = CreateFile(L"log.txt",
		GENERIC_WRITE,
		0,
		nullptr,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		nullptr);

	if (hFile == INVALID_HANDLE_VALUE) {
		return EXIT_FAILURE; // expande para 1
	}

	int window = showWindow();

	if (window == IDNO) {
		return EXIT_SUCCESS;
	}

	LPCSTR texto = "Programando usando a API do Windows";
	size_t tam = lstrlenA(texto);

	if (WriteFile(hFile, texto, tam, nullptr, nullptr) == FALSE) {
		return EXIT_FAILURE;
	}

	CloseHandle(hFile);

}
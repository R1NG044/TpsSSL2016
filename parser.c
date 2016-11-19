/*
	UTN FRBA
	Trabajo Practico Sintaxis y Semantica de los Lenguajes
	Analizador Sintactico Simple
	Profesor: Jose Maria Sola
-	Integrantes:
		Illi, Santiago.
		Bio, Ronan.
		Kim, Elias.
		Gonzalez, Martin.
		Matias Veron Peralta

*/



#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int getClosingChar(int openChar){
	return openChar == '{' ? '}' : openChar == '(' ? ')' : openChar == '[' ? ']' : '1'; 
}

int main(void)
{

// First State : NormalCharacters

// Remaining States: Slash, CommentInLine, ComemntBetweenSlashes, String, Asterisk, End.

	int currentChar;

	Push('$');

	NormalCharacters:
		switch(currentChar = getchar())
		{
			case '"':
				goto String;
			case '\'':
				goto Characters;
			case EOF:
				goto End;
			default:
				goto SpecialCharacters;
		}

	SpecialCharacters:
		switch(currentChar)
		{
			case '(':
			case '{':
			case '[':
				Push(getClosingChar(currentChar));
				goto NormalCharacters;

			case ')':
			case '}':
			case ']':
				if (Pop() == currentChar) goto NormalCharacters;
				goto Error;
			case EOF:
				goto Error;
			default:
				goto NormalCharacters;
		}

	Characters:

		switch(currentChar = getchar())				
		{			
			case '\\':
				currentChar = getchar();
				goto Characters;
			case '\'':
				goto NormalCharacters;
			case EOF:
				goto Error;
			default:
				goto Characters;
		}


	String:
		switch(currentChar = getchar())	
		{			
			case '\\':
				currentChar = getchar();
				goto String;
			case '"':
				goto NormalCharacters;
			case EOF:
				goto Error;
			default:
				goto String;
		}



	End:
	if (Pop() != '$') goto Error;
	printf("%s\n", "El programa se ha ejecutado correctamente");
	return 0;
	Error:
	printf("%s\n", "El programa parser fallo");



return 0;

}
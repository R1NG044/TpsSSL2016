/*
	UTN FRBA
	Trabajo Practico Sintaxis y Semantica de los Lenguajes
	Removedor de Comentarios
	Profesor: Jose Maria Sola
-	Integrantes:
		Illi, Santiago.
		Bio, Ronan.
		Kim, Elias.
		Gonzalez, Martin.
		Matias Veron Peralta

*/


#include <stdio.h>



int main(void){

// First State : NormalCharacters
	int lastChar;
	int currentChar;

	NormalCharacters:
		switch(currentChar = getchar()){

			case '/':
				lastChar = currentChar;
				goto Slash;
			case '"':
				putchar(currentChar);
				goto String;
			case EOF:
				goto End;
			default:
				putchar(currentChar);
				goto NormalCharacters;
		}

	Slash:
		switch(currentChar = getchar()){
			case '/':
				putchar(' ');
				goto ComentaryInLine;
			case '*':
				putchar(' ');
				goto ComentaryBetweenSlashes;
			default:
				putchar(lastChar);
				putchar(currentChar);
				goto NormalCharacters;
		}

	ComentaryInLine:
		switch(currentChar = getchar()){

			case '\n':
				putchar(currentChar);
				goto NormalCharacters;
			case EOF:
				goto End;
			default:
				goto ComentaryInLine;
		}

	ComentaryBetweenSlashes:
		switch(currentChar = getchar()){

			case EOF:
				goto End;
			case '*':
				goto Asterisk;
			default:
				goto ComentaryBetweenSlashes;
		}

	Asterisk:
		if (getchar() == '/') { goto NormalCharacters; }
		goto ComentaryBetweenSlashes;		

	String:
		switch(currentChar = getchar()){

			case '\\':
				putchar(currentChar);
				putchar(getchar());
				goto String;
			case '"':
				putchar(currentChar); 
				goto NormalCharacters;
			case EOF:
				goto End;
			default:
				putchar(currentChar);
				goto String;
		}

	End:
	printf("%s\n", "El programa para remover los comentarios se ha ejecutado correctamente");

		return 0;

}

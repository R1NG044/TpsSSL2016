#include <stdio.h>

int main(){
/*


//
pepeppepeepeppepepee
*/




/*
a
a
a
a

*/
	int linesCount = 0;
	int charCount = 0;
	int spaceCount = 0;
	int wordCount = 0;

	Out: // comentario
		switch(getchar()){
			case ' ' :
			case '\t' :
				charCount++;
				spaceCount++;
				goto Out;
			case '\n' :
				charCount++;  // comentarioooooooooooooooooooooooooooooooooooooooooooooooooooooo
				linesCount++;
				goto Out;
			case EOF :
				goto End;
			default :
				charCount++;
				goto In;
		}

	In:
		switch(getchar()){
			case ' ' :
			case '\t' :
			wordCount++;
			charCount++;
			spaceCount++;
			goto Out;
			case '\n' :
				charCount++;
				linesCount++;
				goto Out;
			case EOF :
				goto End;
			default :
				charCount++;
				goto In;
		}


/*com*/	printf("%s", "\"asdasdasdas\"asdasdasdasdas");

	End:/* asdasdasd */
		printf("%s%d\n%s%d\n%s%d\n%s%d\n", "La cantidad de caracteres es ", charCount,"La cantidad de espacios es ", spaceCount,"La cantidad de lineas es ", linesCount,"La cantidad de palabras es ", wordCount );
		return 0;

}

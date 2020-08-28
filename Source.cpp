/*This program combines multiple text files into a single one*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <string.h>
int main()
{
	FILE* f_combine,* f_final;
	int nr_f, nr_c, i, k;
	char filename[50], final[50], buff[500];
	printf("Enter the number of final files: ");
	scanf_s("%d", &nr_f); // We read the number of final files desired
	
	for (i = 0; i < nr_f; i++)
	{
		printf("enter the name of the final file: \n"); 
		scanf("%s", final); // We read the filename that the generated file will have
		printf("lab %d\n", i + 1);
		printf("enter the number of files you want to combine: \n"); 
		scanf_s("%d", &nr_c); // We read the number of files we want to combine
		for (k = 0; k < nr_c; k++)
		{
			printf("enter filename %d: ", k + 1);
			scanf("%s", filename); // We enter the name of the files we want to combine (with the extension)
			f_final = fopen(final, "a");
			f_combine = fopen(filename, "r");
			
			if (f_combine != NULL)
			{
				while (!feof(f_combine))
				{
					fgets(buff, 500, f_combine);
					if (f_final != NULL)
					{
						fputs(buff, f_final);
						fprintf(f_final,"\n\n");
					}
					else printf("error creating final file\n");
				}

			}
			else printf("error opening file to combine\n");
			fclose(f_combine);
			fclose(f_final);

		}
		



	}

	return 0;
}

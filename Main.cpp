#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void menu(int matrix[])
{
	srand(time(NULL));

	int rowMatrix;
	int columnMatrix;
	int numbersMatrix;
	int directionMatrix;
	int stepMatrix;
	int randomValue;
	int count;
	int unrotatedMatrix[matrix[0]][matrix[1]];
	int rotatedMatrix[matrix[0]][matrix[1]];

	int value = 1;
	
	//UnrotatedMatrix'e rastgele degerler assign ediliyor.
	for (int i = 0; i < matrix[0]; i++)
				{
					for (int j = 0; j < matrix[1]; j++)
					{
						unrotatedMatrix[i][j] = (rand() % matrix[3]) + 1;
					}
				}

	while (value >= 1 && value <= 5)
	{		
		printf("---------------------------------------");
		printf("\n{");
		printf("%d,%d,%d,%d,%d", matrix[0], matrix[1], matrix[2], matrix[3], matrix[4]);
		printf("}");

		printf("\n\n1. Start the program\n");
		printf("2. Create a matrix\n");
		printf("3. Direction\n");
		printf("4. Step number\n");
		printf("5. Exit\n\n");

		//Kullanici secenekler arasindan bir tanesini seciyor.
		int value;
		printf("Choose an option from above: \n-> ");
		scanf("%d", &value);

		switch (value)
		{
			case 1:

				//UnrotatedMatrix yazdiriliyor.
				for (int i = 0; i < matrix[0]; i++)
				{
					for (int j = 0; j < matrix[1]; j++)
					{
						if (unrotatedMatrix[i][j] != NULL)
						{
							printf("%d ", *( *(unrotatedMatrix + i) + j));
						}
					}

					printf("\n");
				}

				printf("---------------------------------------");

				//Eger donme yonu sagsa.
				if (matrix[2] == 1)
				{
					for (int i = 1; i < matrix[0] - 1; i++)
					{
						//Matrix'in ortasinda kalan rotate etmeyecek sayilar rotatedMatrix'e assign ediliyor.
						for (int j = 1; j < matrix[1] - 1; j++)
						{
							rotatedMatrix[i][j] = unrotatedMatrix[i][j];
						}
					}

					while (matrix[4] > 0)
					{
						//Step 0 oluncaya kadar matrix 1'er kez saga kayiyor.
						for (int j = 0; j < matrix[1] - 1; j++)
						{
							//Matrix'in ust kismi saga kaydiriliyor.
							rotatedMatrix[0][j + 1] = unrotatedMatrix[0][j];
						}						

						for (int i = 0; i < matrix[0] - 1; i++)
						{
							//Matrix'in sag kismi asagi kaydiriliyor.
							rotatedMatrix[i + 1][matrix[1]-1] = unrotatedMatrix[i][matrix[1]-1];
						}

						for (int j = matrix[1] - 1; j > 0; j--)
						{
							//Matrix'in alt kismi sola kaydiriliyor.
							rotatedMatrix[matrix[0]-1][j - 1] = unrotatedMatrix[matrix[0]-1][j];
						}

						for (int i = matrix[0] - 1; i > 0; i--)
						{
							//Matrix'in sol kismi yukari kaydiriliyor.
							rotatedMatrix[i - 1][0] = unrotatedMatrix[i][0];
						}

						for (int i = 0; i < matrix[0]; i++)
						{
							//Step sayisi 1'den farkli olabileceginden her defasinda esitliyoruz.
							for (int j = 0; j < matrix[1]; j++)
							{
								unrotatedMatrix[i][j] = rotatedMatrix[i][j];
							}
						}

						matrix[4]--;
					}
				}
				
				//Eger donme yonu solsa.
				else if (matrix[2] == -1)
				{
					for (int i = 1; i < matrix[0] - 1; i++)
					{
						//Matrix'in ortasinda kalan rotate etmeyecek sayilar rotatedMatrix'e assign ediliyor.
						for (int j = 1; j < matrix[1] - 1; j++)
						{
							rotatedMatrix[i][j] = unrotatedMatrix[i][j];
						}
					}

					while (matrix[4] > 0)
					{
						//Step 0 oluncaya kadar matrix 1'er kez sola kayiyor.
						for (int i = matrix[1] - 1; i > 0; i--)
						{
							//Matrix'in ust kismi sola kaydiriliyor.
							rotatedMatrix[0][i - 1] = unrotatedMatrix[0][i];
						}

						for (int i = 0; i < matrix[0] - 1; i++)
						{
							//Matrix'in sol kismi asagi kaydiriliyor.
							rotatedMatrix[i + 1][0] = unrotatedMatrix[i][0];
						}

						for (int i = 0; i < matrix[1] - 1; i++)
						{
							//Matrix'in alt kismi saga kaydiriliyor.
							rotatedMatrix[matrix[1] - 1][i + 1] = unrotatedMatrix[matrix[1] - 1][i];
						}

						for (int i = matrix[0] - 1; i > 0; i--)
						{
							//Matrix'in sag kismi yukari kaydiriliyor.
							rotatedMatrix[i - 1][matrix[0] - 1] = unrotatedMatrix[i][matrix[0] - 1];
						}

						for (int i = 0; i < matrix[0]; i++)
						{
							//Step sayisi 1'den farkli olabileceginden her defasinda esitliyoruz.
							for (int j = 0; j < matrix[1]; j++)
							{
								unrotatedMatrix[i][j] = rotatedMatrix[i][j];
							}
						}

						matrix[4]--;
					}
				}

				printf("\n");

				//RotatedMatrix yazdiriliyor.
				for (int i = 0; i < matrix[0]; i++)
				{
					for (int j = 0; j < matrix[1]; j++)
					{
							printf("%d ", *( *(rotatedMatrix + i) + j));
					}

					printf("\n");
				}

				break;
			case 2:
				//Matrix'in satiri, sutunu ve deger araligi kullanici tarafindan giriliyor.
				printf("Matrix row size (1-9): \n-> ");
				scanf("%d", &rowMatrix);
				
				//Satir icin kontroller saglaniyor.
				if (rowMatrix < 1 || rowMatrix > 9) {
					rowMatrix = 1;
					printf("Wrong value has been entered\n");
				}
				
				printf("Matrix column size (1-9): \n-> ");
				scanf("%d", &columnMatrix);
				
				//Sutun icin kontroller saglaniyor.
				if (columnMatrix < 1 || columnMatrix > 9) {
					columnMatrix = 1;
					printf("Wrong value has been entered\n");
				}
				
				printf("Enter a value bigger than 0 lower than 100 for matrix interval: \n-> ");
				scanf("%d", &numbersMatrix);
			
				//Deger araligi icin kontroller saglaniyor.
				if (numbersMatrix <= 0 || numbersMatrix >= 100)
				{
					numbersMatrix = 1;
					printf("Wrong value has been entered\n");
				}	

				matrix[0] = rowMatrix;
				matrix[1] = columnMatrix;
				matrix[3] = numbersMatrix;

				break;
			case 3:
				//Kullanici tarafindan yon bilgisi giriliyor.
				printf("Enter a direction for a matrix (right=1 or left=-1): \n-> ");
				scanf("%d", &directionMatrix);

				//Yon icin kontroller saglaniyor.
				if (directionMatrix == 1 || directionMatrix == -1)
				{
					matrix[2] = directionMatrix;
				} else {
					printf("Wrong value has been entered\n");
				}

				break;
			case 4:
				//Kullanici tarafindan adim sayisi giriliyor.
				printf("Matrix step number (1-99): \n-> ");
				scanf("%d", &stepMatrix);

				//Adim sayisi icin kontroller saglaniyor.
				if (stepMatrix >= 1 && stepMatrix <= 99) {
				matrix[4] = stepMatrix;
				} else {
					printf("Wrong value has been entered\n");
				}
				break;
			case 5:
				//Bu secenek secildiginde program durduruluyor.
				exit(5);
				break;
			default:
				printf("You've entered invalid value\n");
		}
	}
}

int main()
{
	int matrix[5] = { 5, 5, 1, 99, 5 };
	menu(matrix);
}

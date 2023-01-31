#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("Will you find the secret code ?\nPlease enter a valid guess\n");
		int i, j, attempts, l;
		char user_input[5];
		int well_placed;
		int misplaced;
		attempts = 0;

		while (attempts < 10 && well_placed != 4)
		{
			int length = read(STDIN_FILENO, user_input, 5);
		
			well_placed = 0;
			misplaced = 0;

			if (length > 4)
				printf("Wrong input");

			for (i = 0; i < 4; i++)
			{
				for (j = 0; j < 4; j++)
				{
					if ((user_input[i] == argv[1][j]) && (i == j))
						well_placed++;
					if ((user_input[i] == argv[1][j]) && (i != j))
						misplaced++;
				}
			}
			if (well_placed != 4)
				printf("Well placed pieces:%d\nMisplaced pieces:%d\n", well_placed,misplaced);
			else
			{
				printf("Congratz! You did it !\n");
				break;
			}
			attempts++;
		}
	}

	return (0);
}

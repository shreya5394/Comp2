#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"

int main()
{
	VECTOR hVector;
	int i;
	hVector = vector_init_default();
	if (hVector == NULL)
	{
		printf("call to vector_init_default failed - exiting ...\n");
		exit(1);
	}

	for (i = 0; i < 200; i++)
	{

		if (!vector_push_back(hVector, i * i))
		{
			printf("vector_pushback_failed - exiting\n");
			exit(1);
		}
	}
	
	printf("Vector[77] is %d\n", *vector_at(hVector, 77));
	*vector_at(hVector, 77) = 78;
	printf("Vector[77] is %d\n", *vector_at(hVector, 77));

	vector_pop_back(hVector);
	vector_pop_back(hVector);

	vector_output(hVector);


	vector_destroy(&hVector);

	return 0;
}
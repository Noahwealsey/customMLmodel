#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int trainData[][2] = {
	{1, 2},
	{2, 4},
	{3, 6},
	{4, 8}
};

#define train_size (sizeof(trainData)/(sizeof(trainData[0])))
#define MAX_ITER 500

float rand_float(void){
	return (float)rand()/(float)RAND_MAX;
}

float cost(float w, float b){
		
		float result = 0.;
		for(int i = 0; i < train_size; i++){
			float x = trainData[i][0];
			float y = x*w + b;
			float nudgeMent = y - trainData[i][1];
			result += nudgeMent*nudgeMent;
	}
	
	result /= train_size;
	return result;

}

int main(){
	srand(time(0));
	float eps = 1e-3;
	float rate = 1e-3;
	float b = rand_float();
	float w = rand_float()*10;
	for(int i = 0 ; i < MAX_ITER; i++){
		float derivatew = (cost(w +  eps, b) - cost(w, b))/eps;
		float derivateb = (cost(w , b + eps) - cost(w, b))/eps;
		w -= rate*derivatew;
		b -= rate*derivateb;
		printf("the result is %f : the bias is %f\n : the cost is %f\n", w, b, cost(w, b));
	}
		
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

float trainData[][3] = {
	{0, 0, 0},
	{1, 0, 1},
	{0, 1, 1},
	{1, 1, 1}
	
};	
#define train_size (sizeof(trainData)/(sizeof(trainData[0])))
#define MAX_ITER 10000

float rand_float(void){
	return (float)rand()/(float)RAND_MAX;
}

float sigmoidf(float x){
	return 1.f/(1.f + expf(-x)); 	
}

float cost(float w1,float w2,float b){
		
		float result = 0.;
		for(int i = 0; i < train_size; i++){
			float x1 = trainData[i][0];
			float x2 = trainData[i][1];
			float y = sigmoidf(x1*w1 + x2*w2 + b);
			float nudgeMent = y - trainData[i][2];
			result += nudgeMent*nudgeMent;
	}
	
	result /= train_size;
	return result;

}

int main(){
	srand(time(0));
	float eps = 1e-5;
	float rate = 1e-1;
	float b = rand_float();
	float w1 = rand_float();
	float w2 = rand_float();
	for(int i = 0 ; i < MAX_ITER; i++){
		float c = cost(w1, w2, b);
		printf("%f\n", c);	
		float dw1 = (cost(w1 +  eps, w2,  b) - c)/eps;
		float dw2 = (cost(w1, w2 + eps,  b) - c)/eps;
		float db = (cost(w1, w2 , b + eps) - c)/eps;
		w1 -= rate*dw1;
		w2 -= rate*dw2;
		b -= rate*db;
		//printf("w1 : %f : w2 : %f : the bias is %f : the cost is %f\n", w1, w2, b, cost(w1,w2, b));

	}
	for(size_t i = 0; i < 2; i++){
		for(size_t j = 0; j < 2; j++){
		//	printf("%zu | %zu : %f\n",i, j, sigmoidf(i*w1 + j*w2 + b) )	;
		}
	}
		
	return 0;
}

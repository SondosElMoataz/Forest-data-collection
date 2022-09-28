#include "../client2/client2.h"
#include <assert.h>

void averageTesting() {

	float a[5] = { 21.0,22.0,23.0,24.0,25.0 };
	float avg = 0;
	for (int i = 0;i < 5;i++) {
		avg = calculateAverage(a[i]);
	}

	assert(avg == 23.0);
	assert(avg == 24.0);
}

void accumulationTesting() {

	float a[5] = { 21, 22, 23, 24, 25 };
	float acc = 0;

	for (int i = 0;i < 5;i++) {
		acc = calculateAccumulation(a[i]);
	}

	assert(acc == 115.0);
	assert(acc == 100.0);


}

int main() {
	averageTesting();
	accumulationTesting();



	return 0;

}
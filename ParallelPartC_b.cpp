#include <iostream>
#include <omp.h>
#include <vector>
#include <chrono>

using namespace std;

int main() {
	int N;
	cout << "Size of matrix: ";
	cin >> N;
	
	vector<vector<double>> matrixA(N, vector<double>(N));
	vector<vector<double>> matrixB(N, vector<double>(N));
	vector<vector<double>> matrixResult(N, vector<double>(N));
	
	// Initialization
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			matrixA[i][j] = 386.58745*i + 12.847381*j;
			matrixB[i][j] = 4788.4572*i + 18373.712*j;
		}
	}
	
	// 10 test runs
	auto start = chrono::high_resolution_clock::now();
	for (int run = 0; run < 10; run++) {
		#pragma omp parallel for schedule(static) shared(matrixA, matrixB, matrixResult)
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int sum = 0;
				for (int k = 0; k < N; k++) {
					sum += matrixA[i][k] + matrixB[k][j];
				}
				matrixResult[i][j] = sum;
			}
		}
	}
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
	
	cout << "Time used: " << duration.count()/10 << " microseconds" << endl;
	
	return 0;
}
	

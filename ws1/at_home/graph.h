// Name: Anh Minh Hieu Nguyen
// Email: amhnguyen@myseneca.ca
// Student ID: 151432168  
#ifndef NAMESPACE_GRAPH_H
#define NAMESPACE_GRAPH_H
#include <iostream>
namespace sict {
#define MAX_NO_OF_SAMPLES 20
	void getSamples(int samples[], int noOfSamples);
	// Displays the user interface menu
	int findMax(int samples[], int noOfSamples);
	// Prints a scaled bar relevant to the maximum value in samples array
	void printBar(int val, int max);
	// Prints a graph comparing the sample values visually 
	void printGraph(int samples[], int noOfSamples);
}
#endif

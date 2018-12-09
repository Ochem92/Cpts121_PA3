#include "PA3.h"

void run_app()
{
	//Declare used variables in the function
	//First declare the variables provided from the source file

	//First varible is the student ID# from file
	int ID1 = 0, ID2 = 0, ID3 = 0, ID4 = 0, ID5 = 0;

	//declare the gpa variables from the file
	double GPA1 = 0.0, GPA2 = 0.0, GPA3 = 0.0, GPA4 = 0.0, GPA5 = 0.0;

	//store class standing variable from file
	int class1 = 0, class2 = 0, class3 = 0, class4 = 0, class5 = 0;

	//store class age from files
	double age1 = 0.0, age2 = 0.0, age3 = 0.0, age4 = 0.0, age5 = 0.0;

	//Need to make variables for the intial calculations used for mean, deviation..etc calculations
	double gpa_sum = 0.0, class_sum = 0.0, age_sum = 0.0;

	//store averages for output
	double mean_gpa = 0.0, mean_class = 0.0, mean_age = 0.0;

	//store gpa deviations from the class mean
	double gpa_dev1 = 0.0, gpa_dev2 = 0.0, gpa_dev3 = 0.0, gpa_dev4 = 0.0, gpa_dev5 = 0.0;

	//store claculated gpa variance for outpu
	double gpa_var = 0.0;

	//store gpa standard deviation for output
	double gpa_standard_dev = 0.0;

	//store gpa max and min values for output
	double gpa_max = 0.0, gpa_min = 0.0;


	


	//Umm. assigns infile and outfile as a FILE with no number return? I really dont know, thats what the slides say
	FILE *infile = NULL;
	FILE *outfile = NULL;

	//Open the documents for input and output, still just following the slides
	infile = fopen("input.dat", "r");
	outfile = fopen("output.dat", "w");

	//Read the data from the input files and assign the functions to the variables for student #1
	//Im assuming that the files will be read row by row, otherwise...idk what to do.
	//Student #1
	ID1 = read_intiger(infile);
	GPA1 = read_double(infile);
	class1 = read_intiger(infile);
	age1 = read_double(infile);

	//student#2
	ID2 = read_intiger(infile);
	GPA2 = read_double(infile);
	class2 = read_intiger(infile);
	age2 = read_double(infile);

	//student#3
	ID3 = read_intiger(infile);
	GPA3 = read_double(infile);
	class3 = read_intiger(infile);
	age3 = read_double(infile);

	//student#4
	ID4 = read_intiger(infile);
	GPA4 = read_double(infile);
	class4 = read_intiger(infile);
	age4 = read_double(infile);

	//student #5
	ID5 = read_intiger(infile);
	GPA5 = read_double(infile);
	class5 = read_intiger(infile);
	age5 = read_double(infile);

	//Calculate the mean GPA
	//First need to calculate sums
	gpa_sum = calculate_sum(GPA1, GPA2, GPA3, GPA4, GPA5);
	class_sum = calculate_sum(class1, class2, class3, class4, class5);
	age_sum = calculate_sum(age1, age2, age3, age4, age5);

	// Now using the sums for calculations of the averages
	mean_gpa = calculate_mean(gpa_sum, 5);
	mean_class = calculate_mean(class_sum, 5);
	mean_age = calculate_mean(age_sum, 5);

	//calculate the individual students deviation from the class mean values
	gpa_dev1 = calculate_deviation(GPA1, mean_gpa);
	gpa_dev2 = calculate_deviation(GPA2, mean_gpa);
	gpa_dev3 = calculate_deviation(GPA3, mean_gpa);
	gpa_dev4 = calculate_deviation(GPA4, mean_gpa);
	gpa_dev5 = calculate_deviation(GPA5, mean_gpa);

	//calculate the variance for all of the students GPAs
	gpa_var = calculate_variance(gpa_dev1, gpa_dev2, gpa_dev3, gpa_dev4, gpa_dev5, 5);

	//calculate the standard deviation of the GPAs
	gpa_standard_dev = calculate_standard_deviation(gpa_var);

	//find the highest GPA provided
	gpa_max = find_max(GPA1, GPA2, GPA3, GPA4, GPA5);

	//find lowest gpa
	gpa_min = find_min(GPA1, GPA2, GPA3, GPA4, GPA5);

	print_double(outfile, mean_gpa);
	print_double(outfile, mean_class);
	print_double(outfile, mean_age);
	print_double(outfile, gpa_standard_dev);
	print_double(outfile, gpa_max);
	print_double(outfile, gpa_min);


	fclose(infile);
	fclose(outfile);


}

double read_double(FILE *infile)
{
	double number = 0.0;
	fscanf(infile, "%lf", &number);
	return number;

}


int read_intiger(FILE *infile)
{
	int number = 0;
	fscanf(infile, "%d", &number);
	return number;
}


double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double sum = 0.0;
	sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}


double calculate_mean(double sum, int number)
{
	double mean = 0.0;
	mean = sum / ((double)number);
	return mean;

}


double calculate_deviation(double number, double mean)
{
	double deviation = 0.0;
	deviation = number - mean;
	return deviation;
}


double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	double variance = 0.0, sum = 0.0;
	sum = calculate_sum((deviation1*deviation1), (deviation2*deviation2), (deviation3*deviation3), (deviation4*deviation4), (deviation5*deviation5));
	variance = calculate_mean(sum, number);
	return variance;
}

double calculate_standard_deviation(double variance)
{
	double standard_deviation = 0.0;
	standard_deviation = sqrt(variance);
	return standard_deviation;
}

double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double max_value = number1;
	if (max_value < number2)
		{
			max_value = number2;
		}
	if (max_value < number3)
		{
			max_value = number3;
		}
	if (max_value < number4)
		{
			max_value = number4;
		}
	if (max_value < number5)
		{
			max_value = number5;
		}
	return max_value;
}

double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double min_value = number1;
	if (min_value > number2)
		{
			min_value = number2;
	}
	if (min_value > number3)
		{
			min_value = number3;
		}
	if (min_value > number4)
		{
			min_value = number4;
		}
	if (min_value > number5)
		{
			min_value = number5;
		}
	return min_value;
}

void print_double(FILE *outfile, double number)
{

	printf("output value %0.2lf printed to document %s \n", number, "output.dat");
	fprintf(outfile,"%0.2lf\n", number);
}
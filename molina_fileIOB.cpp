/*
Dario Molina
10/22/15
Descrition: Write a program that will utilize a text input file(scores.txt) and compute the listed specifications.  Write a program to compute numberic grades for a course.

1. Allow the user to enter the name of the input file.  ( Which will always be "Scores.txt" for this example.

2. Your program will take the data, calculate certain values and send to an output file " results.txt".

3. The data i the output file will have the input file values, neatly formatted exactly! as seen in the example.

4.For each student in the input file, you will calculate the average of the scores and append to the respective line listing.

5.Also, determine the student who earns the highes average and list their name at the end of the file listing.*/
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
 
 double s1, s2, s3, s4, s5, s6;
 double  average, average1, average2, average3, average4, average5, average6;
 double min = 9999, max = -9999; 
 int count;
 string  firstName, lastName, maxStudent;
 char answer[20];
 
 ifstream fin;
 ofstream fout;
 
 cout << " Hello, please enter the file name: scores.txt.\n";
 cin >> answer;
 
  fin.open( answer);
  fout.open( "results.txt");
  
  if( fin.fail())
  {
    cout << "Error opening file input.\n";
    exit(1);
  
  }
  
  if( fout.fail())
  {
    cout << "Error opening output file.\n";
    exit(1);
  }
 
 while ( fin >> firstName >> lastName >> s1 >> s2 >> s3 >> s4 >> s5 >> s6)
{

  fout.setf(ios::fixed);
  fout.setf(ios::showpoint);
  fout.precision(2);
  fout.setf(ios::left);
  
  average = ( s1 + s2 + s3 + s4 + s5 + s6 ) / 6;
  
  fout << setw(10) << firstName << setw(10) << lastName;
  
  fout << setw(8) << s1 << setw(8) << s2 << setw(8) << s3 << setw(8) << s4 << setw(8) << s5  << setw(8) << s6 << setw(8) << average << endl;
  
  if ( average > max )
   {  
   
     max = average;
     maxStudent = firstName + " " + lastName;
   
   }

 

}

 fout <<"\nHighest Score: " << maxStudent << endl;

 fin.close();
 fout.close();

return 0;
} 

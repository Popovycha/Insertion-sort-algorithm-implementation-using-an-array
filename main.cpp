//CSC231_Artem_Popovych_Program_#_4
//CSC231-1301: Discrete Structures and Applications to Computer Science BMCC/CUNY Fall 2019
//Due date 12/09/2019
#include<iostream>
#include<fstream>
#include<ctime>
#include<stdlib.h>
using namespace std;
//quick sort
void quicksort(int arr[])
{
int i,j,temp=0;
for (i = 0; i < 9; i++)
for (j = 0; j < 10-i-1; j++)
if (arr[j] > arr[j+1])
  {
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp;
  }
}
//heap
void heap(int arr[],int n,int i)
{
int temp,f,r,large;
large = i;
f = 2 * i + 1;
r = 2 * i + 2;
if (f < n && arr[f] > arr[large])
large = f;
if (r < n && arr[r] > arr[large])
large = r;
if (large != i)
 {
temp = arr[i];
arr[i] = arr[large];
arr[large] = temp;
heap(arr,n,large);
 }
}
//heap sort
void heapsort(int arr[],int n)
{
int temp;
for (int i = n/ 2 - 1; i >= 0; i--)
heap(arr,n,i);
for (int i = n - 1; i >= 0; i--)
 {
temp = arr[0];
arr[0] = arr[i];
arr[i] = temp;
heap(arr,i,0);
 }
}
//main 
int main()
{
ofstream file;
//open the file to place a record of result
file.open("csc231_apopovych_program4.txt");
file << "CSC231-1301: BMCC/CUNY Fall 2019" << endl;
file << "Discrete Structures and Applications to Computer Science" << endl;
file<<"Program #4" << endl;
file << "Artem Popovych ID:23579191" << endl;

cout << "CSC231-1301: BMCC/CUNY Fall 2019" << endl;
cout << "Discrete Structures and Applications to Computer Science" << endl;
cout <<"Program #4" << endl;
cout << "Artem Popovych ID:23579191" << endl;
int n=10,arr[n],i;
//srand it used to change the seed of the rand
//time(0) is changed every time,so seed will change
srand(time(0));

file << "Before sorting:\n";
cout << "Before sorting:\n";
//loop to create elements randomly in array
for(i=0;i<10;i++)
{
//Generates 3 digit positive random integer numbers
arr[i] = (rand() % (999-100 +1)+100);
cout << arr[i]<< " ";
file << arr[i]<< " ";
}

//calling the function
quicksort(arr);
cout <<"\nAfter quick sort:\n";
file <<"\nAfter quick sort:\n";
//displays the array after sorting
for(i=0;i<10;i++)
{
file << arr[i]<< " ";
cout << arr[i]<< " ";
}
file << "\nBefore heap sorting:\n";
cout << "\nBefore heap sorting:\n";
//store random number in array
for(i=0;i<10;i++)
{
arr[i] = (rand() % (999-100 +1)+100);
file << arr[i]<< " ";
cout << arr[i]<< " ";
}
//calling the function
heapsort(arr,n);
file <<"\nAfter heap sort:\n";
cout <<"\nAfter heap sort:\n";
//display sorted array
for(i=0;i<10;i++)
{
file << arr[i]<< " ";
cout << arr[i]<< " ";
} 
return 0;
}
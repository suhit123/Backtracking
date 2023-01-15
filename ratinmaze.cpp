/*

Rat In A Maze Problem
You are given an integer N and a binary 2D array of size N*N. The given binary matrix represents a maze and a rat starts from the top left cell and has to reach to the bottom right cell of the maze. The rat can move in all the four directions: up, down, left and right.
In the given binary matrix, 0 signifies the cell is a dead end and 1 signifies the cell can be used to move from source to destination cell.
You have to print all the paths, following which rat can move from the top left cell to the bottom right cell of the given binary matrix.
Input Format
The first line of input contains an integer, that denotes the value of N.
Each of the following N lines denote rows of the binary matrix and contains either 0 or 1. Each row of the binary matrix contains N elements. 
Output Format :
Every possible solution has to be printed on a separate line. Each of the possible solution will have N*N elements, printed row wise and separated by space. The cells that are part of the path should be 1 and remaining all cells should be 0. Please refer to sample test cases for more clarity.   
Constraints
1 <= N <= 18
0 <= Number of cells with value 1 <= 15
Time Limit: 1 second
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 

Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Explanation:
 As described in the Sample Output 2, four paths are possible.
*/

#include<bits/stdc++.h>
using namespace std;
int question[11][11];
int answer[11][11];
void printallsol(int r,int c,int n){
  if (r == n - 1 && c == n - 1) {
	answer[r][c]=1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << answer[i][j] << " ";
      }
    }
    cout << endl;
	answer[r][c]=0;
    return;
  }
  if(r<0||c<0||r==n||c==n||question[r][c]==0||answer[r][c]==1){
	  return;
  }
  answer[r][c]=1;
  printallsol(r, c + 1, n);
  printallsol(r, c-1, n);
  printallsol(r+1, c, n);
  printallsol(r-1, c, n);
  answer[r][c]=0;
  return;
}
void ratinmaze(int r,int c,int n){
	memset(answer,0,11*11*sizeof(int));
	printallsol(r,c,n);
	return;
}
int main() {
	int size;
	cin>>size;
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cin>>question[i][j];
		}
	}
	ratinmaze(0,0,size);
	return 0;
}

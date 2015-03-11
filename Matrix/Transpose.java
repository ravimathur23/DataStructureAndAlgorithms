/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class Transpose{
	public int[][] A;
	Transpose(int[][] A){
		this.A = A;
	}
	
	public int[][] doTranspose(){
		int[][] B = new int[A[0].length][A.length];
		for(int i=0;i<A.length;i++){
			for(int j=0;j<A[i].length;j++){
				B[j][i] = A[i][j];
			}
		}
		return B;
	}
}
/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int[][] A = {{1,2,3},{4,5,6}, {7,8,9}};
		System.out.println(Arrays.deepToString(new Transpose(A).doTranspose()));
	}
}

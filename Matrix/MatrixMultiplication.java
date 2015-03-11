/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class MatrixMul{
	public int[][] A, B;
	MatrixMul(int[][] A, int[][] B){
		this.A = A; this.B = B;
	}
	
	public int[][] doMul(){
		int[][] C = new int[A.length][B[0].length];
		int sum;
		
		for(int i=0;i<A.length;i++){
			for(int j=0;j<B[0].length;j++){
				sum = 0;
				for(int k=0;k<B.length;k++){
					sum += (A[i][k]*B[k][j]);
				}
				
				C[i][j] = sum;
			}
		}
		return C;
	}
}

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int[][] A = {{1,2},
					 {4,5},
					 {7,8}};
		
		int[][] B = {{1,2,3},
					 {4,5,6}};

		System.out.println(Arrays.deepToString(new MatrixMul(A, B).doMul()));
	}
}

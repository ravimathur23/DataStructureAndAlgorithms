/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class MatrixComp{
	
	public int[][] A, B;
	MatrixComp(int[][] A, int[][] B){
		this.A = A;
		this.B = B;
	}
	public boolean isSame(){
		boolean flag = true;
		
		for(int i=0;i<A.length;i++){
			for(int j=0;j<A[i].length;j++){
				if(A[i][j] != B[i][j])
					flag = false;
			}
		}
		return flag;
	}	
}

/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		int[][] A = {{1,2,3},{4,5,6}};
		int[][] B = {{1,2,3},{4,5,6}};
		MatrixComp mat = new MatrixComp(A,B);
		System.out.println("IsSame = "+ mat.isSame());
	}
}

package FinalExam;

import java.util.Arrays;

public class ArraysCheck {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int[] A = {4, 3, 2, 4, 0};
		int[] B = {1, 2, 3, 4, 5};
		check(A,B);
		}
		
	public static boolean check(int[]A, int[]B) {
		Arrays.sort(A);
		Arrays.sort(B);
		if(A.length != B.length) {
			return false;
		}
		else {
			for(int i = 0;i < A.length; i++){
			       if(A[i]==B[i] || A[i]+1==B[i]){
			           continue;
			       }
			     else{  
			    	 System.out.println("false");
			    	 return false;
		}
		}
		System.out.println("true");
		return true;
	}
	}
	}





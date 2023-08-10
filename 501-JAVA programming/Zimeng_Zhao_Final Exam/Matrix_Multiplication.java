package FinalExam;

import java.util.ArrayList;

public class Matrix_Multiplication {

    public static ArrayList<int[][]> partition(int[][] A) {
        int[][] A11 = new int[A.length / 2][A.length / 2];
        int[][] A12 = new int[A.length / 2][A.length / 2];
        int[][] A21 = new int[A.length / 2][A.length / 2];
        int[][] A22 = new int[A.length / 2][A.length / 2];

        for (int i = 0; i < A.length / 2; i++) {
            for (int j = 0; j < A.length / 2; j++) {
                A11[i][j] = A[i][j];
            }
        }
        for (int i = 0; i < A.length / 2; i++) {
            for (int j = 0; j < A.length / 2; j++) {
                A12[i][j] = A[i][j + A.length / 2 ];
            }
        }
        for (int i = 0; i < A.length / 2; i++) {
            for (int j = 0; j < A.length / 2; j++) {
                A21[i][j] = A[i + A.length / 2 ][j];
            }
        }
        for (int i = 0; i < A.length / 2; i++) {
            for (int j = 0; j < A.length / 2; j++) {
                A22[i][j] = A[i + A.length / 2 ][j + A.length / 2 ];
            }
        }
        ArrayList<int[][]> output = new ArrayList<>();
        output.add(A11);
        output.add(A12);
        output.add(A21);
        output.add(A22);
        return output;
    }
    
    
    public static int sum(ArrayList<int[][]> A) { 
    	int[] determinant = new int[A.size()]; 
    	int sumOfDet = 0;
    	for(int i = 0; i < A.size(); i++) {
    	if(A.get(i).length == 2) {
    		determinant[i] = A.get(i)[0][0] * A.get(i)[1][1] - A.get(i)[0][1] * A.get(i)[1][0];
    		sumOfDet += determinant[i];
    		}
    	}
    	return sumOfDet; 
    }

//    public static int sumOfDet(ArrayList<int[][]> A) {
//    	int sumOfDet = 0;
//    	int[]a = new int[A.size()];
//    	for(int i = 0; i < A.size(); i++) {
//    		 a[i] = determinant(A.get(i));
//    		 sumOfDet += a[i];
//    	}
//    	return sumOfDet;
//    }
    
    public static void add(int A[][],int B[][],int C[][]){
        int n = A.length;
        for(int i = 0; i < n; i++){
            for(int j = 0;j < n; j++){
                C[i][j] = A[i][j] + B[i][j];
            }
        }
    }
    public static void merge(int result[][], int startI, int startJ, int original[][]) {
        int n = original.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
            	result[startI + i][startJ + j] = original[i][j];
            }
        }
    }

    public static int[][] recursiveMatrixMultiplication(int[][] A, int[][] B) {
        int n = A.length;
        int[][] C = new int[n][n];
        int[][] A11 = new int[n / 2][n / 2];
        int[][] A12 = new int[n / 2][n / 2];
        int[][] A21 = new int[n / 2][n / 2];
        int[][] A22 = new int[n / 2][n / 2];
        int[][] B11 = new int[n / 2][n / 2];
        int[][] B12 = new int[n / 2][n / 2];
        int[][] B21 = new int[n / 2][n / 2];
        int[][] B22 = new int[n / 2][n / 2];
        int[][] C11 = new int[n / 2][n / 2];
        int[][] C12 = new int[n / 2][n / 2];
        int[][] C21 = new int[n / 2][n / 2];
        int[][] C22 = new int[n / 2][n / 2];
        if (n == 1) {
            C[0][0] = A[0][0] * B[0][0];
        } else {
            ArrayList<int[][]> AA = partition(A);
            ArrayList<int[][]> BB = partition(B);
            ArrayList<int[][]> CC = partition(C);
            A11 = AA.get(0);
            A12 = AA.get(1);
            A21 = AA.get(2);
            A22 = AA.get(3);
            B11 = BB.get(0);
            B12 = BB.get(1);
            B21 = BB.get(2);
            B22 = BB.get(3);
            C11 = CC.get(0);
            C12 = CC.get(1);
            C21 = CC.get(2);
            C22 = CC.get(3);
            add(recursiveMatrixMultiplication(A11, B11), recursiveMatrixMultiplication(A12, B21), C11);
            add(recursiveMatrixMultiplication(A11, B12), recursiveMatrixMultiplication(A12, B22), C12);
            add(recursiveMatrixMultiplication(A21, B11), recursiveMatrixMultiplication(A22, B21), C21);
            add(recursiveMatrixMultiplication(A21, B12), recursiveMatrixMultiplication(A22, B22), C22);
            merge(C, 0, 0, C11);
            merge(C, 0, n/2, C12);
            merge(C, n/2, 0, C21);
            merge(C, n/2, n/2, C22);


        }
        return C;
    }
    
    public static void show (int matrix[][]) { 
    	int n = matrix.length;
    	 System.out.println("Result: ");  
        for (int i = 0; i < n; i++) {
        	
            for (int j = 0; j < n; j++) {  
                System.out.print(matrix[i][j] + " ");  
            }  
            
            System.out.println();  
        }  
    }  
    
    public static int[][] matMul(int[][] a, int[][] b) {
		int rowLength = a.length;
		int colLength = b[0].length;
		int[][] output = new int[rowLength][colLength];
		if(a[0].length != b.length) {
			System.out.println("The two matrices can't be multiplied");
		}
		else {
			for(int i = 0; i < a.length; i++) {
				for(int j = 0; j < b[0].length; j++) {
					for(int k = 0; k < b.length; k++) {
						output[i][j] += a[i][k] * b[k][j];
					}
				}
			}	
		}
		return output;
	}

    public static boolean equalMatrix(int[][]C1,int[][]C2) {
//    	int[][] C1 = new int[A.length][B[0].length];
//    	C1 = recursiveMatrixMultiplication(A,B);
//    	int[][] C2 = new int[A.length][B[0].length];
//    	C2 = matMul(A,B);
    			
    	if(C1.length != C2.length || C1[0].length != C2[0].length) {
    		return false;
    	}
    	else {
    		for(int i = 0; i < C1.length; i++) {
    			for(int j = 0; j < C2[0].length; j++) {
    				if(C1[i][j] != C2[i][j]) {
    					return false;
    				}
    				else {
    					return true;
    				}
    			}
    		}
    	}
    	return true;
    }

    public static void main(String args[]) {

//        int[][] a = {{1, 2 }, {3, 4}};
//        int[][] b = {{1, 2 }, {3, 4}};;
//        int[][] c=recursiveMatrixMultiplication(a,b);
//        int aaa=1;
//        show(c);
    	
    	int[][] A = {
    			{1, 2, 3, 4},
    			{5, 6, 7, 8},
    			{-8, -7, -6, -5},
    			{-4, -3, -2, -1},
    	};
    	
    	int[][] B = {
    			{10, 11, 14, 15},
    			{12, 13, 16, 17},
    			{-18,-17,-16,-15},
    			{-14,-13,-12,-11},
    	};
    	
    	
    	System.out.println("sum of partition : " + sum(partition(A)));
    	//System.out.println("sum of partition : " + sum(partition(B)));

    	int[][] C2 = matMul(A,B); 
    	show(C2);
    	
    	int[][] C1 = recursiveMatrixMultiplication(A,B);
    	System.out.println("Two Matrices are equal : " + equalMatrix(C1,C2));
    	
    	
    }
}
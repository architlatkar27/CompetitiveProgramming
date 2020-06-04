import java.util.*;
public class sorting {  
    static void bubbleSort(int[] array) {  
        int n = array.length;  
        for (int j = 1; j < n; j++) {  
            int key = array[j];  
            int i = j-1;  
            while ( (i > -1) && ( array [i] > key ) ) {  
                array [i+1] = array [i];  
                i--;  
            }  
            array[i+1] = key;  
        }
  
    }  
    public static void main(String[] args) {
        for(int n=10;n<=1000;n+=20){
            //
            int arr[] =new int[n]; 
                
            // System.out.println("Array Before Bubble Sort");  
            // for(int i=0; i < arr.length; i++){  
            //         System.out.print(arr[i] + " ");  
            // }  
            // System.out.println();  
            for(int i=0;i<n;i++){
                arr[i]=(int)(Math.random()*1000);
            }
            long t1=System.nanoTime();
            bubbleSort(arr);//sorting array elements using bubble sort  
            long t2=System.nanoTime();
            System.out.println(n+"   "+(t2-t1));    
        } 
    }  
}  
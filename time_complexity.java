import java.util.*;

class time_complexity{
    static int factorial(int n){
        if(n==1) return 1;
        return n*factorial(n-1);
    }
    public static void main(String args[]){
        System.out.println("hi");
        for(int i=1;i<=10;i++){
            System.out.println(i+" "+Math.log(i)+" "+i*Math.log(i)+" "+i*i+" "+i*i*i+" "+factorial(i));
        }
    }
    
}
import java.util.*;
class function{
    public static void main(String args[]){
        System.out.println("7n^2+n+5    8n^2    7n^2");
        int v1,v2,v3;
        for(int i=0;i<=10;i++){
            v1=7*i*i+i+5;
            v2=8*i*i;
            v3=7*i*i;
            System.out.println(v1+"   "+v2+ "  "+v3);
            
        }
    }
}
import java.util.*;
class GaleShapely{
    static int men[][]=new int[100][100];
    static int women[][]=new int[100][100];
    static int mMark[]=new int[100];
    static int wc[]=new int[100];
    static int mc[]=new int[100];

    public static void main(String args[]){
        int n;
        Scanner sc=new Scanner(System.in);
        System.out.println("#men / women?");
        n=sc.nextInt();
        
        System.out.println("enter women's preference");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                women[i][j]=sc.nextInt();
            }
        }
        System.out.println("enter men's preference");
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                men[i][j]=sc.nextInt();
            }
        }
        sc.close();
        stableMatch(n);
        for(int i=1;i<=n;i++){
            System.out.println("match of "+i+" is "+mc[i]);
        }
    }
    static int wPrefersWhom(int w,int m,int m1,int n){
        for(int i=1;i<=n;i++){
            if(women[w][i]==m) return 1;
            else if(women[w][i]==m1) return 0;
        }
        return 100;
    }
    static void stableMatch(int n){
        int i,freecount;
        freecount=n;
        for(i=1;i<=n;i++){
            wc[i]=-1;
            mMark[i]=0;
        }
        while(freecount>0){
            int m,w;
            for(m=1;m<=n;m++) if(mMark[m]==0) break;
            for(i=1;i<=n && mMark[m]==0;i++){
                w=men[m][i];
                if(wc[w]==-1){
                    mc[m]=w;
                    wc[w]=m;
                    mMark[m]=1;
                    freecount--;
                }
                else{
                    int m1=wc[w];
                    int res=wPrefersWhom(w, m, m1, n);
                    if(res==1){
                        wc[w]=m;
                        mc[m]=w;
                        mc[m1]=0;
                        mMark[m]=1;
                        mMark[m1]=0;
                    }
                }
            }
            
        }
    }
}
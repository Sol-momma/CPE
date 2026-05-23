import java.util.*;

public class CPE12455{
    static boolean result = false ;
    static int[] parr ;
    
    static  int obtain ; 
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0){
            result = false ;
            obtain = sc.nextInt();
            parr = new int[sc.nextInt()];
            for(int i=0;i<parr.length;i++)
                parr[i] = sc.nextInt();
            chk(0,0);

            if(result) System.out.println("YES");
            else System.out.println("NO");
        }
        sc.close();
    }

    public static void chk(int sum , int i){
        if(sum > obtain) return ; 
        else if(sum == obtain) result = true;
        for(;i<parr.length;i++)
            chk(sum + parr[i], i+1);
    } 
}
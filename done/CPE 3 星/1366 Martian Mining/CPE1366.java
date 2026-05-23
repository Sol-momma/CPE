import java.util.* ; 

public class CPE1366 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n , m ; 
        

        while((n = sc.nextInt()) != 0 && (m = sc.nextInt()) != 0){
            int[][] y = new int[n][m];
            int[][] b = new int[n][m];
            int[][] dp = new int[n][m];
            
            
            for(int i = 0; i < n ; i++)
                for(int j=0;j < m ;j++){
                    b[j][i] = sc.nextInt();
                }
            for(int i = 0; i < n ; i++)
                for(int j=0;j < m ;j++){
                    y[j][i] = sc.nextInt();
                }
            
            for(int i=0;i<n ; i++){
                for(int j=0;j < m ;j++){
                    int ysum = 0 , bsum = 0;
                    for(int c = i ;c < n ; c++){
                        for(int d = j ;d < m ;d++){
                            ysum += y[c][d];
                            bsum += b[c][d];
                        } 
                    }
                    y[i][j] = ysum ;
                    b[i][j] = bsum ; 
                    
                }
            }


            for(int i = n-1; i >=0;i--){
                for(int j=m-1;j>=0;j--){
                    int y1 = j+1 == m ? 0 : dp[i][j+1];
                    int y2 = y[i][j];
                    int y3 = j + 1 == m ? 0 :y[i][j+1];
                    int b1 = i+1 == n ? 0 : dp[i+1][j];
                    int b2 = b[i][j];
                    int b3 = i+1 == n ? 0 : b[i+1][j];
                  
                    dp[i][j] = Math.max(y1+y2-y3, b1+b2-b3);
                }
            }   
           
            System.out.println(dp[0][0]);
        }

        sc.close();
    }
}
import java.util.*;

public class CPE160 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
       

        int n = 0 ; 
        // 先把100內的質數儲存
        int[] prime = new int[]{
            2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,
            71,73,79,83,89,97
        };
        while ( (n = sc.nextInt()) != 0 ){
            Vector<Integer> result = new Vector<Integer>();
            for(int i = 0 ; i < prime.length ; i++){
                if(prime[i] > n)break;
                int temp = n ;
                int sum = 0;

                while (temp >= prime[i]){
                    sum += temp / prime[i] ; 
                   
                    temp /= prime[i];
                }
                result.add(sum);
            }
            
            // 輸出
            System.out.printf("%3d! = ", n);
            for(int i = 0 ; i < result.size(); i++){          
                if(i % 15 == 0 && i != 0  ){
                    System.out.println();
                    System.out.printf("      ");

                }
                System.out.printf("%3d" , result.get(i) );
            }
            System.out.println();
        }
        sc.close();
    }
}
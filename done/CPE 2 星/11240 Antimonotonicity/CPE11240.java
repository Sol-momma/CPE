import java.util.* ; 

public class CPE11240 {
    public static void main(String[] args) {
        int T ; 
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
        while (T-- > 0 ) {
            int n = sc.nextInt();
            int flag = 0 ;
            int step = 0 ;
            int num = 0 ; 
            Vector<Integer> vec = new Vector<Integer>();

            while( n-- > 0 ){
                num = sc.nextInt();
                if(vec.size() == 0) {
                    vec.add(num);
                    step ++ ;
                    continue;
                }

                if(flag == 0){
                    if(vec.get(step-1) > num){
                        vec.add(num);
                        step ++ ;
                        flag = 1;
                    }else 
                        vec.set(step-1, num );
                }else if (flag == 1 ){
                    if(vec.get(step-1) < num){
                        vec.add(num);
                        step ++ ; 
                        flag = 0 ;
                    }else 
                        vec.set(step-1, num);
                }      
            }
            System.out.println(step);
        }
        sc.close();
    }
}
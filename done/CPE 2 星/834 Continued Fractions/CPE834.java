import java.util.*;

public class CPE834 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            int numerator = sc.nextInt();
            int denominator = sc.nextInt();
            List<Integer> output = new ArrayList<Integer>();
            while(denominator > 0){
                int temp = numerator / denominator ;
                output.add(temp);

                numerator -= denominator*temp;
               
                temp = denominator ; 
                denominator = numerator ;
                numerator = temp ; 
                
            }

            System.out.print("[");
            System.out.print(output.get(0) + ";");
            for(int i=1;i < output.size();i++){
                System.out.print(output.get(i));
                if(i != output.size() -1){
                    System.out.print(",");
                }
            }
            System.out.println("]");
        }
        sc.close();
    }
}
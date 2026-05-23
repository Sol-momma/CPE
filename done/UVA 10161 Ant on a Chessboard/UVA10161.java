import java.util.* ;

public class UVA10161 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder output = new StringBuilder();
        while(sc.hasNextLine()){
            int N = sc.nextInt();
            if(N==0) break ; 
            int x = 1; 
            int y = 1;

            while(true){
                if(Math.pow(x,2)-(x-1) >= N && Math.pow(x-1,2) - (x-2) <= N) {
                    if(Math.abs(Math.pow(x,2) - (x-1) - N) >= x){
                        x -= 1;
                    }
                   y = x ;
                   break ;
                }
                x++;
            }


            int sub = (int)Math.pow(x,2) - (x-1) - N ;
            if(x % 2 == 0){
                if(sub < 0 )y += sub ; 
                else x -= sub ;
            }else {
                if(sub < 0 ) x += sub ;
                else y -= sub ; 
            }
            output.append(x + " " + y + "\n");
        }
        System.out.println(output);
        sc.close();
    }
}
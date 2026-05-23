import java.util.* ; 

public class CPE11576{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cases = sc.nextInt();
        StringBuilder output = new StringBuilder();
        
        while(cases-- > 0 ){
            int m = sc.nextInt();
            int n = sc.nextInt();
            sc.nextLine();
            List<Character> list = new ArrayList<Character>();
             char[] pastchar = new char[]{} ;
            for(int i = 0 ; i < n ; i++){
                char[] cha = sc.nextLine().toCharArray();
                int index = CPE(cha , pastchar);
                for(int j = index ; j < cha.length ; j++){
                    list.add(cha[j]);
                }
                pastchar = cha ; 
            }
           
            output.append(list.size() + "\n" );
        }       
        sc.close();
        System.out.println(output);

    }

    static int CPE(char[] cur_cha , char[] pre_cha){        
        if(pre_cha.length == 0) return 0 ;
        String cur_str = "";
        String past_str = "";
        int index = 0 ;
        
        for(int i = pre_cha.length - 1,j=0 ; i >= 0 ; i-- , j++ ){
            past_str = pre_cha[i]  + past_str ; 
            cur_str += cur_cha[j];
            if(past_str.equals(cur_str)){
                index = j+1 ;
            }
            
        }
        return index ; 
    }
}
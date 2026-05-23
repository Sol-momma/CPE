import java.util.* ; 

public class CPE10903 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextInt()){
            int n = sc.nextInt();
            if(n==0)break;
            Player[] player = new Player[n];
            for(int i =0 ; i < player.length ; i++)
                player[i] = new Player();
            int k = sc.nextInt();
            sc.nextLine();
            while(k-- > 0 ){
                String[] s = sc.nextLine().split( " ");
                Set<String> set = new HashSet<>();
                for(int i = 1 ; i < s.length ; i+=2){
                    int index = Integer.parseInt(s[i-1]) - 1 ;
                    
                    player[index].action = s[i];
                    set.add(s[i]);
                }
                
                if(set.size() == 1 || set.size() == 3)continue;
               for(int i=0;i<player.length;i++){
                   player[i].WinOrLose(player);
               }
            }
            for(int i=0;i<player.length;i++){
                System.out.printf("%.3f\n",player[i].getWinRate());
            }
        
        }
        sc.close();
    }

}

class Player { 
    int win;
    int lose ; 
    String action ; 
    
    Player(){
        win = 0 ;
        lose = 0 ; 
        action = "" ;
    }

    public float getWinRate(){
        return (float)win/(win+lose);
    }
    public void WinOrLose(Player[] players){
        boolean chk = false ;
        for(int i = 0 ; i < players.length ; i++){
            if(action.equals("paper") && players[i].action.equals("scissors") ||
              action.equals("rock") && players[i].action.equals("paper") ||
              action.equals("scissors") && players[i].action.equals("rock")){
                lose++;
                chk = true;
                break ;
            }
        }
        if(!chk)win ++ ;
    }

    
}
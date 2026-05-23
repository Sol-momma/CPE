import java.util.* ;

public class CPE11624 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0 ){
            int R = sc.nextInt();
            int C = sc.nextInt();
            Queue<POS> JOE = new LinkedList<POS>();
            Queue<POS> FIRE = new LinkedList<POS>();

            int[][] firearr = new int[R][C];
            int[][] joearr = new int[R][C];
            int a  = 0,  b = 0 ;
            while(R-- > 0){
                char[] cha = sc.next().toCharArray();
                b = 0 ;
                for(char c : cha){
                    if(c == 'J'){
                        POS pos = new POS() ;
                        pos.x = a ; 
                        pos.y = b ; 
                        pos.val = 0 ;
                        firearr[a][b] = -1;
                        JOE.add(pos);
                    }else if(c=='F'){
                        POS pos = new POS() ;
                        pos.x = a ;
                        pos.y = b ;
                        pos.val = 0;
                        joearr[a][b] = -3 ;
                        FIRE.add(pos);
                    }else if (c == '.'){
                        firearr[a][b] = -1;
                        joearr[a][b] = -1 ;
                    }else if(c == '#'){
                        firearr[a][b] = -2 ;
                        joearr[a][b] = -2 ;
                    }
                    b++;
                }
                
                a++;
            }
            FIRECALC(FIRE, firearr);     
            
            JOECALC(JOE, joearr,firearr);
            OUTPUT(joearr);
        }
        sc.close();
    }

    public static void FIRECALC(Queue<POS> FIRE,int[][] firearr){
        while(!FIRE.isEmpty()){
            POS pos = FIRE.poll();

            if(pos.x - 1 >= 0 && firearr[pos.x-1][pos.y] == -1){
                POS newpos = new POS();
                newpos.x = pos.x - 1 ;
                newpos.y = pos.y ;
                newpos.val = pos.val + 1 ;
                firearr[newpos.x][newpos.y] = newpos.val ; 
                FIRE.add(newpos);
            }

            if(pos.x + 1 < firearr.length  && firearr[pos.x+1][pos.y] == -1){
                POS newpos = new POS();
                newpos.x = pos.x + 1 ;
                newpos.y = pos.y ;
                newpos.val = pos.val + 1 ;
                firearr[newpos.x][newpos.y] = newpos.val ; 
                FIRE.add(newpos);
            }

            if(pos.y - 1 >= 0  && firearr[pos.x][pos.y-1] == -1){
                POS newpos = new POS();
                newpos.x = pos.x  ;
                newpos.y = pos.y - 1 ;
                newpos.val = pos.val + 1 ;
                firearr[newpos.x][newpos.y] = newpos.val ; 
                FIRE.add(newpos);
            }
  
            if(pos.y + 1 < firearr[pos.x].length  && firearr[pos.x][pos.y+1] == -1){
                POS newpos = new POS();
                newpos.x = pos.x  ;
                newpos.y = pos.y + 1 ;
                newpos.val = pos.val + 1 ;
                firearr[newpos.x][newpos.y] = newpos.val ; 
                FIRE.add(newpos);
            }
        }
    }

    public static void JOECALC(Queue<POS> JOE , int[][] joearr , int[][] firearr){
        while(!JOE.isEmpty()){
            POS pos = new POS();
            pos = JOE.poll();
            if(pos.x - 1 >= 0 && joearr[pos.x-1][pos.y] == -1){
                if(firearr[pos.x-1][pos.y] <= pos.val + 1 )
                    joearr[pos.x-1][pos.y] = -3;
                else {
                    POS newpos = new POS();
                    newpos.x = pos.x - 1 ;
                    newpos.y = pos.y ;
                    newpos.val = pos.val + 1 ;
                    joearr[newpos.x][newpos.y] = newpos.val ; 
                    JOE.add(newpos);
                }
            }
           
            if(pos.x + 1 < joearr.length && joearr[pos.x+1][pos.y] == -1){
               
                if(firearr[pos.x+1][pos.y] <= pos.val + 1 )
                    joearr[pos.x+1][pos.y] = -3;
                else {
                    POS newpos = new POS();
                    newpos.x = pos.x + 1 ;
                    newpos.y = pos.y ;
                    newpos.val = pos.val + 1 ;
                    joearr[newpos.x][newpos.y] = newpos.val ; 
                    JOE.add(newpos);
                }
            }

            if(pos.y + 1 < joearr[pos.x].length && joearr[pos.x][pos.y+1] == -1){
                if(firearr[pos.x][pos.y+1] <= pos.val + 1 )
                    joearr[pos.x][pos.y+1] = -3;
                else {
                    POS newpos = new POS();
                    newpos.x = pos.x  ;
                    newpos.y = pos.y + 1;
                    newpos.val = pos.val + 1 ;
                    joearr[newpos.x][newpos.y] = newpos.val ; 
                    JOE.add(newpos);
                }
            }

            if(pos.y - 1 >= 0 && joearr[pos.x][pos.y-1] == -1){
                if(firearr[pos.x][pos.y-1] <= pos.val + 1 )
                    joearr[pos.x][pos.y-1] = -3;
                else {
                    POS newpos = new POS();
                    newpos.x = pos.x  ;
                    newpos.y = pos.y - 1;
                    newpos.val = pos.val + 1 ;
                    joearr[newpos.x][newpos.y] = newpos.val ; 
                    JOE.add(newpos);
                }
            }
        }
    }

    public static void OUTPUT(int[][] joearr){
       List<Integer> out = new ArrayList<Integer>();

       for(int i = 0 ; i < joearr.length ; i++){
         if(joearr[i][0] >= 0)out.add(joearr[i][0]);
         if(joearr[i][joearr[i].length - 1 ] >= 0 ) out.add(joearr[i][joearr[i].length-1]);
       }

       for(int i=0;i< joearr[0].length ; i++){
         if(joearr[0][i] >= 0)out.add(joearr[0][i]);
         if(joearr[joearr.length-1][i] >= 0 ) out.add(joearr[joearr.length-1][i]);
       }
       if(out.size() == 0){
        System.out.println("IMPOSSIBLE");
       }else {
         int min = 999 ; 
         for(int a : out){
            min = Math.min(min,a);
         }
         System.out.println(min+1);
       }
    }
}

class POS {
    int x ;
    int y ;
    int val ;
}


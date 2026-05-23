import java.util.* ;

public class CPE512 {
    static int count = 0 ;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int index = 0 ;
        
        while(sc.hasNextInt()){
            count = 0 ;
            int r = sc.nextInt();
            int c = sc.nextInt();
            if(r==0 && c==0)break ;
            else if(index >0) System.out.println();
            index ++ ;
            Vector<Vector<Integer>> vec = new Vector<Vector<Integer>>();
            Vector<Vector<Integer>> vec2 = new Vector<Vector<Integer>>();
            
            for(int i=1;i <= r ; i++){
                Vector<Integer> vecr1 = new Vector<Integer>();
                Vector<Integer> vecr2 = new Vector<Integer>();
                for(int j = 1; j <= c ; j++){
                    vecr1.add(count);
                    vecr2.add(count);
                    count++;
                }
                vec.add(vecr1);
                vec2.add(vecr2);
            }
           
           
            int op = sc.nextInt();
            
            while(op-- > 0){
                String command = sc.next();
                switch(command){
                    case "DR" : 
                        DR(sc,vec);
                        break ;
                    case "DC":
                        DC(sc,vec);
                        break;
                    case "IC" :
                        IC(sc,vec);
                        break ;
                    case "IR" :
                        IR(sc,vec);
                        break;
                    case "EX":
                        EX(sc,vec);
                        break;
                }
                
            }
            
            int query = sc.nextInt();
            Vector<String> output = new Vector<String>();
            while(query -- > 0){
                int r1 = sc.nextInt();
                int c1 = sc.nextInt();
               
                    
                int val = vec2.get(r1-1).get(c1-1);

                int r2 = 0;
                int c2 = 0;
                
                Boolean chk = false ;
                for(int i = 0; i < vec.size();i++){
                    for(int j=0;j<vec.get(i).size();j++){
                        if(vec.get(i).get(j) == val ){
                            r2 = i+1;
                            c2 = j+1;
                            chk = true;
                            break ;
                        }
                    }
                    if(chk)break;
                }
                String result = "Cell data in (" + r1 + "," + c1 + ")" ; 
                if(chk)
                    result += " moved to (" + r2 + "," + c2 + ")";
                else 
                    result += " GONE";
                output.add(result);
            }
            System.out.println("Spreadsheet #" + (index));

            for(String str : output)
                System.out.println(str);
            
            
        }

        sc.close();
    }

  
    public static void DR(Scanner sc , Vector<Vector<Integer>> vec){
        int A = sc.nextInt();
        int[] delro = new int[A];
        for(int i=0;i<delro.length;i++)
            delro[i] = vec.get(sc.nextInt()-1).get(0);
        for(int i=0;i<delro.length;i++){
            for(int j=0;j<vec.size();j++){
                if(vec.get(j).get(0) == delro[i]){
                    vec.remove(j);
                    break;
                }
                
            }
        }  
    }

    public static void DC(Scanner sc , Vector<Vector<Integer>> vec){
        int A = sc.nextInt();
        int[] delcol = new int[A];
        for(int i=0;i < delcol.length ; i++)
            delcol[i] = vec.get(0).get(sc.nextInt() - 1 );
        for(int i=0;i<delcol.length;i++){
            for(int j = 0;j<vec.get(0).size();j++){
                if(vec.get(0).get(j) == delcol[i]){
                    for(int k=0;k<vec.size();k++){
                        vec.get(k).remove(vec.get(k).get(j));
                    }  
                    break;
                }
            }
        }
    }

    public static void IC(Scanner sc , Vector<Vector<Integer>> vec){
        int A = sc.nextInt();
        int[] targetcol = new int[A];

        for(int i =0;i< targetcol.length;i++){
            int num = sc.nextInt();
            targetcol[i] = vec.get(0).get(num-1);
        }
        for(int i=0;i<targetcol.length;i++){
            for(int j=0;j<vec.get(0).size();j++){
                if(vec.get(0).get(j) == targetcol[i]){
                    for(int k=0;k<vec.size();k++){
                        vec.get(k).add(j,count);
                        count++;
                    }
                    break;
                }
            }
        }
    }

    public static void IR(Scanner sc , Vector<Vector<Integer>> vec){
        int A = sc.nextInt();
        int[] targetrow = new int[A];
        
        

        for(int i=0;i<targetrow.length;i++){
            int num = sc.nextInt();
            targetrow[i] = vec.get(num-1).get(0);
        }
        
        for(int i =0;i < targetrow.length;i++){
            for(int j = 0 ; j < vec.size();j++){
                if(vec.get(j).get(0).equals(targetrow[i])){
                    Vector<Integer> vect = new Vector<Integer>();
                    for(int k=0;k<vec.get(0).size();k++){
                        vect.add(count);
                        count++;
                    }   
                    vec.add(j,vect);
                    break;
                }
            }
        }
    }

    public static void EX(Scanner sc , Vector<Vector<Integer>> vec){
        int r1 = sc.nextInt()-1;
        int c1 = sc.nextInt()-1;
        int r2 = sc.nextInt()-1;
        int c2 = sc.nextInt()-1;

        int str1 = vec.get(r1).get(c1);
        int str2 = vec.get(r2).get(c2);
        vec.get(r1).set(c1,str2);
        vec.get(r2).set(c2,str1);
    }

}
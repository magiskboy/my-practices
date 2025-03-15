import java.util.*;
import java.io.*;
import java.lang.Math;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            
            for (int k = 0; k < n; ++k) {
                int s = 0;
                for (int j = 0; j < k+1; ++j) s += (int)Math.pow(2, j);
                int v = a + b * s;
                System.out.printf("%d ", v);
            }
            System.out.println();
        }
        in.close();
    }
}

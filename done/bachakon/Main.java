import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n,b,ans = 0;
        int sum = 0;
        int a[] = new int[100000];
        n = scan.nextInt();

        for(int i=0;i<n;i++){
          a[i] = scan.nextInt();
          if(i == 0) sum = a[i];
          else sum += abs(a[i-1] - a[i]);
        }


        System.out.println(ans);
    }
    public static int abs(int a){
      if(a>0) return a;
      else return -1 * a;
    }
}


/**
 * This program counts the steps of three algos for different input sizes.
 * The three algos are:
 * <ol><li>Check minimun value and maximum value in one loop and return their difference.</li>
 * <li>Print fibonacci series</li>
 * <li>Matrix Multiplication of square matrices</li></ol>
 * 
 *
 * @author Pratyush Gupta
 * @version 28-08-2020
 */
public class NoOfSteps
{
    static int count =0;
    public static void main(String ars[]){
        System.out.println("Algorithm 1:");
        System.out.println("The values of no. of steps for different sizes of inputs are:");
        System.out.println("size(n)\tsteps");
        
        
        for(int n =5;n<=50;n+=5){
            int a[] = new int[n];
            int total = 0;
            for(int t = 0; t<10; t++){//t for 10 times
                for(int i =0;i<n;i++)
                    a[i]=(int)(Math.random()*Integer.MAX_VALUE);
                int returned = Secret(a,n);
                total+=count;
                count=0;
            }
            System.out.println(n+"\t"+total/10);
        }

        System.out.println("\n*******************************************");
        System.out.println("Algorithm 2:");
        System.out.println("Computing n-th fibonacci number and counting steps:");
        System.out.println("n-th Fibonacci\tn\tsteps");
        Fibonacci(1);//for n = 1
        System.out.println("\t\t1\t"+count);//for n = 1
        for(int n = 3;n<=36;n+=3){
            Fibonacci(n);
            System.out.println("\t\t"+n+"\t"+count);
            count=0;
        }
        
        System.out.println("\n*******************************************");
        System.out.println("Algorithm 3:");
        System.out.println("Matrix multiplication of different sizes 'n' and counting steps:");
        System.out.println("n\tsteps");
        for(int n=1;n<=10;n++){
            int a1[][]=new int[n][n];
            int a2[][]=new int[n][n];
            int m[][]=new int[n][n];
            int total = 0;
            for(int t = 0; t<10; t++){//t for 10 times
                for(int i =0;i<n;i++)
                    for(int j =0;j<n;j++){
                        a1[i][j]=(int)(Math.random()*Integer.MAX_VALUE);
                        a2[i][j]=(int)(Math.random()*Integer.MAX_VALUE);
                    }
                matrixMultiplication(m,a1,a2,n);
                total+=count;
                count=0;
            }
            System.out.println(n+"\t"+total/10);
        }
    }
    public static int Secret(int A[],int n){
        int minval = A[0]; count++;
        int maxval = A[0]; count++;
        for(int i =0; i<n ; i++){//for each condition evalutaion
            count++; //times the outer loop condition evaluates and returns true
            
            count++;//first condition evaluation
            if(A[i]<minval){
                minval=A[i]; count++;
            }
            count++;//second condition evaluation
            if(A[i]>maxval){
                maxval=A[i]; count++;
            }
        }
        count++; //for the last time outerloop condition evaluates and returns false
        count++; //execution of last return statement
        return maxval-minval;
    }
    public static void Fibonacci(int n){
        count++;//condition evaluation
        if(n<=1){
            System.out.print(n);
            count++;//printing value
        }
        else{
            int fnm1=0;count++;
            int fnm2=1;count++;
            int fn=0;
            for(int i=2;i<=n;i++){
                count++;//each time condition is evaluated
                fn=fnm1+fnm2;
                fnm2=fnm1;
                fnm1=fn;
                count+=3;//for above THREE program steps
            }
            count++;//last time when condition evaluates to false
            System.out.print(fn);count++;
        }
    }
    
    /**
     * Method matrixMultiplication
     * multiplies two square matrices and stores them in another array
     *
     * @param m resultant array, since refernce is passed in java, values will directly be reflected.
     * @param a1 first array
     * @param a2 second array
     * @param n input size
     */
    public static void matrixMultiplication(int m[][],int a1[][],int a2[][], int n){
        
        for(int i =0;i<n;i++){
            count++;//each time loop 'i' condition evaluated TRUE
            for(int j =0;j<n;j++){
                count++;//each time loop 'j' condition evaluated TRUE
                for(int k = 0;k<n;k++){
                    count++;//each time loop 'k' condition evaluated TRUE
                    m[i][j]+=a1[i][k]+a2[k][j]; count++;
                }
                count++;//one time when loop 'k' condition evaluates FALSE
            }
            count++;//one time when loop 'j' condition evaluates FALSE
        }
        count++;//one time when loop 'i' condition evaluates FALSE
    }
}

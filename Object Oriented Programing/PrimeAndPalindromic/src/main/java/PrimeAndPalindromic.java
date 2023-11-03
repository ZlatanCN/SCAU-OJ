import java.util.Scanner;

public class PrimeAndPalindromic {
    private static boolean isPrime(int num) {
        if (num < 2) {
            return false;
        }
        for (int i = 2; i < num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    private static boolean isPalindromic(int num) {
        if (num <= 0) {
            return false;
        } else if (num < 10) {
            return true;
        } else {
            StringBuilder sb = new StringBuilder("" + num);
            String original = sb.toString();
            StringBuilder reversedSB = sb.reverse();
            String reversed = reversedSB.toString();
            return reversed.equals(original);
        }
    }

    private static boolean isPrimeAndPalindromic(int num) {
        if (isPrime(num) && isPalindromic(num)) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.print("输入个数：");
        Scanner sc = new Scanner(System.in);
        int numToOutput = sc.nextInt();
        int count = 0;
        System.out.printf("前%d个同时为素数和回文数的正整数是：\n", numToOutput);
        for (int i = 1; count < numToOutput; i++) {
            if (isPrimeAndPalindromic(i)) {
                System.out.print(i + " ");
                count += 1;
            }
        }
    }
}

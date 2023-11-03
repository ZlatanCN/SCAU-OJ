import java.util.Random;
import java.util.Scanner;

public class GuessNumberGame {
    public static int rest_chance = 3;
    public static int game_times = 0;
    public static int win_times = 0;
    public static int lose_times = 0;

    public static boolean is_win = false;

    public static boolean continueToPlay() {
        System.out.print("你还要继续游戏吗？（Y继续/N退出）：");
        Scanner sc = new Scanner(System.in);
        String yes_or_no = sc.next();
        return yes_or_no.equals("Y");
    }

    public static int check_size(int guess, int random) {
        return guess - random;
    }

    public static void reset() {
        is_win = false;
        rest_chance = 3;
    }

    public static void playGame() {
        game_times += 1;
        System.out.printf("第%d次游戏， 程序生成了一个[0, 9]之间的数字。\n", game_times);
        Random r = new Random();
        int random_number = r.nextInt(10);
        if (rest_chance != 0) {
            while (!is_win && rest_chance != 0) {
                Scanner sc = new Scanner(System.in);
                System.out.printf("你还有%d次机会， 输入你猜的数字：", rest_chance);
                int guess_number = sc.nextInt();
                int check = check_size(guess_number, random_number);
                if (check == 0) {
                    System.out.println("恭喜你， 猜对了！");
                    rest_chance -= 1;
                    win_times += 1;
                    is_win = true;
                    break;
                } else if (check < 0) {
                    System.out.println("你猜的数字太小了！");
                    rest_chance -= 1;
                } else {
                    System.out.println("你猜的数字太大了！");
                    rest_chance -= 1;
                }
            }
        }
        if (rest_chance == 0 && !is_win) {
            lose_times += 1;
            System.out.printf("本次游戏失败！正确数字是%d\n", random_number);
            if (continueToPlay()) {
                reset();
                playGame();
            }
        } else if (is_win && continueToPlay()) {
            reset();
            playGame();
        }
    }

    public static void main(String[] args) {
        playGame();
        System.out.printf("你共进行了%d次游戏，成功%d次，失败%d次。", game_times, win_times, lose_times);
    }
}

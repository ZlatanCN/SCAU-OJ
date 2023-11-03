import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class PokerGame {
    private static String[][] deck;
    private static final int NUM_OF_CARDS = 52;
    private static final int NUM_OF_COLORS = 4;

    public PokerGame() {
        deck = new String[4][13];
        for (int i = 0; i < deck.length; i++) {
            for (int j = 0; j < deck[i].length; j++) {
                if (j <= 8) {
                    String temp = Integer.toString(j + 2);
                    deck[i][j] = temp;
                } else if (j == 9) {
                    deck[i][j] = "J";
                } else if (j == 10) {
                    deck[i][j] = "Q";
                } else if (j == 11) {
                    deck[i][j] = "K";
                } else if (j == 12) {
                    deck[i][j] = "A";
                }
            }
        }
    }

    private static boolean deckIsEmpty() {
        for (int i = 0; i < deck.length; i++) {
            for (int j = 0; j < deck[i].length; j++) {
                if (deck[i][j] != null) {
                    return false;
                }
            }
        }
        return true;
    }

    private static String[] sortCards(String[] cards, int num) {
        int[] intCards = new int[num];
        String[] returnCards = new String[num];
        for (int i = 0; i < num; i++) {
            if (cards[i].equals("J")) {
                intCards[i] = 11;
            } else if (cards[i].equals("Q")) {
                intCards[i] = 12;
            } else if (cards[i].equals("K")) {
                intCards[i] = 13;
            } else if (cards[i].equals("A")) {
                intCards[i] = 1;
            } else {
                intCards[i] = Integer.parseInt(cards[i]);
            }
        }
        Arrays.sort(intCards, 0, num);
        for (int i = 0; i < num; i++) {
            if (intCards[i] == 11) {
               returnCards[i] = "J";
            } else if (intCards[i] == 12) {
                returnCards[i] = "Q";
            } else if (intCards[i] == 13) {
                returnCards[i] = "K";
            } else if (intCards[i] == 1) {
                returnCards[i] = "A";
            } else {
                returnCards[i] = Integer.toString(intCards[i]);
            }
        }
        return returnCards;
    }

    private static void listCards(int[] allocatedCards, int whichPlayer) {
        Random rand = new Random();
        int cardsToBeAllocated = allocatedCards[whichPlayer];

        String[] blackPeach = new String[13];
        int blackPeachCount = 0;

        String[] redPeach = new String[13];
        int redPeachCount = 0;

        String[] plum = new String[13];
        int plumCount = 0;

        String[] square = new String[13];
        int squareCount = 0;

        for (int i = 0; i < cardsToBeAllocated; i++) {
            int color = rand.nextInt(NUM_OF_COLORS);
            int whichCard = rand.nextInt(13);
            while (deck[color][whichCard] == null && !deckIsEmpty()) {
                color = rand.nextInt(NUM_OF_COLORS);
                whichCard = rand.nextInt(13);
            }
            String theCard = deck[color][whichCard];
            deck[color][whichCard] = null;
            if (color == 0) {
                blackPeach[blackPeachCount] = theCard;
                blackPeachCount += 1;
            } else if (color == 1) {
                redPeach[redPeachCount] = theCard;
                redPeachCount += 1;
            } else if (color == 2) {
                plum[plumCount] = theCard;
                plumCount += 1;
            } else {
                square[squareCount] = theCard;
                squareCount += 1;
            }
        }

        String[] b = sortCards(blackPeach, blackPeachCount);
        String[] r = sortCards(redPeach, redPeachCount);
        String[] p = sortCards(plum, plumCount);
        String[] s = sortCards(square, squareCount);

        outputToScreen(b, r, p, s);
    }

    private static void outputToScreen(String[] b, String[] r, String[] p, String[] s) {
        System.out.print("  黑桃：");
        for (int i = b.length - 1; i >= 0; i--) {
            System.out.print(b[i] + " ");
        }
        System.out.println();

        System.out.print("  红心：");
        for (int i = r.length - 1; i >= 0; i--) {
            System.out.print(r[i] + " ");
        }
        System.out.println();

        System.out.print("  草花：");
        for (int i = p.length - 1; i >= 0; i--) {
            System.out.print(p[i] + " ");
        }
        System.out.println();

        System.out.print("  方块：");
        for (int i = s.length - 1; i >= 0; i--) {
            System.out.print(s[i] + " ");
        }
        System.out.println();
    }

    private static int[] allocateCards (int numOfPlayers){
        int[] cards = new int[numOfPlayers];
        if (NUM_OF_CARDS % numOfPlayers != 0) {
            if (numOfPlayers == 3) {
                cards[0] = 18;
                cards[1] = 17;
                cards[2] = 17;
            } else if (numOfPlayers == 5) {
                cards[0] = 11;
                cards[1] = 11;
                cards[2] = 10;
                cards[3] = 10;
                cards[4] = 10;
            } else if (numOfPlayers == 6) {
                cards[0] = 9;
                cards[1] = 9;
                cards[2] = 9;
                cards[3] = 9;
                cards[4] = 8;
                cards[5] = 8;
            }
        } else {
            Arrays.fill(cards, NUM_OF_CARDS / numOfPlayers);
        }
        return cards;
    }

    public static void playGame (int num){
        PokerGame game = new PokerGame();
        int[] allocatedCards = allocateCards(num);
        for (int i = 0; i < num; i++) {
            System.out.printf("第%d个人：\n", i + 1);
            listCards(allocatedCards, i);
        }
    }

    public static void main (String[]args){
        System.out.print("输入人数：");
        Scanner sc = new Scanner(System.in);
        int numOfPlayers = sc.nextInt();
        while (numOfPlayers < 2 || numOfPlayers > 6) {
            System.out.print("人数不符合要求，请重新输入[2，6]：");
            numOfPlayers = sc.nextInt();
        }
        playGame(numOfPlayers);
    }
}

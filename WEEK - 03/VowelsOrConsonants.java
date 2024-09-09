
import java.util.Scanner;


public class VowelsOrConsonants {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String str = input.next();
        char [] strArr = str.toCharArray();
        
        int vowelCount = 0;
        int consCount = 0;
        for(char i : strArr){
            Character.toLowerCase(i);
            if(i == 'a' ||i == 'e' ||i == 'i' ||i == 'o' ||i == 'u' ){
                vowelCount++;
            }else{
                consCount++;
            }
        }
        System.out.println("vowels: " + vowelCount+ " consonants: "+ consCount);
    }
}
